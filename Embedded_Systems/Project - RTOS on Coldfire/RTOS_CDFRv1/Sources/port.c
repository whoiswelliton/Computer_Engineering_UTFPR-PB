#include "derivative.h"
#include "os.h"

/*A vantagem de utilizar um sistema operacional é que podemos trocar o processador e se 
tivermos o port nosso código vai funcionar igual no outro processador, tudo o que depende
do sistema se mantém, só será modificado o port*/

/* PRIMEIRO PORT
	1. prepara a pilha da tarefa
	2. descobrir como gerar interrupção de soffware nesse processador
	3. descobrir como salvar e restaurar contexto e mudar o tipo de processador
*/

/* Para implementar o Port devemos entender como são organizados os registradores desse processador:
- do D0 ao D7 = registradores de dados
- do A0 ao A7 =  registradores de endereço
- o A7 é o stackpointer desse processador (32 bits)
- o PC são endereços de 32 bits 

O banco de registradores é assimétrico.
*/

/*
INTERRUPÇÃO = EXCESSÃO
O stack frame de interrupção:
- quando ocorre uma interrupção, é salvo:
	1. a primeira coisa é o '(P)rogram (C)ounter', 
	2. depois registrador de status (32 bits)
	3. vetor com qual interrupção que aconteceu
	4. o formato de empilhamento
	5. e um código de erro (*que podemos ignorar)
*/

/*
GERENCIAMENTO DE TAREFAS
- O nível de interrupção quando voltar de uma tarefa é 0, 0 é o nível da tarefa
- E quando estou dentro de uma interrupção tenho que estar num nível "supervisor",ou seja, 
setar bit S para modo supervisor, isso é feito pra podermos mexer nos registradores 
que permitem realizar a troca de contexto.
*/

/*
TRAP = interrupção de software do processador
- devemos disparar um yield() pra entender como ele salva contexo.
*/


/* Pra garantir que o sistema funciona, devemos escrever o nome do registrador quando
	 inicializada a tarefa, sabendo assim se conseguimos dispachar a tarefa corretamente*/
	 
cpu_t *stk_tmp;

cpu_t *PrepareStack(void *task, cpu_t *stk, int stk_size){
	stk = (cpu_t *)((int)stk + stk_size - sizeof(cpu_t)); 
	
	*stk-- = (cpu_t)task;
	*stk-- = 0x40002000;
	*stk-- = 0xA1;
	*stk-- = 0xA0;
	*stk-- = 0xD2;
	*stk-- = 0xD1;
	*stk-- = 0xD0;
	*stk-- = 0xA6;
	*stk-- = 0xA5;
	*stk-- = 0xA4;
	*stk-- = 0xA3;
	*stk-- = 0xA2;
	*stk-- = 0xD7;
	*stk-- = 0xD6;
	*stk-- = 0xD5;
	*stk-- = 0xD4;
	*stk = 0xD3;  
	
	return stk;
}

/*
Quando ocorre a interrupção o compilador salva automaticamente e temos que salvar o complemento.

- Primeiro salvar todo o contexto, depois salvamos o que falta, usamos o SAVE_CONTEXT();
- Depois de corrigir o stackpointer pra nova tarefa, usamos o RESTORE_CONTEXT();

*/

/* - A Interrupção de contexto ocorre na @Vtrap0 */
interrupt void SwitchContext(void){
	SAVE_CONTEXT();
	SAVE_SP();
	tcb[ct].stk = stk_tmp;
	stk_tmp = scheduler();
	RESTORE_SP();
	RESTORE_CONTEXT();
}

/* - A Interrupção de tempo ocorre na @Vtpm1ovf */
interrupt void TickTimer(void){
	TPM1SC_TOF = 0;
	if( os_inc_and_compare()){
		SAVE_CONTEXT();
		SAVE_SP();
		tcb[ct].stk = stk_tmp;
		stk_tmp = scheduler();
		RESTORE_SP();
		RESTORE_CONTEXT();	
	}
}

void init_os_timer(void){
	TPM1SC = 0x00;
	TPM1MOD = 19999;
	TPM1SC = 0x48;
}