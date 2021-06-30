#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"              // FILA para desenvolver o driver de UART
#include "semphr.h"             // SEM�FAROS & MUTEX para desenvolver o driver de UART
#include "inc/hw_ints.h"        // Hardware interrupts
#include "inc/hw_uart.h"        // Hardware UART
#include "driverlib/uart.h"     // UART.h
#include "driverlib/pin_map.h"  // PIN_MAP.h para configurar os pinos

#define UART_CARACTERE      1
#define UART_QUEUE          2
#define UART_STRING         UART_QUEUE

/*
 *  - Os Dados s�o adicionados em uma fila, quem controla a transmiss�o � a pr�pria fila.
 *  - A tarefa s� volta a executar quando terminar a frase inteira.
 *  - Menos troca de contexto.
 *  - Evita ficar voltando na fun��o toda vez
 */

//*****************************************************************************
//
// System clock rate in Hz.
//
//*****************************************************************************
uint32_t g_ui32SysClock;

void task1(void* param){

    // Enable the GPIO port that is used for the on-board LED.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);

    // Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION))
    {
        // Caso o clock não esteja ativo, vou desistir do processador
        vTaskDelay(100);
    }

    // Enable the GPIO pin for the LED (PN0).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);

    while(1){
        // Turn on the LED.
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
        vTaskDelay(200);   // 200ticks = 200ms ---> Ou seja, ticktime = 1ms

        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
        vTaskDelay(200);   // 200ticks = 200ms
    }
}

void task2(void* param){

    // Enable the GPIO port that is used for the on-board LED.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);

    // Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION))
    {
        // Caso o clock não esteja ativo, vou desistir do processador
        vTaskDelay(100);
    }

    // Enable the GPIO pin for the LED (PN1).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_1);

    while(1){
        // Turn on the LED.
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
        vTaskDelay(1000);   // 1000ticks = 1s

        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
        vTaskDelay(1000);   // 1000ticks = 1s
    }
}

void Terminal(void *param);
void print_task(void *arg);

TaskHandle_t task1_handle;
TaskHandle_t task2_handle;

int main(void)
{

    MAP_SysCtlMOSCConfigSet(SYSCTL_MOSC_HIGHFREQ);
    //
    // Run from the PLL at 120 MHz.
    // Note: SYSCTL_CFG_VCO_240 is a new setting provided in TivaWare 2.2.x and
    // later to better reflect the actual VCO speed due to SYSCTL#22.
    //
    g_ui32SysClock = MAP_SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                             SYSCTL_OSC_MAIN |
                                             SYSCTL_USE_PLL |
                                             SYSCTL_CFG_VCO_240), 120000000);


    //eNABLE STACKING FOR INTERRUPT HANDLER. tHIS ALLOWS FLOATING-POINTS
    // instructions to be used within interrupt handlers, but at the expense of
    // extra stack usage
    MAP_FPUEnable();
    MAP_FPULazyStackingEnable();

    // Instalando uma tarefa - Pressione Ctrl+Space enquanto digita uma função pra ativar o Intellisense
    xTaskCreate(task1, "Tarefa 1", 256, NULL, 10, NULL);
    xTaskCreate(task2, "Tarefa 2", 256, NULL, 10, NULL);

    /*
     * Para testar:
     * Conectando na porta serial ACM0 utilizando GtkTerm
     * Configuramos para 115200 8-N-1 e assim temos acesso a porta serial
     * e a utilizar os recursos do Terminal e ver a print_task concorrendo ao Terminal.
     */
    xTaskCreate(Terminal, "Terminal Serial", 256, NULL, 6, &task1_handle);
    xTaskCreate(print_task, "Print task", 256, NULL, 7, &task2_handle);

    // Start the scheduller
    vTaskStartScheduler();
	return 0;
}

// Declarando uma estrutura de FILA para o UART
QueueHandle_t qUART0;
#if UART_STRING == UART_QUEUE
    QueueHandle_t qUART0Tx;
#endif

// Declarando uma estrutura de SEM�FARO para o UART
SemaphoreHandle_t sUART0;

// Declarando uma estrutura de MUTEX para o UART
SemaphoreHandle_t mutexTx0;

portBASE_TYPE UARTGetChar(char *data, TickType_t timeout);
void UARTPutChar(uint32_t ui32Base, char ucData);
void UARTPutString(uint32_t ui32Base, char *string);

// This function will compete for UART resource
void print_task(void *arg){
    vTaskDelay(200);    // Tempo para esperar a inicializar da UART
    while(1){
        UARTPutString(UART0_BASE, "Teste!\n\r");
        vTaskDelay(1000);
    }
}

// Tarefa que instala o driver da UART
void Terminal(void *param){
    char data;
    (void)param;

    // Criação de um semaphore binário
    // Vai alocar dinamicamente na memória do sistema que é o HEAP, a estrutura de dados semaphoro e vai devolver
    // um ponteiro de semaphore
    sUART0 = xSemaphoreCreateBinary();

    // Como é um ponteiro, posso testar se ele é nulo
    if (sUART0 == NULL){
        // There was insufficient FreeRTOS heap available for the semaphore to be created successfully
        vTaskSuspend(NULL);
    }
    else{
        mutexTx0 =  xSemaphoreCreateMutex();
        if (mutexTx0 == NULL){
            // There was insufficient FreeRTOS heap available for the semaphore to be created successfully
            vSemaphoreDelete(sUART0);   // Se não tive memória suficinete para criar este semaphore, exclua o anterior
            vTaskSuspend(NULL);
        }
        else{
            qUART0 =xQueueCreate(128, sizeof(char));    // Fila de 128 caracteres do tipo char
            if(qUART0 == NULL){
                // There was insufficient FreeRTOS heap available for the semaphore to be created successfully
                vSemaphoreDelete(sUART0);
                vSemaphoreDelete(mutexTx0);
                vTaskSuspend(NULL);
            }
            else{       // Deu tudo certo, agora vou inicializar o periférico
                #if UART_STRING == UART_QUEUE
                    qUART0Tx =  xQueueCreate(128, sizeof(char));
                #endif

                    // Enable the peripherals used by this example.
                    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);    // CLock da UART inicializado
                    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);    // CLock dos pinos conectados a UART

                    // Set GPIO A0 and A1 as UART pins
                    // Para usar o driver da UART, precisa definir este symbol TARGET_IS_TM4C129_RA1
                    // Operações para o processador ARM
                    MAP_GPIOPinConfigure(GPIO_PA0_U0RX);
                    MAP_GPIOPinConfigure(GPIO_PA1_U0TX);
                    // Operações para o periférico da Texas
                    MAP_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

                    // Configure the UART for 115.200, 8-N-1 operation
                    MAP_UARTConfigSetExpClk(UART0_BASE, configCPU_CLOCK_HZ, 115200,
                                            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE)
                                            );

                    // Desabilitando a FIFO - Pq a FIFO tem uma forma diferente de usar e atrapalha
                    // um pouco o entendimento de como configura uma UART
                    MAP_UARTFIFODisable(UART0_BASE);

                    // Enable the UART interrupt
                    // 1º - Defino a prioridade de nível 5 das interrupções
                    // 2º - Para o processador ARM, quero habilitar a interrupção
                    // 3º - Para o periférico, quero habilitar a interrupção de recepção
                    MAP_IntPrioritySet(INT_UART0, 0xC0);
                    MAP_IntEnable(INT_UART0);
                    MAP_UARTIntEnable(UART0_BASE, UART_INT_RX);

            }
        }
    }

    // Limpando a tela
    UARTPutString(UART0_BASE, "\033[2J\033[H");

    // Avisando que o sistema iniciou
    UARTPutString(UART0_BASE, "FreeRTOS started!\n\r");

    // Laço infinito que aguarda eu digitar algum caractere
    while(1){
        (void)UARTGetChar(&data, portMAX_DELAY);    // portMAX_delay = Deixa a função em espera indefinidamente, neste caso é até ser digitado algo
        if(data != 13){                             // Se for diferente de ENTER
            UARTPutChar(UART0_BASE, data);          // devolve o caractere para o terminal
        }
        else{                                       // Quebra de linha
            UARTPutChar(UART0_BASE, '\n');
            UARTPutChar(UART0_BASE, '\r');
        }
    }
}

#if UART_STRING == UART_QUEUE
    volatile uint32_t isstring = 0;   // Sempre que a FILA transmitir, recebe 1 em UARTPutString
#endif

void UARTIntHandler(void){
    uint32_t ui32Status;        // Necess�rio para o driver da UART da Texas
    // Variaveis que testam se vai haver preempção ou não, se eu acordei uma tarefa mais prioritária
    signed portBASE_TYPE pxHigherPriorityTaskWokenRX = pdFALSE;
    signed portBASE_TYPE pxHigherPriorityTaskWokenTX = pdFALSE;
    char data;

    #if UART_STRING == UART_QUEUE
        BaseType_t ret;
    #endif

        // Recebe o Status de Interrup��o
        ui32Status = MAP_UARTIntStatus(UART0_BASE, true);       // É RX ou TX???

        UARTIntClear(UART0_BASE, ui32Status);                   // Depois de saber o que, eu limpo as flags

        // Se for a interrupção de RX
        if((ui32Status&UART_INT_RX) == UART_INT_RX){
            // Loop while there are characteres in the receive FIFO
            while(MAP_UARTCharsAvail(UART0_BASE)){
                // Read the next character from the UART and write it back to the UART
                data = (char)MAP_UARTCharGetNonBlocking(UART0_BASE);
                xQueueSendToBackFromISR(qUART0, &data, &pxHigherPriorityTaskWokenRX);
            }
        }

        if((ui32Status&UART_INT_TX) == UART_INT_TX){
            #if UART_STRING == UART_QUEUE

            if(isstring){
                // read the char to be sent
                // Se for string, recebo o caractere da fila Tx
                ret = xQueueReceiveFromISR(qUART0Tx, &data, NULL);

                if(ret){
                    // Send the char
                    HWREG(UART0_BASE + UART_O_DR) = data;
                }
                else{
                    // There is no more char to be send in this string
                    isstring = 0;
                    MAP_UARTIntDisable(UART0_BASE, UART_INT_TX);

                    // Wake up the task that is sending the string
                    xSemaphoreGiveFromISR(sUART0, &pxHigherPriorityTaskWokenTX);
                }
            }
            else{
                MAP_UARTIntDisable(UART0_BASE, UART_INT_TX);

                // Call the task that is sending the char
                xSemaphoreGiveFromISR(sUART0, &pxHigherPriorityTaskWokenTX);
            }
            #else
            MAP_UARTIntDisable(UART0_BASE, UART_INT_TX);

            // Call the keyboard analysis task
            xSemaphoreGiveFromISR(sUART0, &pxHigherPriorityTaskWokenTX);
            #endif
        }
        // Se houver uma task com prioridade maior em TX ou RX, significa que precisa ter uma troca de contexto
        // Portanto, eu chamo o YIELD.
        if((pxHigherPriorityTaskWokenRX == pdTRUE) || (pxHigherPriorityTaskWokenTX == pdTRUE)){
            portYIELD();
        }
}


// Lê uma fila do sistema
// N�o tem mutex para receber os dados, por opção de projeto. Já que não tem nada concorrendo com a leitura
portBASE_TYPE UARTGetChar(char *data, TickType_t timeout){
    // Este retorno me diz se eu sai por timeout ou porque chegou dados
    return xQueueReceive(qUART0, data, timeout);
}

void UARTPutChar(uint32_t ui32Base, char ucData){
    /*
     * 2 Diferenças entre semaphore e mutex
     *      1º - Semaphore não tem o controle de herança de prioridade, e o mutex tem
     *      2º - Semaphore binario do mutex sai aberto de inicio, e o que não for mutex sai fechado
     */

    if(mutexTx0 != NULL){
        if(xSemaphoreTake(mutexTx0, portMAX_DELAY) == pdTRUE){
            // Send the char
            // Copia o dado ucData que eu quero transmitir, para o registrador de dados da UART0
            HWREG(ui32Base + UART_O_DR) = ucData;

            // Wait until space is available.
            // Esta interrupt vai me avisar quando o buffer tiver vazio (Por isso chamei ela depois de copiar,
            //  pois senão ela já iria disparar)
            MAP_UARTIntEnable(UART0_BASE, UART_INT_TX);

            // Wait indefinitely for a UART interrupt
            // Poderia tambem usar um timeout de 2ms, e se demorasse mais que este timeout aconteceu um erro
            xSemaphoreTake(sUART0, portMAX_DELAY);  // Sai daqui significa que a transmissão terminou

            xSemaphoreGive(mutexTx0);               // Portanto, eu posso liberar o recurso
        }
    }
}


#if UART_STRING == UART_CARACTERE
void UARTPutString(uint32_t ui32Base, char *string){
    if(mutexTx0 != NULL){
        if(xSemaphoreTake(mutexTx0, portMAX_DELAY) == pdTRUE){
            while(*string){
                // Send the char
                // Copia o dado ucData que eu quero transmitir, para o registrador de dados da UART0
                HWREG(ui32Base + UART_O_DR) = *string;

                // Wait until space is available.
                // Esta interrupt vai me avisar quando o buffer tiver vazio (Por isso chamei ela depois de copiar,
                //  pois senão ela já iria disparar)
                MAP_UARTIntEnable(UART0_BASE, UART_INT_TX);

                // Wait indefinitely for a UART interrupt
                // Poderia tambem usar um timeout de 2ms, e se demorasse mais que este timeout aconteceu um erro
                xSemaphoreTake(sUART0, portMAX_DELAY);  // Sai daqui significa que a transmissão terminou

                string++;       // Avança para o proximo caractere da string

            }

            // Terminado a string, libero o recurso
            xSemaphoreGive(mutexTx0);
        }
    }
}
#else

void UARTPutString(uint32_t ui32Base, char *string){
    char data;
    if(mutexTx0 != NULL){
        if(xSemaphoreTake(mutexTx0, portMAX_DELAY) == pdTRUE){
            isstring = 1;
            // Percorre a string e armazena tudo em uma fila
            while(*string){
                // Joga para o final da fila
                xQueueSendToBack(qUART0Tx, string, portMAX_DELAY); //Se a fila tiver cheia, eu fico esperando ter espa�o na fila
                string++;
            }

            // Envia o 'char'
            xQueueReceive(qUART0Tx, &data, portMAX_DELAY);
            HWREG(ui32Base + UART_O_DR) = data;

            MAP_UARTIntEnable(UART0_BASE, UART_INT_TX);

            // Espera indefinidamente a finaliza��o da transmiss�o da string pelo porte UART
            xSemaphoreTake(sUART0, portMAX_DELAY);
            xSemaphoreGive(mutexTx0);
        }
    }
}
#endif

