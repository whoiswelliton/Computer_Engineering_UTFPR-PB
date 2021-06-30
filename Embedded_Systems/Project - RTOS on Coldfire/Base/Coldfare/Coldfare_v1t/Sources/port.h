#ifndef _PORT_H_
#define _PORT_H_

typedef unsigned long cpu_t;

extern cpu_t *stk_tmp;

cpu_t *PrepareStack(void *task, cpu_t *stk, int stk_size);
void init_os_timer(void);

#define dispatcher()							\
		asm("MOVE stk_tmp, A7");				\
		asm("MOVEM.L (A7), D3-D7/A2-A6");		\
		asm("LEA 40(A7), A7");					\
		asm("MOVEM.L (A7), D0-D2/A0-A1");		\
		asm("LEA 20(A7), A7");					\
		asm("RTE")      	

	 
#define yield()	asm("TRAP %0")

#define SAVE_SP()	asm("MOVE A7, stk_tmp")			

#define SAVE_CONTEXT()						\
		asm("LEA -40(A7), A7");				\
		asm("MOVEM.L D3-D7/A2-A6, (A7)")

#define RESTORE_CONTEXT()					\
		asm("MOVEM.L (A7), D3-D7/A2-A6");	\
		asm("LEA 40(A7), A7")
	    
#define RESTORE_SP()	asm("MOVE stk_tmp, A7")



#endif