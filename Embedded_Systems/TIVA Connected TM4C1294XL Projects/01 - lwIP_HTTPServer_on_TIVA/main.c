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
#include "lwiplib.h"       // lwip
#include "pinout.h"        // pinout para configurar ethernet
#include "httpd.h"         // servidor http
#include "sntp.h"          // Para descobrir o tempo do sistema com sntp

extern void SocketTCPClient( void *pvParameters );

//*****************************************************************************
//
// Display an lwIP type IP Address.
//
//*****************************************************************************
void
DisplayIPAddress(uint32_t ui32Addr)
{
    static volatile char pcBuf[16];
    //
    // Converte o Endereço de IP para uma string.
    //
    sprintf(pcBuf, "%d.%d.%d.%d", (int)(ui32Addr & 0xff), (int)((ui32Addr >> 8) & 0xff),
            (int)((ui32Addr >> 16) & 0xff), (int)((ui32Addr >> 24) & 0xff));

    //
    // Display the string.
    //
    ////UARTPutString(UART0_BASE, pcBuf);
}

//*****************************************************************************
//
// Required by lwIP library to support any host-related timer functions.
//
//*****************************************************************************
volatile BaseType_t lwip_link_up = pdFALSE;
uint32_t g_ui32IPAddress;
void
lwIPHostTimerHandler(void)
{
    uint32_t ui32Idx, ui32NewIPAddress;

    //
    // Pega o endereço de IP atual.
    //
    ui32NewIPAddress = lwIPLocalIPAddrGet();

    //
    // Verifica se o endereço de IP mudou
    //
    if(ui32NewIPAddress != g_ui32IPAddress)
    {
        //
        // See if there is an IP address assigned.
        //
        if(ui32NewIPAddress == 0xffffffff)
        {
            //
            // Indica que não há link.
            //
            //UARTPutString(UART0_BASE, "Waiting for link.\n\r");
        }
        else if(ui32NewIPAddress == 0)
        {
            //
            // There is no IP address, so indicate that the DHCP process is
            // running.
            //
            //UARTPutString(UART0_BASE, "Waiting for IP address.\n\r");
        }
        else
        {
            //
            // Display the new IP address.
            //
            lwip_link_up = pdTRUE;
            //UARTPutString(UART0_BASE, "IP Address: ");
            DisplayIPAddress(ui32NewIPAddress);
            //UARTPutString(UART0_BASE, "\n\rOpen a browser and enter the IP address.\n\r");
        }

        //
        // Save the new IP address.
        //
        g_ui32IPAddress = ui32NewIPAddress;

        //
        // Turn GPIO off.
        //
       // MAP_GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, ~GPIO_PIN_1);
    }
    //
    // If there is not an IP address.
    //
    if((ui32NewIPAddress == 0) || (ui32NewIPAddress == 0xffffffff))
    {
        //
        // Loop through the LED animation.
        //

        for(ui32Idx = 1; ui32Idx < 17; ui32Idx++)
        {

            //
            // Toggle the GPIO
            //
#if 0
            MAP_GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1,
                    (MAP_GPIOPinRead(GPIO_PORTN_BASE, GPIO_PIN_1) ^
                     GPIO_PIN_1));

           // DelayTask(1000/ui32Idx);
#endif
        }
    }
}


#include "httpd.h"
#include "sntp.h"
extern void SocketTCPClient( void *pvParameters );


struct netif sNetIF;

void UpLwIP(void *param)
{
    uint32_t ui32User0, ui32User1;
    //uint32_t ui32Loop;
    uint8_t pui8MACArray[6];
    (void)param;
    //
    // Configure the device pins.
    //
    //inicializando os pinos de ethernet

    PinoutSet(true, false);

    vTaskDelay(1500);
    //UARTPutString(UART0_BASE, "Ethernet lwIP example\n\r");

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
        //UARTPutString(UART0_BASE, "No MAC programmed!\n\r");
        while(1)
        {
        }
    }

    // Tell the user what we are doing just now.
    //UARTPutString(UART0_BASE, "Waiting for IP.\n\r");

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
    while(lwip_link_up != pdTRUE){
        vTaskDelay(1000);
    }

    // Initialize a sample httpd server.
    httpd_init();

    // Inicia cliente SNTP
    //sntp_init();

    //sys_thread_new("LwIP Telnet Server", SocketTelnetServer, NULL, 2048, 5);


    // Loop forever.  All the work is done in the created tasks
    while(1)
    {
        // Delay ou pode inclusive apagar a tarefa
        vTaskDelay(10000);
    }

}


uint32_t g_ui32SysClock;

void task1(void* param){

    // Enable the GPIO port that is used for the on-board LED.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);

    // Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION))
    {
        // Caso o clock nÃ£o esteja ativo, vou desistir do processador
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
        // Caso o clock nÃ£o esteja ativo, vou desistir do processador
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

    // Instalando uma tarefa - Pressione Ctrl+Space enquanto digita uma funÃ§Ã£o pra ativar o Intellisense
    xTaskCreate(task1, "Tarefa 1", 256, NULL, 10, NULL);
    xTaskCreate(task2, "Tarefa 2", 256, NULL, 10, NULL);

    // Instalando tarefa lwIP
    xTaskCreate(UpLwIP, "LwIP Task", 1024, NULL, 4, NULL);

    // Start the scheduller
    vTaskStartScheduler();
    return 0;
}
