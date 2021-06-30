

/**
 * main.c
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"

#include "freeRTOS.h"
#include "task.h"

void task1(void *param)
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
            vTaskDelay(500);

            // Turn off the LED.
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0);
            vTaskDelay(500);
       }
}

void task2(void *param){
    // Enable the GPIO port that is used for the on-board LED.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);

    // Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION))
    {
        vTaskDelay(100);
    }

    // Enable the GPIO pin for the LED (PN0).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_1);

  while(1){

      // Turn on the LED.
      GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
      vTaskDelay(1000);

      // Turn off the LED.
      GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
      vTaskDelay(1000);
  }
}


uint32_t g_ui32SysClock;

int main(void)
{
    //
        // Run from the PLL at 120 MHz.
        // Note: SYSCTL_CFG_VCO_240 is a new setting provided in TivaWare 2.2.x and
        // later to better reflect the actual VCO speed due to SYSCTL#22.
        //
        g_ui32SysClock = MAP_SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                                 SYSCTL_OSC_MAIN |
                                                 SYSCTL_USE_PLL |
                                                 SYSCTL_CFG_VCO_240), 120000000);

        xTaskCreate(task1, "Tarefa 1", 256, NULL, 10, NULL);
        xTaskCreate(task2, "Tarefa 2", 256, NULL, 10, NULL);

        vTaskStartScheduler();
        //
	return 0;
}
