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
#include "FreeRTOS_CLI.h"
#include "task.h"
#include "queue.h"              // FILA para desenvolver o driver de UART
#include "semphr.h"             // SEMAFAROS & MUTEX para desenvolver o driver de UART
#include "inc/hw_ints.h"        // Hardware interrupts
#include "inc/hw_uart.h"        // Hardware UART
#include "driverlib/uart.h"     // UART.h
#include "driverlib/pin_map.h"  // PIN_MAP.h para configurar os pinos
#include "lwiplib.h"            // lwIP
#include "pinout.h"             // Pinout para config ethernet
#include "telnet_server.h"

volatile BaseType_t lwip_link_up = pdFALSE;     // Required by lwIP library to support any host-related timer functions.
uint32_t g_ui32IPAddress;                       // Required by lwIP library to support any host-related timer functions.
uint32_t g_ui32SysClock;                        // System clock rate in Hz.

TaskHandle_t task1_handle;
TaskHandle_t task2_handle;
TaskHandle_t lwIP_handler;

struct netif sNetIF;
void task1(void* param);
void task2(void* param);
void UpLwIP(void *param);
void lwIPHostTimerHandler(void);
void DisplayIPAddress(uint32_t ui32Addr);
extern void SocketTCPClient( void *pvParameters );

//[TODAS AS FUNÇÕES]

void configurePIN0(void)
{
    // Enable the GPIO port that is used for the on-board LED.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    // Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION))
    {
        vTaskDelay(100);
    }
    // Enable the GPIO pin for the LED (PN0).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);
}
void setPIN0(BaseType_t param)
{
    if(param == 0)
    {
        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
    }
    else
    {
        // Turn on the LED.
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
    }
}

void task1(void* param)
{
    // Enable the GPIO port that is used for the on-board LED.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    // Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION))
    {
        vTaskDelay(100);
    }
    // Enable the GPIO pin for the LED (PN0).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);

    while(1)
    {
        // Turn on the LED.
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
        vTaskDelay(200);   // 200ticks = 200ms ---> Ou seja, ticktime = 1ms

        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
        vTaskDelay(200);   // 200ticks = 200ms
    }
}

void task2(void* param)
{
    // Enable the GPIO port that is used for the on-board LED.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    // Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION))
    {
        // Caso o clock nÃ£o esteja ativo, vou desistir do processador
        vTaskDelay(100);
    }
    // Enable the GPIO pin for the LED (PN1).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_1);

    while(1)
    {
        // Turn on the LED.
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
        vTaskDelay(1000);   // 1000ticks = 1s

        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
        vTaskDelay(1000);   // 1000ticks = 1s
    }
}

//[FreeRTOS + CLI (Command Line Interface)]

/*  METODOLOGIA:
 *  1 - Criar uma função que implemente o compartamento do comando
 *  2 - Mapear o comando para a funçõa para implementar seu comportamento
 *  3 - Registrar este comando com o FreeRTOS + CLI
 *  4 - Executar o interpretador de comandos
 */

//Liga e desliga LED 0 de acordo com o comando
static BaseType_t command_LED_ON_OFF(char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString){
    char *pcParameter1;
    BaseType_t xParameterStringLength;

    pcParameter1 = FreeRTOS_CLIGetParameter(pcCommandString, 1, &xParameterStringLength);

    if(!strcmp(pcParameter1, "ON") || !strcmp(pcParameter1, "on"))
    {
        strcpy(pcWriteBuffer, "LED 0 turned ON\r\n");
        setPIN0(1);
    }
    else if(!strcmp(pcParameter1, "OFF") || !strcmp(pcParameter1, "off"))
    {
        strcpy(pcWriteBuffer, "LED 0 turned OFF\r\n");
        setPIN0(0);
    }
    else
    {
        strcpy(pcWriteBuffer, "Invalid Parameter - type ON ou OFF\r\n");
    }
    return pdFALSE;
}
//Exibe os status das tarefas [ESTÁ COM PROBLEMA...]
static BaseType_t prvTaskStatsCommand(char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString)
{
    static BaseType_t state = 0;
    if(!state)
    {
        char *head = "Name          State   Priority    Stack   Number\n\r";
        (void) xWriteBufferLen;

        strcpy(pcWriteBuffer, head);
        vTaskList( &pcWriteBuffer[strlen(head)]);

        state = 1;
        return pdTRUE;
    }
    else
    {
        state = 0;
        strcpy(pcWriteBuffer,"\n\r");
        return pdFALSE;
    }
}
//Limpa a tela
static BaseType_t prvClearCommand(char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString)
{
    strcpy(pcWriteBuffer, "\033[2J\033[H"); //SEQUÊNCIA/COMANDO QUE LIMPA A TELA
    return pdFALSE;
}

//MAPEANDO COMANDOS PARA SUAS FUNÇÕES
static const CLI_Command_Definition_t xLEDCommand =
{
     "led", // Command name
     "\r\nled:\r\nTurn the led ON or OFF (Parameter: ON or OFF)\r\n\r\n", // Hint --help
     command_LED_ON_OFF,    // Called function
     1                      // This command has 1 parameter
};
static const CLI_Command_Definition_t xTaskCommand =
{
     "tasks", // Command name
     "\r\ntasks:\r\nLists all the installed tasks\r\n\r\n", // Hint --help
     prvTaskStatsCommand,    // Called function
     0                      // This command has 1 parameter
};
static const CLI_Command_Definition_t xClearCommand =
{
     "clear", // Command name
     "\r\nclear:\r\nClean the console\r\n\r\n", // Hint --help
     prvClearCommand,    // Called function
     0
};


//[lwIP]

//*****************************************************************************
//
// Display an lwIP type IP Address.
//
//*****************************************************************************
void DisplayIPAddress(uint32_t ui32Addr)
{
    char pcBuf[16];
    //
    // Convert the IP Address into a string.
    //
    sprintf(pcBuf, "%d.%d.%d.%d", (int)(ui32Addr & 0xff), (int)((ui32Addr >> 8) & 0xff),
            (int)((ui32Addr >> 16) & 0xff), (int)((ui32Addr >> 24) & 0xff));
}

void lwIPHostTimerHandler(void)
{
    uint32_t ui32Idx, ui32NewIPAddress;
    // Get the current IP address.
    ui32NewIPAddress = lwIPLocalIPAddrGet();
    // See if the IP address has changed.
    if(ui32NewIPAddress != g_ui32IPAddress)
    {
        // See if there is an IP address assigned.
        if(ui32NewIPAddress == 0xffffffff)
        {
            // Indicate that there is no link.
            //UARTPutString(UART0_BASE, "Waiting for link.\n\r");
        }
        else if(ui32NewIPAddress == 0)
        {
            // There is no IP address, so indicate that the DHCP process is
            // running.
            //UARTPutString(UART0_BASE, "Waiting for IP address.\n\r");
        }
        else
        {
            // Display the new IP address.
            lwip_link_up = pdTRUE;
            //UARTPutString(UART0_BASE, "\r\nIP Address: ");
            DisplayIPAddress(ui32NewIPAddress);
        }

        // Save the new IP address.
        g_ui32IPAddress = ui32NewIPAddress;
        // Turn GPIO off.
       // MAP_GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, ~GPIO_PIN_1);
    }
    // If there is not an IP address.
    if((ui32NewIPAddress == 0) || (ui32NewIPAddress == 0xffffffff))
    {
        // Loop through the LED animation.
        for(ui32Idx = 1; ui32Idx < 17; ui32Idx++)
        {
            // Toggle the GPIO
            #if 0
                        MAP_GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1,
                                (MAP_GPIOPinRead(GPIO_PORTN_BASE, GPIO_PIN_1) ^
                                 GPIO_PIN_1));

                       // DelayTask(1000/ui32Idx);
            #endif
        }
    }
}

void UpLwIP(void *param)
{
    uint32_t ui32User0, ui32User1;
    //uint32_t ui32Loop;
    uint8_t pui8MACArray[6];
    (void)param;

    // Configure the device pins.
    PinoutSet(true, false);

    vTaskDelay(1500);

    // Configure the hardware MAC address for Ethernet Controller filtering of
    // incoming packets.  The MAC address will be stored in the non-volatile
    // USER0 and USER1 registers.
    ui32User0 = 0x001AB6;
    ui32User1 = 0x0318CC;

    MAP_FlashUserSet(ui32User0, ui32User1);
    MAP_FlashUserGet(&ui32User0, &ui32User1);
    if((ui32User0 == 0xffffffff) || (ui32User1 == 0xffffffff)){
        // We should never get here.  This is an error if the MAC address has
        // not been programmed into the device.  Exit the program.
        // Let the user know there is no MAC address
        while(1)
        {
        }
    }
    // Convert the 24/24 split MAC address from NV ram into a 32/16 split MAC
    // address needed to program the hardware registers, then program the MAC
    // address into the Ethernet Controller registers.
    pui8MACArray[0] = ((uint8_t)(ui32User0 >>  0) & 0xff);
    pui8MACArray[1] = ((uint8_t)(ui32User0 >>  8) & 0xff);
    pui8MACArray[2] = ((uint8_t)(ui32User0 >> 16) & 0xff);
    pui8MACArray[3] = ((uint8_t)(ui32User1 >>  0) & 0xff);
    pui8MACArray[4] = ((uint8_t)(ui32User1 >>  8) & 0xff);
    pui8MACArray[5] = ((uint8_t)(ui32User1 >> 16) & 0xff);

    // Initialize the lwIP library, using DHCP.
    lwIPInit(configCPU_CLOCK_HZ, pui8MACArray, 0, 0, 0, IPADDR_USE_DHCP, &sNetIF);

    // Set the interrupt priorities.  We set the SysTick interrupt to a higher
    // priority than the Ethernet interrupt to ensure that the file system
    // tick is processed if SysTick occurs while the Ethernet handler is being
    // processed.  This is very likely since all the TCP/IP and HTTP work is
    // done in the context of the Ethernet interrupt.
    while(lwip_link_up != pdTRUE)
    {
        vTaskDelay(1000);
    }

    // Initialize a sample httpd server. (lwip/apps/httpserver_raw)
    //httpd_init();

    // Initialize SNTP client
    //sntp_init();

    // Initialize a socket Telnet server
    //SocketTelnetServer("useless parameter");
    sys_thread_new("LwIP Telnet Server", SocketTelnetServer, NULL, 2048, 5);

    // Loop forever.  All the work is done in the created tasks
    while(1)
    {
        vTaskDelay(10000);
    }
}

//[MAIN]

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

    // Configure GPIO to PIN0
    configurePIN0();

    //[REGISTRANDO COMANDOS]
     FreeRTOS_CLIRegisterCommand(&xLEDCommand);
     FreeRTOS_CLIRegisterCommand(&xTaskCommand);
     FreeRTOS_CLIRegisterCommand(&xClearCommand);

    // Installing lwIP task
    xTaskCreate(UpLwIP, "LwIP Task", 1024, NULL, 10, &lwIP_handler);

    // Start the scheduller
    vTaskStartScheduler();
    return 0;
}
