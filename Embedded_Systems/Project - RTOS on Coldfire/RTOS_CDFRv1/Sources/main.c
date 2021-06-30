#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "os.h"

#ifdef __cplusplus
 extern "C"
#endif
void MCU_init(void); /* Device initialization function declaration */

cpu_t stk1[128];
cpu_t stk2[128];
cpu_t stk3[128];

void task1(void){
	int i =0;
	for(;;){
		i++;
		os_delay(10);
	}
}

void task2(void){
	int i =0;
	for(;;){
		i++;
		os_delay(20);
	}
}

void task3(void){
	int i =0;
	for(;;){
		i++;
		os_delay(30);
	}
}

void main(void) {
  MCU_init(); /* call Device Initialization */

  /* include your code here */
  InstallTask(task1, 1, stk1, 128);  
  InstallTask(task2, 2, stk2, 128);  
  InstallTask(task3, 3, stk3, 128);  
  
 os_start();

  for(;;) {
    /* __RESET_WATCHDOG(); by default, COP is disabled with device init. When enabling, also reset the watchdog. */
  } /* loop forever */
  /* please make sure that you never leave main */
}
