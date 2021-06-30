#include "os.h"

volatile tcb_t tcb[5];
volatile cpu_t ct = 0;
volatile cpu_t it = 0;
volatile long long os_time = 0;

cpu_t stk_idle[ 128];

void InstallTask(task_t task, cpu_t prio, cpu_t *stk, int stk_size){
	stk = PrepareStack(task, stk, stk_size);
	tcb[it].stk = stk;
	tcb[it].prio = prio;
	tcb[it].ready = 1;
	tcb[it].timeout = 0;
	it++;	
}

void os_delay(long long time){
	tcb[ct].timeout = os_time + time;
	tcb[ct].ready = 0;
	yield();
}

void idle_task(void){
	for(;;){
	}
}

cpu_t os_inc_and_compare(void){
	int i = 0;
	cpu_t ready = 0;
	os_time++;
	for(i=0; i<it; i++){
		if(tcb[i].timeout == os_time){
			tcb[i].ready=1;
			ready = 1;
		}
	}
	return ready;
}

cpu_t *scheduler(void){
#if (scheduler_mode == scheduler_coop)
	do{
		ct++;
		if(ct >= it){
			ct = 0;
		}
	}while(!tcb[ct].ready);
	return tcb[ct].stk;
#endif
#if (scheduler_mode == scheduler_prio)
	cpu_t i = 0;
	cpu_t higher_prio = 0;
	cpu_t higher_task = 0;
	for(i=0; i<it; i++){
		if(tcb[i].ready == 1){
			if(tcb[i].prio >= higher_prio){
				higher_prio = tcb[i].prio;
				higher_task = i;
			}
		}
	}
	ct = higher_task;
	return tcb[ct].stk;
#endif
}

void os_start(void){
	InstallTask(idle_task, 0, stk_idle, 128);
	init_os_timer();
	#if (scheduler_mode == scheduler_coop)
		stk_tmp = tcb[ct].stk;
	#endif
	#if (scheduler_mode == scheduler_prio)
		stk_tmp = scheduler();
	#endif
  	dispatcher(); 
}