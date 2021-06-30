/*
 * Arquivo:C:\Users\WELLITON LEAL\Desktop\mcpcase.c
 * Código Gerado para a familia MSP430Gxx com saída Mealy
 * Foi utilizado a estrutura case-if como jogador de autômato
 * Desenvolvido por César Rafael Claure Torrico
 */
#include "msp430.h"

//Funções para a sequência operacional dos eventos
void event_1(void);	//Sequência operacional para o evento 1
void event_3(void);	//Sequência operacional para o evento 3
void event_7(void);	//Sequência operacional para o evento 7
void event_9(void);	//Sequência operacional para o evento 9
void event_13(void);	//Sequência operacional para o evento 13
void event_15(void);	//Sequência operacional para o evento 15
void event_19(void);	//Sequência operacional para o evento 19
void event_21(void);	//Sequência operacional para o evento 21
void event_23(void);	//Sequência operacional para o evento 23
void event_25(void);	//Sequência operacional para o evento 25
void event_2(void);	//Sequência operacional para o evento 2
void event_4(void);	//Sequência operacional para o evento 4
void event_8(void);	//Sequência operacional para o evento 8
void event_10(void);	//Sequência operacional para o evento 10
void event_14(void);	//Sequência operacional para o evento 14
void event_16(void);	//Sequência operacional para o evento 16
void event_20(void);	//Sequência operacional para o evento 20
void event_22(void);	//Sequência operacional para o evento 22
void event_24(void);	//Sequência operacional para o evento 24
void event_30(void);	//Sequência operacional para o evento 30
void event_34(void);	//Sequência operacional para o evento 34

//mapeamento de eventos não controláveis como entradas
#define E0 2	//Entrada 0
#define E1 4	//Entrada 1
#define E2 8	//Entrada 2
#define E3 10	//Entrada 3
#define E4 14	//Entrada 4
#define E5 16	//Entrada 5
#define E6 20	//Entrada 6
#define E7 22	//Entrada 7
#define E8 24	//Entrada 8
#define E9 30	//Entrada 9
#define E10 34	//Entrada 10

//definição dos eventos de saída
#define S0_ON  P2OUT |= BIT0	//Saida 0 ON
#define S0_OFF P2OUT &=~BIT0	//Saida 0 OFF
#define S1_ON  P2OUT |= BIT1	//Saida 1 ON
#define S1_OFF P2OUT &=~BIT1	//Saida 1 OFF
#define S2_ON  P2OUT |= BIT2	//Saida 2 ON
#define S2_OFF P2OUT &=~BIT2	//Saida 2 OFF
#define S3_ON  P2OUT |= BIT3	//Saida 3 ON
#define S3_OFF P2OUT &=~BIT3	//Saida 3 OFF
#define S4_ON  P2OUT |= BIT4	//Saida 4 ON
#define S4_OFF P2OUT &=~BIT4	//Saida 4 OFF
#define S5_ON  P2OUT |= BIT5	//Saida 5 ON
#define S5_OFF P2OUT &=~BIT5	//Saida 5 OFF
#define S6_ON  P2OUT |= BIT6	//Saida 6 ON
#define S6_OFF P2OUT &=~BIT6	//Saida 6 OFF
#define S7_ON  P2OUT |= BIT7	//Saida 7 ON
#define S7_OFF P2OUT &=~BIT7	//Saida 7 OFF

//Definição de funções de inicialização
void config_clk(void);		//Configura Clock
void config_timer(void);		//Configura Timer
void config_io(void);		//Configura entradas e saídas
void tempo_ms(unsigned int);	// Função de temporização do timer A em milisegundos

//Declaração de variáveis globais
unsigned int buffer[10];		//Buffer para armazenar a fila de enventos externos
unsigned int n_buffer=0;		//Número de eventos no Buffer
char gerar_evento=1;			//Flag para habilitar a temporização de eventos controláveis

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;		//Desabilita o WDT
	config_clk();				//configura o clk
	config_timer();			//configura o timer
	config_io();				//configura entradas e saídas

	unsigned int k;
	char occur_event;			//Evento ocorrido
	unsigned int current_state = 0;	//Estado atual inicializado com estado inicial
	int g=0; 			//Flag para gerador aleatório de eventos
	_enable_interrupt();		//Habilita interrupção geral

	while(1)
	{

		if(n_buffer == 0)//se não existir evento no buffer então gerar um evento interno(evento controlável)
		{
			if(TACTL&TAIFG)	//Se o timer estourar, habilita a geração de eventos 
			{
				gerar_evento=1;
			}
			if(gerar_evento==1)
			{
				switch(g)	//Aqui é implementado um gerador automático de eventos controláveis
				{
					case(0):
						occur_event=1;
						g++;
						break;
					case(1):
						occur_event=3;
						g++;
						break;
					case(2):
						occur_event=7;
						g++;
						break;
					case(3):
						occur_event=9;
						g++;
						break;
					case(4):
						occur_event=13;
						g++;
						break;
					case(5):
						occur_event=15;
						g++;
						break;
					case(6):
						occur_event=19;
						g++;
						break;
					case(7):
						occur_event=21;
						g++;
						break;
					case(8):
						occur_event=23;
						g++;
						break;
					case(9):
						occur_event=25;
						g=0;
						break;
				}
			}
		}
		else 	//se existir evento não controlável pegar do buffer
		{
			occur_event = buffer[0];
			n_buffer--;
			k = 0;
			while(k<n_buffer)
			{
				buffer[k] = buffer[k+1];
				k++;
			}
		}
		switch(current_state)
		{
			case(0):
				if(occur_event == 19)
				{
					event_19();
					current_state = 1;
				}
				break;
			case(1):
				if(occur_event == 24)
				{
					event_24();
					current_state = 3;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 1;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 2;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(2):
				if(occur_event == 24)
				{
					event_24();
					current_state = 5;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 2;
				}
				if(occur_event == 21)
				{
					event_21();
					current_state = 4;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 2;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(3):
				if(occur_event == 30)
				{
					event_30();
					current_state = 6;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 3;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 5;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(4):
				if(occur_event == 1)
				{
					event_1();
					current_state = 7;
				}
				break;
			case(5):
				if(occur_event == 30)
				{
					event_30();
					current_state = 9;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 5;
				}
				if(occur_event == 23)
				{
					event_23();
					current_state = 8;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 5;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(6):
				if(occur_event == 22)
				{
					event_22();
					current_state = 9;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(7):
				if(occur_event == 2)
				{
					event_2();
					current_state = 10;
				}
				break;
			case(8):
				if(occur_event == 7)
				{
					event_7();
					current_state = 11;
				}
				break;
			case(9):
				if(occur_event == 25)
				{
					event_25();
					current_state = 12;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 9;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(10):
				if(occur_event == 3)
				{
					event_3();
					current_state = 14;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 13;
				}
				break;
			case(11):
				if(occur_event == 8)
				{
					event_8();
					current_state = 15;
				}
				break;
			case(12):
				if(occur_event == 13)
				{
					event_13();
					current_state = 16;
				}
				break;
			case(13):
				if(occur_event == 3)
				{
					event_3();
					current_state = 0;
				}
				break;
			case(14):
				if(occur_event == 19)
				{
					event_19();
					current_state = 17;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 0;
				}
				break;
			case(15):
				if(occur_event == 10)
				{
					event_10();
					current_state = 19;
				}
				if(occur_event == 9)
				{
					event_9();
					current_state = 18;
				}
				break;
			case(16):
				break;
			case(17):
				if(occur_event == 24)
				{
					event_24();
					current_state = 22;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 17;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 21;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 20;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(18):
				if(occur_event == 19)
				{
					event_19();
					current_state = 23;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 0;
				}
				break;
			case(19):
				if(occur_event == 9)
				{
					event_9();
					current_state = 0;
				}
				break;
			case(20):
				if(occur_event == 24)
				{
					event_24();
					current_state = 25;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 20;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 24;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 20;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(21):
				if(occur_event == 24)
				{
					event_24();
					current_state = 26;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 21;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 24;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(22):
				if(occur_event == 30)
				{
					event_30();
					current_state = 27;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 22;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 26;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 25;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(23):
				if(occur_event == 24)
				{
					event_24();
					current_state = 30;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 23;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 29;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 28;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(24):
				if(occur_event == 24)
				{
					event_24();
					current_state = 31;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 24;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 24;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(25):
				if(occur_event == 30)
				{
					event_30();
					current_state = 33;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 25;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 31;
				}
				if(occur_event == 23)
				{
					event_23();
					current_state = 32;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 25;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(26):
				if(occur_event == 30)
				{
					event_30();
					current_state = 34;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 26;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 31;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(27):
				if(occur_event == 4)
				{
					event_4();
					current_state = 34;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 33;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(28):
				if(occur_event == 24)
				{
					event_24();
					current_state = 37;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 28;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 36;
				}
				if(occur_event == 21)
				{
					event_21();
					current_state = 35;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 28;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(29):
				if(occur_event == 24)
				{
					event_24();
					current_state = 38;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 29;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 36;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(30):
				if(occur_event == 30)
				{
					event_30();
					current_state = 39;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 30;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 38;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 37;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(31):
				if(occur_event == 30)
				{
					event_30();
					current_state = 41;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 31;
				}
				if(occur_event == 23)
				{
					event_23();
					current_state = 40;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 31;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(32):
				if(occur_event == 7)
				{
					event_7();
					current_state = 42;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 40;
				}
				break;
			case(33):
				if(occur_event == 4)
				{
					event_4();
					current_state = 41;
				}
				if(occur_event == 25)
				{
					event_25();
					current_state = 43;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 33;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(34):
				if(occur_event == 22)
				{
					event_22();
					current_state = 41;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(35):
				if(occur_event == 10)
				{
					event_10();
					current_state = 45;
				}
				if(occur_event == 1)
				{
					event_1();
					current_state = 44;
				}
				break;
			case(36):
				if(occur_event == 24)
				{
					event_24();
					current_state = 46;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 36;
				}
				if(occur_event == 21)
				{
					event_21();
					current_state = 45;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 36;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(37):
				if(occur_event == 30)
				{
					event_30();
					current_state = 47;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 37;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 46;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 37;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(38):
				if(occur_event == 30)
				{
					event_30();
					current_state = 48;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 38;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 46;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(39):
				if(occur_event == 10)
				{
					event_10();
					current_state = 48;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 47;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(40):
				if(occur_event == 7)
				{
					event_7();
					current_state = 49;
				}
				break;
			case(41):
				if(occur_event == 25)
				{
					event_25();
					current_state = 50;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 41;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(42):
				if(occur_event == 8)
				{
					event_8();
					current_state = 51;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 49;
				}
				break;
			case(43):
				if(occur_event == 4)
				{
					event_4();
					current_state = 50;
				}
				if(occur_event == 13)
				{
					event_13();
					current_state = 52;
				}
				break;
			case(44):
				if(occur_event == 10)
				{
					event_10();
					current_state = 54;
				}
				if(occur_event == 2)
				{
					event_2();
					current_state = 53;
				}
				break;
			case(45):
				if(occur_event == 1)
				{
					event_1();
					current_state = 54;
				}
				break;
			case(46):
				if(occur_event == 30)
				{
					event_30();
					current_state = 55;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 46;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 46;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(47):
				if(occur_event == 10)
				{
					event_10();
					current_state = 55;
				}
				if(occur_event == 25)
				{
					event_25();
					current_state = 56;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 47;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(48):
				if(occur_event == 22)
				{
					event_22();
					current_state = 55;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(49):
				if(occur_event == 8)
				{
					event_8();
					current_state = 57;
				}
				break;
			case(50):
				if(occur_event == 13)
				{
					event_13();
					current_state = 58;
				}
				break;
			case(51):
				if(occur_event == 10)
				{
					event_10();
					current_state = 60;
				}
				if(occur_event == 9)
				{
					event_9();
					current_state = 59;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 15;
				}
				break;
			case(52):
				if(occur_event == 4)
				{
					event_4();
					current_state = 58;
				}
				break;
			case(53):
				if(occur_event == 10)
				{
					event_10();
					current_state = 10;
				}
				if(occur_event == 3)
				{
					event_3();
					current_state = 59;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 61;
				}
				break;
			case(54):
				if(occur_event == 2)
				{
					event_2();
					current_state = 62;
				}
				break;
			case(55):
				if(occur_event == 25)
				{
					event_25();
					current_state = 63;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 55;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(56):
				if(occur_event == 10)
				{
					event_10();
					current_state = 63;
				}
				if(occur_event == 13)
				{
					event_13();
					current_state = 64;
				}
				break;
			case(57):
				if(occur_event == 10)
				{
					event_10();
					current_state = 66;
				}
				if(occur_event == 9)
				{
					event_9();
					current_state = 65;
				}
				break;
			case(58):
				break;
			case(59):
				if(occur_event == 19)
				{
					event_19();
					current_state = 67;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 14;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 18;
				}
				break;
			case(60):
				if(occur_event == 9)
				{
					event_9();
					current_state = 14;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 19;
				}
				break;
			case(61):
				if(occur_event == 10)
				{
					event_10();
					current_state = 13;
				}
				if(occur_event == 3)
				{
					event_3();
					current_state = 18;
				}
				break;
			case(62):
				if(occur_event == 3)
				{
					event_3();
					current_state = 69;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 68;
				}
				break;
			case(63):
				if(occur_event == 13)
				{
					event_13();
					current_state = 70;
				}
				break;
			case(64):
				if(occur_event == 10)
				{
					event_10();
					current_state = 70;
				}
				break;
			case(65):
				if(occur_event == 19)
				{
					event_19();
					current_state = 72;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 71;
				}
				break;
			case(66):
				if(occur_event == 9)
				{
					event_9();
					current_state = 71;
				}
				break;
			case(67):
				if(occur_event == 24)
				{
					event_24();
					current_state = 75;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 67;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 74;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 72;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 73;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(68):
				if(occur_event == 3)
				{
					event_3();
					current_state = 76;
				}
				break;
			case(69):
				if(occur_event == 19)
				{
					event_19();
					current_state = 74;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 76;
				}
				break;
			case(70):
				if(occur_event == 14)
				{
					event_14();
					current_state = 77;
				}
				break;
			case(71):
				if(occur_event == 19)
				{
					event_19();
					current_state = 21;
				}
				break;
			case(72):
				if(occur_event == 24)
				{
					event_24();
					current_state = 80;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 72;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 79;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 78;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(73):
				if(occur_event == 24)
				{
					event_24();
					current_state = 82;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 73;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 81;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 78;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 73;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(74):
				if(occur_event == 24)
				{
					event_24();
					current_state = 83;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 74;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 79;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 81;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(75):
				if(occur_event == 30)
				{
					event_30();
					current_state = 84;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 75;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 83;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 80;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 82;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(76):
				if(occur_event == 19)
				{
					event_19();
					current_state = 29;
				}
				break;
			case(77):
				if(occur_event == 15)
				{
					event_15();
					current_state = 85;
				}
				break;
			case(78):
				if(occur_event == 24)
				{
					event_24();
					current_state = 87;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 78;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 86;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 78;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(79):
				if(occur_event == 24)
				{
					event_24();
					current_state = 88;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 79;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 86;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(80):
				if(occur_event == 30)
				{
					event_30();
					current_state = 89;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 80;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 88;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 87;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(81):
				if(occur_event == 24)
				{
					event_24();
					current_state = 90;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 81;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 86;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 81;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(82):
				if(occur_event == 30)
				{
					event_30();
					current_state = 91;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 82;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 90;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 87;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 82;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(83):
				if(occur_event == 30)
				{
					event_30();
					current_state = 92;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 83;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 88;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 90;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(84):
				if(occur_event == 10)
				{
					event_10();
					current_state = 92;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 89;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 91;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(85):
				if(occur_event == 19)
				{
					event_19();
					current_state = 93;
				}
				break;
			case(86):
				if(occur_event == 24)
				{
					event_24();
					current_state = 94;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 86;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 86;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(87):
				if(occur_event == 30)
				{
					event_30();
					current_state = 95;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 87;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 94;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 87;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(88):
				if(occur_event == 30)
				{
					event_30();
					current_state = 96;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 88;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 94;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(89):
				if(occur_event == 10)
				{
					event_10();
					current_state = 96;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 95;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(90):
				if(occur_event == 30)
				{
					event_30();
					current_state = 97;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 90;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 94;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 90;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(91):
				if(occur_event == 10)
				{
					event_10();
					current_state = 97;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 95;
				}
				if(occur_event == 25)
				{
					event_25();
					current_state = 98;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 91;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(92):
				if(occur_event == 4)
				{
					event_4();
					current_state = 96;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 97;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(93):
				if(occur_event == 24)
				{
					event_24();
					current_state = 101;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 93;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 100;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(94):
				if(occur_event == 30)
				{
					event_30();
					current_state = 102;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 94;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 94;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(95):
				if(occur_event == 10)
				{
					event_10();
					current_state = 102;
				}
				if(occur_event == 25)
				{
					event_25();
					current_state = 103;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 95;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(96):
				if(occur_event == 22)
				{
					event_22();
					current_state = 102;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(97):
				if(occur_event == 4)
				{
					event_4();
					current_state = 102;
				}
				if(occur_event == 25)
				{
					event_25();
					current_state = 104;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 97;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(98):
				if(occur_event == 10)
				{
					event_10();
					current_state = 104;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 103;
				}
				if(occur_event == 13)
				{
					event_13();
					current_state = 105;
				}
				break;
			case(99):
				if(occur_event == 19)
				{
					event_19();
					current_state = 106;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 0;
				}
				break;
			case(100):
				if(occur_event == 24)
				{
					event_24();
					current_state = 108;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 100;
				}
				if(occur_event == 21)
				{
					event_21();
					current_state = 107;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 100;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(101):
				if(occur_event == 30)
				{
					event_30();
					current_state = 109;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 101;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 108;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(102):
				if(occur_event == 25)
				{
					event_25();
					current_state = 110;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 102;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(103):
				if(occur_event == 10)
				{
					event_10();
					current_state = 110;
				}
				if(occur_event == 13)
				{
					event_13();
					current_state = 111;
				}
				break;
			case(104):
				if(occur_event == 4)
				{
					event_4();
					current_state = 110;
				}
				if(occur_event == 13)
				{
					event_13();
					current_state = 112;
				}
				break;
			case(105):
				if(occur_event == 10)
				{
					event_10();
					current_state = 112;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 111;
				}
				break;
			case(106):
				if(occur_event == 24)
				{
					event_24();
					current_state = 115;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 106;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 114;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 113;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(107):
				if(occur_event == 1)
				{
					event_1();
					current_state = 116;
				}
				break;
			case(108):
				if(occur_event == 30)
				{
					event_30();
					current_state = 117;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 108;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 108;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(109):
				if(occur_event == 22)
				{
					event_22();
					current_state = 117;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(110):
				if(occur_event == 13)
				{
					event_13();
					current_state = 118;
				}
				break;
			case(111):
				if(occur_event == 10)
				{
					event_10();
					current_state = 118;
				}
				break;
			case(112):
				if(occur_event == 4)
				{
					event_4();
					current_state = 118;
				}
				if(occur_event == 14)
				{
					event_14();
					current_state = 119;
				}
				break;
			case(113):
				if(occur_event == 24)
				{
					event_24();
					current_state = 122;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 113;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 121;
				}
				if(occur_event == 21)
				{
					event_21();
					current_state = 120;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 113;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(114):
				if(occur_event == 24)
				{
					event_24();
					current_state = 123;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 114;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 121;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(115):
				if(occur_event == 30)
				{
					event_30();
					current_state = 124;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 115;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 123;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 122;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(116):
				if(occur_event == 2)
				{
					event_2();
					current_state = 125;
				}
				break;
			case(117):
				if(occur_event == 22)
				{
					event_22();
					current_state = 117;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(118):
				if(occur_event == 14)
				{
					event_14();
					current_state = 126;
				}
				break;
			case(119):
				if(occur_event == 4)
				{
					event_4();
					current_state = 126;
				}
				if(occur_event == 15)
				{
					event_15();
					current_state = 127;
				}
				break;
			case(120):
				if(occur_event == 1)
				{
					event_1();
					current_state = 129;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 128;
				}
				break;
			case(121):
				if(occur_event == 24)
				{
					event_24();
					current_state = 130;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 121;
				}
				if(occur_event == 21)
				{
					event_21();
					current_state = 128;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 121;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(122):
				if(occur_event == 30)
				{
					event_30();
					current_state = 132;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 122;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 130;
				}
				if(occur_event == 23)
				{
					event_23();
					current_state = 131;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 122;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(123):
				if(occur_event == 30)
				{
					event_30();
					current_state = 133;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 123;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 130;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(124):
				if(occur_event == 16)
				{
					event_16();
					current_state = 133;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 132;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(125):
				if(occur_event == 3)
				{
					event_3();
					current_state = 135;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 134;
				}
				break;
			case(126):
				if(occur_event == 15)
				{
					event_15();
					current_state = 136;
				}
				break;
			case(127):
				if(occur_event == 19)
				{
					event_19();
					current_state = 137;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 136;
				}
				break;
			case(128):
				if(occur_event == 1)
				{
					event_1();
					current_state = 138;
				}
				break;
			case(129):
				if(occur_event == 2)
				{
					event_2();
					current_state = 139;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 138;
				}
				break;
			case(130):
				if(occur_event == 30)
				{
					event_30();
					current_state = 141;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 130;
				}
				if(occur_event == 23)
				{
					event_23();
					current_state = 140;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 130;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(131):
				if(occur_event == 7)
				{
					event_7();
					current_state = 142;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 140;
				}
				break;
			case(132):
				if(occur_event == 16)
				{
					event_16();
					current_state = 141;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 132;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(133):
				if(occur_event == 22)
				{
					event_22();
					current_state = 141;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(134):
				if(occur_event == 3)
				{
					event_3();
					current_state = 85;
				}
				break;
			case(135):
				if(occur_event == 19)
				{
					event_19();
					current_state = 137;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 85;
				}
				break;
			case(136):
				if(occur_event == 19)
				{
					event_19();
					current_state = 143;
				}
				break;
			case(137):
				if(occur_event == 24)
				{
					event_24();
					current_state = 146;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 137;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 143;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 145;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 144;
				}
				break;
			case(138):
				if(occur_event == 2)
				{
					event_2();
					current_state = 147;
				}
				break;
			case(139):
				if(occur_event == 3)
				{
					event_3();
					current_state = 144;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 148;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 10;
				}
				break;
			case(140):
				if(occur_event == 7)
				{
					event_7();
					current_state = 149;
				}
				break;
			case(141):
				if(occur_event == 22)
				{
					event_22();
					current_state = 141;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(142):
				if(occur_event == 8)
				{
					event_8();
					current_state = 150;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 149;
				}
				break;
			case(143):
				if(occur_event == 24)
				{
					event_24();
					current_state = 152;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 143;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 151;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(144):
				if(occur_event == 19)
				{
					event_19();
					current_state = 153;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 99;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 14;
				}
				break;
			case(145):
				if(occur_event == 24)
				{
					event_24();
					current_state = 154;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 145;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 151;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 145;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 144;
				}
				break;
			case(146):
				if(occur_event == 30)
				{
					event_30();
					current_state = 155;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 146;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 152;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 154;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 144;
				}
				break;
			case(147):
				if(occur_event == 3)
				{
					event_3();
					current_state = 157;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 156;
				}
				break;
			case(148):
				if(occur_event == 3)
				{
					event_3();
					current_state = 99;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 13;
				}
				break;
			case(149):
				if(occur_event == 8)
				{
					event_8();
					current_state = 158;
				}
				break;
			case(150):
				if(occur_event == 10)
				{
					event_10();
					current_state = 160;
				}
				if(occur_event == 9)
				{
					event_9();
					current_state = 159;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 15;
				}
				break;
			case(151):
				if(occur_event == 24)
				{
					event_24();
					current_state = 161;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 151;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 151;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(152):
				if(occur_event == 30)
				{
					event_30();
					current_state = 162;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 152;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 161;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(153):
				if(occur_event == 24)
				{
					event_24();
					current_state = 166;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 153;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 165;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 164;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 163;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 144;
				}
				break;
			case(154):
				if(occur_event == 30)
				{
					event_30();
					current_state = 167;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 154;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 161;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 154;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 144;
				}
				break;
			case(155):
				if(occur_event == 4)
				{
					event_4();
					current_state = 162;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 167;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 144;
				}
				break;
			case(156):
				if(occur_event == 3)
				{
					event_3();
					current_state = 168;
				}
				break;
			case(157):
				if(occur_event == 19)
				{
					event_19();
					current_state = 169;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 168;
				}
				break;
			case(158):
				if(occur_event == 10)
				{
					event_10();
					current_state = 171;
				}
				if(occur_event == 9)
				{
					event_9();
					current_state = 170;
				}
				break;
			case(159):
				if(occur_event == 19)
				{
					event_19();
					current_state = 172;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 99;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 18;
				}
				break;
			case(160):
				if(occur_event == 9)
				{
					event_9();
					current_state = 99;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 19;
				}
				break;
			case(161):
				if(occur_event == 30)
				{
					event_30();
					current_state = 173;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 161;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 161;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(162):
				if(occur_event == 22)
				{
					event_22();
					current_state = 173;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(163):
				if(occur_event == 24)
				{
					event_24();
					current_state = 176;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 163;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 175;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 174;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 163;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 144;
				}
				break;
			case(164):
				if(occur_event == 24)
				{
					event_24();
					current_state = 177;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 164;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 114;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 174;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(165):
				if(occur_event == 24)
				{
					event_24();
					current_state = 179;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 165;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 178;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 175;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(166):
				if(occur_event == 30)
				{
					event_30();
					current_state = 180;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 166;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 179;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 177;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 176;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 144;
				}
				break;
			case(167):
				if(occur_event == 4)
				{
					event_4();
					current_state = 173;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 167;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 144;
				}
				break;
			case(168):
				if(occur_event == 19)
				{
					event_19();
					current_state = 114;
				}
				break;
			case(169):
				if(occur_event == 24)
				{
					event_24();
					current_state = 182;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 169;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 178;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 181;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(170):
				if(occur_event == 19)
				{
					event_19();
					current_state = 183;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 168;
				}
				break;
			case(171):
				if(occur_event == 9)
				{
					event_9();
					current_state = 168;
				}
				break;
			case(172):
				if(occur_event == 24)
				{
					event_24();
					current_state = 186;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 172;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 93;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 185;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 184;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 159;
				}
				break;
			case(173):
				if(occur_event == 22)
				{
					event_22();
					current_state = 173;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(174):
				if(occur_event == 24)
				{
					event_24();
					current_state = 187;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 174;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 121;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 174;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(175):
				if(occur_event == 24)
				{
					event_24();
					current_state = 189;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 175;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 188;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 175;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(176):
				if(occur_event == 30)
				{
					event_30();
					current_state = 191;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 176;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 189;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 187;
				}
				if(occur_event == 23)
				{
					event_23();
					current_state = 190;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 176;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 144;
				}
				break;
			case(177):
				if(occur_event == 30)
				{
					event_30();
					current_state = 192;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 177;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 123;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 187;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(178):
				if(occur_event == 24)
				{
					event_24();
					current_state = 193;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 178;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 188;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(179):
				if(occur_event == 30)
				{
					event_30();
					current_state = 194;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 179;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 193;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 189;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(180):
				if(occur_event == 4)
				{
					event_4();
					current_state = 194;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 192;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 191;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 144;
				}
				break;
			case(181):
				if(occur_event == 24)
				{
					event_24();
					current_state = 195;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 181;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 188;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 181;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(182):
				if(occur_event == 30)
				{
					event_30();
					current_state = 196;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 182;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 193;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 195;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(183):
				if(occur_event == 24)
				{
					event_24();
					current_state = 199;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 183;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 198;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 197;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(184):
				if(occur_event == 24)
				{
					event_24();
					current_state = 202;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 184;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 100;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 201;
				}
				if(occur_event == 21)
				{
					event_21();
					current_state = 200;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 184;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 159;
				}
				break;
			case(185):
				if(occur_event == 24)
				{
					event_24();
					current_state = 203;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 185;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 114;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 201;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(186):
				if(occur_event == 30)
				{
					event_30();
					current_state = 204;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 186;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 101;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 203;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 202;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 159;
				}
				break;
			case(187):
				if(occur_event == 30)
				{
					event_30();
					current_state = 206;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 187;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 130;
				}
				if(occur_event == 23)
				{
					event_23();
					current_state = 205;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 187;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(188):
				if(occur_event == 24)
				{
					event_24();
					current_state = 207;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 188;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 188;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(189):
				if(occur_event == 30)
				{
					event_30();
					current_state = 209;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 189;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 207;
				}
				if(occur_event == 23)
				{
					event_23();
					current_state = 208;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 189;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(190):
				if(occur_event == 7)
				{
					event_7();
					current_state = 210;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 208;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 205;
				}
				break;
			case(191):
				if(occur_event == 4)
				{
					event_4();
					current_state = 209;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 206;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 191;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 144;
				}
				break;
			case(192):
				if(occur_event == 4)
				{
					event_4();
					current_state = 133;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 206;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(193):
				if(occur_event == 30)
				{
					event_30();
					current_state = 211;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 193;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 207;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(194):
				if(occur_event == 16)
				{
					event_16();
					current_state = 211;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 209;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(195):
				if(occur_event == 30)
				{
					event_30();
					current_state = 213;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 195;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 207;
				}
				if(occur_event == 23)
				{
					event_23();
					current_state = 212;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 195;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(196):
				if(occur_event == 4)
				{
					event_4();
					current_state = 211;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 213;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(197):
				if(occur_event == 24)
				{
					event_24();
					current_state = 216;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 197;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 215;
				}
				if(occur_event == 21)
				{
					event_21();
					current_state = 214;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 197;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(198):
				if(occur_event == 24)
				{
					event_24();
					current_state = 217;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 198;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 215;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(199):
				if(occur_event == 30)
				{
					event_30();
					current_state = 218;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 199;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 217;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 216;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(200):
				if(occur_event == 10)
				{
					event_10();
					current_state = 107;
				}
				if(occur_event == 1)
				{
					event_1();
					current_state = 220;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 219;
				}
				break;
			case(201):
				if(occur_event == 24)
				{
					event_24();
					current_state = 221;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 201;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 121;
				}
				if(occur_event == 21)
				{
					event_21();
					current_state = 219;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 201;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(202):
				if(occur_event == 30)
				{
					event_30();
					current_state = 222;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 202;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 108;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 221;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 202;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 159;
				}
				break;
			case(203):
				if(occur_event == 30)
				{
					event_30();
					current_state = 223;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 203;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 123;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 221;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(204):
				if(occur_event == 10)
				{
					event_10();
					current_state = 109;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 223;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 222;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 159;
				}
				break;
			case(205):
				if(occur_event == 7)
				{
					event_7();
					current_state = 224;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 140;
				}
				break;
			case(206):
				if(occur_event == 4)
				{
					event_4();
					current_state = 141;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 206;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(207):
				if(occur_event == 30)
				{
					event_30();
					current_state = 226;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 207;
				}
				if(occur_event == 23)
				{
					event_23();
					current_state = 225;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 207;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(208):
				if(occur_event == 7)
				{
					event_7();
					current_state = 227;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 225;
				}
				break;
			case(209):
				if(occur_event == 16)
				{
					event_16();
					current_state = 226;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 209;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 99;
				}
				break;
			case(210):
				if(occur_event == 8)
				{
					event_8();
					current_state = 228;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 227;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 224;
				}
				break;
			case(211):
				if(occur_event == 22)
				{
					event_22();
					current_state = 226;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(212):
				if(occur_event == 7)
				{
					event_7();
					current_state = 229;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 225;
				}
				break;
			case(213):
				if(occur_event == 4)
				{
					event_4();
					current_state = 226;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 213;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(214):
				if(occur_event == 10)
				{
					event_10();
					current_state = 231;
				}
				if(occur_event == 1)
				{
					event_1();
					current_state = 230;
				}
				break;
			case(215):
				if(occur_event == 24)
				{
					event_24();
					current_state = 232;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 215;
				}
				if(occur_event == 21)
				{
					event_21();
					current_state = 231;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 215;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(216):
				if(occur_event == 30)
				{
					event_30();
					current_state = 233;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 216;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 232;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 216;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(217):
				if(occur_event == 30)
				{
					event_30();
					current_state = 234;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 217;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 232;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(218):
				if(occur_event == 10)
				{
					event_10();
					current_state = 234;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 233;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(219):
				if(occur_event == 10)
				{
					event_10();
					current_state = 128;
				}
				if(occur_event == 1)
				{
					event_1();
					current_state = 235;
				}
				break;
			case(220):
				if(occur_event == 10)
				{
					event_10();
					current_state = 116;
				}
				if(occur_event == 2)
				{
					event_2();
					current_state = 236;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 235;
				}
				break;
			case(221):
				if(occur_event == 30)
				{
					event_30();
					current_state = 237;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 221;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 130;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 221;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(222):
				if(occur_event == 10)
				{
					event_10();
					current_state = 117;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 237;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 222;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 159;
				}
				break;
			case(223):
				if(occur_event == 10)
				{
					event_10();
					current_state = 133;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 237;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(224):
				if(occur_event == 8)
				{
					event_8();
					current_state = 238;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 149;
				}
				break;
			case(225):
				if(occur_event == 7)
				{
					event_7();
					current_state = 239;
				}
				break;
			case(226):
				if(occur_event == 22)
				{
					event_22();
					current_state = 226;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(227):
				if(occur_event == 8)
				{
					event_8();
					current_state = 240;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 239;
				}
				break;
			case(228):
				if(occur_event == 10)
				{
					event_10();
					current_state = 242;
				}
				if(occur_event == 9)
				{
					event_9();
					current_state = 241;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 150;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 51;
				}
				break;
			case(229):
				if(occur_event == 8)
				{
					event_8();
					current_state = 238;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 239;
				}
				break;
			case(230):
				if(occur_event == 10)
				{
					event_10();
					current_state = 244;
				}
				if(occur_event == 2)
				{
					event_2();
					current_state = 243;
				}
				break;
			case(231):
				if(occur_event == 1)
				{
					event_1();
					current_state = 244;
				}
				break;
			case(232):
				if(occur_event == 30)
				{
					event_30();
					current_state = 245;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 232;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 232;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(233):
				if(occur_event == 10)
				{
					event_10();
					current_state = 245;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 233;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(234):
				if(occur_event == 22)
				{
					event_22();
					current_state = 245;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(235):
				if(occur_event == 10)
				{
					event_10();
					current_state = 138;
				}
				if(occur_event == 2)
				{
					event_2();
					current_state = 243;
				}
				break;
			case(236):
				if(occur_event == 10)
				{
					event_10();
					current_state = 139;
				}
				if(occur_event == 3)
				{
					event_3();
					current_state = 241;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 246;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 53;
				}
				break;
			case(237):
				if(occur_event == 10)
				{
					event_10();
					current_state = 141;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 237;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(238):
				if(occur_event == 10)
				{
					event_10();
					current_state = 248;
				}
				if(occur_event == 9)
				{
					event_9();
					current_state = 247;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 158;
				}
				break;
			case(239):
				if(occur_event == 8)
				{
					event_8();
					current_state = 249;
				}
				break;
			case(240):
				if(occur_event == 10)
				{
					event_10();
					current_state = 251;
				}
				if(occur_event == 9)
				{
					event_9();
					current_state = 250;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 57;
				}
				break;
			case(241):
				if(occur_event == 19)
				{
					event_19();
					current_state = 252;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 144;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 159;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 59;
				}
				break;
			case(242):
				if(occur_event == 9)
				{
					event_9();
					current_state = 144;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 160;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 60;
				}
				break;
			case(243):
				if(occur_event == 10)
				{
					event_10();
					current_state = 147;
				}
				if(occur_event == 3)
				{
					event_3();
					current_state = 247;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 253;
				}
				break;
			case(244):
				if(occur_event == 2)
				{
					event_2();
					current_state = 254;
				}
				break;
			case(245):
				if(occur_event == 22)
				{
					event_22();
					current_state = 245;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(246):
				if(occur_event == 10)
				{
					event_10();
					current_state = 148;
				}
				if(occur_event == 3)
				{
					event_3();
					current_state = 159;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 61;
				}
				break;
			case(247):
				if(occur_event == 19)
				{
					event_19();
					current_state = 255;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 157;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 170;
				}
				break;
			case(248):
				if(occur_event == 9)
				{
					event_9();
					current_state = 157;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 171;
				}
				break;
			case(249):
				if(occur_event == 10)
				{
					event_10();
					current_state = 257;
				}
				if(occur_event == 9)
				{
					event_9();
					current_state = 256;
				}
				break;
			case(250):
				if(occur_event == 19)
				{
					event_19();
					current_state = 259;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 258;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 65;
				}
				break;
			case(251):
				if(occur_event == 9)
				{
					event_9();
					current_state = 258;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 66;
				}
				break;
			case(252):
				if(occur_event == 24)
				{
					event_24();
					current_state = 262;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 252;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 137;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 259;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 261;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 260;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 241;
				}
				break;
			case(253):
				if(occur_event == 10)
				{
					event_10();
					current_state = 156;
				}
				if(occur_event == 3)
				{
					event_3();
					current_state = 170;
				}
				break;
			case(254):
				if(occur_event == 3)
				{
					event_3();
					current_state = 264;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 263;
				}
				break;
			case(255):
				if(occur_event == 24)
				{
					event_24();
					current_state = 268;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 255;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 267;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 266;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 265;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(256):
				if(occur_event == 19)
				{
					event_19();
					current_state = 266;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 269;
				}
				break;
			case(257):
				if(occur_event == 9)
				{
					event_9();
					current_state = 269;
				}
				break;
			case(258):
				if(occur_event == 19)
				{
					event_19();
					current_state = 165;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 71;
				}
				break;
			case(259):
				if(occur_event == 24)
				{
					event_24();
					current_state = 272;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 259;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 143;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 271;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 270;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 159;
				}
				break;
			case(260):
				if(occur_event == 24)
				{
					event_24();
					current_state = 274;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 260;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 145;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 270;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 273;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 260;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 241;
				}
				break;
			case(261):
				if(occur_event == 24)
				{
					event_24();
					current_state = 275;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 261;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 164;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 185;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 273;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(262):
				if(occur_event == 30)
				{
					event_30();
					current_state = 276;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 262;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 146;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 272;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 275;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 274;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 241;
				}
				break;
			case(263):
				if(occur_event == 3)
				{
					event_3();
					current_state = 277;
				}
				break;
			case(264):
				if(occur_event == 19)
				{
					event_19();
					current_state = 267;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 277;
				}
				break;
			case(265):
				if(occur_event == 24)
				{
					event_24();
					current_state = 280;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 265;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 279;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 278;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 265;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(266):
				if(occur_event == 24)
				{
					event_24();
					current_state = 282;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 266;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 281;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 278;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(267):
				if(occur_event == 24)
				{
					event_24();
					current_state = 283;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 267;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 281;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 279;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(268):
				if(occur_event == 30)
				{
					event_30();
					current_state = 284;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 268;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 283;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 282;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 280;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(269):
				if(occur_event == 19)
				{
					event_19();
					current_state = 178;
				}
				break;
			case(270):
				if(occur_event == 24)
				{
					event_24();
					current_state = 286;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 270;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 151;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 285;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 270;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 159;
				}
				break;
			case(271):
				if(occur_event == 24)
				{
					event_24();
					current_state = 287;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 271;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 178;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 285;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(272):
				if(occur_event == 30)
				{
					event_30();
					current_state = 288;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 272;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 152;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 287;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 286;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 159;
				}
				break;
			case(273):
				if(occur_event == 24)
				{
					event_24();
					current_state = 289;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 273;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 174;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 201;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 273;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(274):
				if(occur_event == 30)
				{
					event_30();
					current_state = 290;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 274;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 154;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 286;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 289;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 274;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 241;
				}
				break;
			case(275):
				if(occur_event == 30)
				{
					event_30();
					current_state = 291;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 275;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 177;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 203;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 289;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(276):
				if(occur_event == 10)
				{
					event_10();
					current_state = 155;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 288;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 291;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 290;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 241;
				}
				break;
			case(277):
				if(occur_event == 19)
				{
					event_19();
					current_state = 198;
				}
				break;
			case(278):
				if(occur_event == 24)
				{
					event_24();
					current_state = 293;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 278;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 292;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 278;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(279):
				if(occur_event == 24)
				{
					event_24();
					current_state = 294;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 279;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 292;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 279;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(280):
				if(occur_event == 30)
				{
					event_30();
					current_state = 295;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 280;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 294;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 293;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 280;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(281):
				if(occur_event == 24)
				{
					event_24();
					current_state = 296;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 281;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 292;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(282):
				if(occur_event == 30)
				{
					event_30();
					current_state = 297;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 282;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 296;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 293;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(283):
				if(occur_event == 30)
				{
					event_30();
					current_state = 298;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 283;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 296;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 294;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(284):
				if(occur_event == 10)
				{
					event_10();
					current_state = 298;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 297;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 295;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(285):
				if(occur_event == 24)
				{
					event_24();
					current_state = 299;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 285;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 188;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 285;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(286):
				if(occur_event == 30)
				{
					event_30();
					current_state = 300;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 286;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 161;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 299;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 286;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 159;
				}
				break;
			case(287):
				if(occur_event == 30)
				{
					event_30();
					current_state = 301;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 287;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 193;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 299;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(288):
				if(occur_event == 10)
				{
					event_10();
					current_state = 162;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 301;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 300;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 159;
				}
				break;
			case(289):
				if(occur_event == 30)
				{
					event_30();
					current_state = 302;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 289;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 187;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 221;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 289;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(290):
				if(occur_event == 10)
				{
					event_10();
					current_state = 167;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 300;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 302;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 290;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 241;
				}
				break;
			case(291):
				if(occur_event == 10)
				{
					event_10();
					current_state = 192;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 223;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 302;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(292):
				if(occur_event == 24)
				{
					event_24();
					current_state = 303;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 292;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 292;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(293):
				if(occur_event == 30)
				{
					event_30();
					current_state = 304;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 293;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 303;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 293;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(294):
				if(occur_event == 30)
				{
					event_30();
					current_state = 305;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 294;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 303;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 294;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(295):
				if(occur_event == 10)
				{
					event_10();
					current_state = 305;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 304;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 295;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(296):
				if(occur_event == 30)
				{
					event_30();
					current_state = 306;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 296;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 303;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(297):
				if(occur_event == 10)
				{
					event_10();
					current_state = 306;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 304;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(298):
				if(occur_event == 4)
				{
					event_4();
					current_state = 306;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 305;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(299):
				if(occur_event == 30)
				{
					event_30();
					current_state = 307;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 299;
				}
				if(occur_event == 10)
				{
					event_10();
					current_state = 207;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 299;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(300):
				if(occur_event == 10)
				{
					event_10();
					current_state = 173;
				}
				if(occur_event == 16)
				{
					event_16();
					current_state = 307;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 300;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 159;
				}
				break;
			case(301):
				if(occur_event == 10)
				{
					event_10();
					current_state = 211;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 307;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(302):
				if(occur_event == 10)
				{
					event_10();
					current_state = 206;
				}
				if(occur_event == 4)
				{
					event_4();
					current_state = 237;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 302;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 59;
				}
				break;
			case(303):
				if(occur_event == 30)
				{
					event_30();
					current_state = 308;
				}
				if(occur_event == 20)
				{
					event_20();
					current_state = 303;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 303;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(304):
				if(occur_event == 10)
				{
					event_10();
					current_state = 308;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 304;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(305):
				if(occur_event == 4)
				{
					event_4();
					current_state = 308;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 305;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 14;
				}
				break;
			case(306):
				if(occur_event == 22)
				{
					event_22();
					current_state = 308;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
			case(307):
				if(occur_event == 10)
				{
					event_10();
					current_state = 226;
				}
				if(occur_event == 22)
				{
					event_22();
					current_state = 307;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 18;
				}
				break;
			case(308):
				if(occur_event == 22)
				{
					event_22();
					current_state = 308;
				}
				if(occur_event == 34)
				{
					event_34();
					current_state = 0;
				}
				break;
		}//fim switch
		occur_event = -1;
	}//fim while(1)
}//fim main

//Tratamento da Interrupção da porta P1
//--------------------------------------------------------------
//--------------------------------------------------------------
#pragma vector=PORT1_VECTOR
__interrupt void RTI_PORT1(void)
{
	if(P1IFG&BIT0)	//verifica se P1.0 foi presionado
	{
		P1IFG&=~BIT0;		//apaga o flag
		buffer[n_buffer]=E0;	//Atribuir evento a P1.0
		n_buffer++;
	}
	if(P1IFG&BIT1)	//verifica se P1.1 foi presionado
	{
		P1IFG&=~BIT1;		//apaga o flag
		buffer[n_buffer]=E1;	//Atribuir evento a P1.1
		n_buffer++;
	}
	if(P1IFG&BIT2)	//verifica se P1.2 foi presionado
	{
		P1IFG&=~BIT2;		//apaga o flag
		buffer[n_buffer]=E2;	//Atribuir evento a P1.2
		n_buffer++;
	}
	if(P1IFG&BIT3)	//verifica se P1.3 foi presionado
	{
		P1IFG&=~BIT3;		//apaga o flag
		buffer[n_buffer]=E3;	//Atribuir evento a P1.3
		n_buffer++;
	}
	if(P1IFG&BIT4)	//verifica se P1.4 foi presionado
	{
		P1IFG&=~BIT4;		//apaga o flag
		buffer[n_buffer]=E4;	//Atribuir evento a P1.4
		n_buffer++;
	}
	if(P1IFG&BIT5)	//verifica se P1.5 foi presionado
	{
		P1IFG&=~BIT5;		//apaga o flag
		buffer[n_buffer]=E5;	//Atribuir evento a P1.5
		n_buffer++;
	}
	if(P1IFG&BIT6)	//verifica se P1.6 foi presionado
	{
		P1IFG&=~BIT6;		//apaga o flag
		buffer[n_buffer]=E6;	//Atribuir evento a P1.6
		n_buffer++;
	}
	if(P1IFG&BIT7)	//verifica se P1.7 foi presionado
	{
		P1IFG&=~BIT7;		//apaga o flag
		buffer[n_buffer]=E7;	//Atribuir evento a P1.7
		n_buffer++;
	}
	if(P1IFG&BIT8)	//verifica se P1.8 foi presionado
	{
		P1IFG&=~BIT8;		//apaga o flag
		buffer[n_buffer]=E8;	//Atribuir evento a P1.8
		n_buffer++;
	}
	if(P1IFG&BIT9)	//verifica se P1.9 foi presionado
	{
		P1IFG&=~BIT9;		//apaga o flag
		buffer[n_buffer]=E9;	//Atribuir evento a P1.9
		n_buffer++;
	}
	if(P1IFG&BIT10)	//verifica se P1.10 foi presionado
	{
		P1IFG&=~BIT10;		//apaga o flag
		buffer[n_buffer]=E10;	//Atribuir evento a P1.10
		n_buffer++;
	}
	P1IFG=0;
}


//Configuração de perifericos
//--------------------------------------------------------------
//--------------------------------------------------------------
void config_clk(void)	//configura o clock
{
	//O clock foi configurado a partir do DCO para aprox SMCLK=9,8Mhz
	DCOCTL = 0x00;
	__delay_cycles(100000);
	DCOCTL = MOD0 + MOD1 + MOD2 + MOD3 + MOD4 + DCO0;
	BCSCTL1 = XT2OFF + DIVA_0 + RSEL1 + RSEL2 + RSEL3;
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void config_timer(void)	//configura o timer
{
	//Configura o timer se necessário
	//para este caso será utilizado o Timer A com temporização de eventos
	//f_ref aprox = (VLOCLK)12e3/4 = 3kHz
	//TASSEL_1 -- ACLK
	//ID_2 -- Divide - /4
	//MC_1 -- contagem até TACCR0
	TACTL = TASSEL_1 + ID_2 + MC_1;
	BCSCTL3 |= LFXT1S1;	//coloca como fonte de clk o VLOCLK ao invés do cristal oscilador externo
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void config_io(void)	//configura entradas e saídas
{
	//Por default a porta 1 será considerada entrada e a porta 2 saída
	P1DIR = 0;		//toda a porta P1 como entrada
	P1REN |= BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7;	//habilita resistores de pull(up/down)
	P1OUT |= BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7;	//pull UP
	P1IE  |= BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7;	//habilita interrupção das entradas P1
	P1IES |= BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7;	//a borda de descida que provoca interrupção (descida = 1 - subida = 0)
	//P1IES &= ~(BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7);	//a borda de subida que provoca interrupção (descida = 1 - subida = 0)
	P1IFG = 0;			//Apaga o Flag da interrupção de todas as entradas
	P2SEL &= ~(BIT6 | BIT7); 					 //Bit 6 e 7 do P2 como IO 
	P2DIR |= BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7;	//toda a porta P2 como saída
	P2OUT = 0;			//todas as saídas em nível lógico 0
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void tempo_ms(unsigned int tempo)	//Função de temporização do timer A
{
	TACTL|= TACLR;		//zera o timer A
	TACCR0 =3*tempo;	//especifica tempo de estouro
	TACTL &= ~TAIFG;	//zera o Flag do estouro do Timer

//--------------------------------------------------------------
//--------------------------------------------------------------
//Funções para a sequência operacional dos eventos
void event_1(void)	//Sequência operacional para o evento 1
{
}
void event_3(void)	//Sequência operacional para o evento 3
{
}
void event_7(void)	//Sequência operacional para o evento 7
{
}
void event_9(void)	//Sequência operacional para o evento 9
{
}
void event_13(void)	//Sequência operacional para o evento 13
{
}
void event_15(void)	//Sequência operacional para o evento 15
{
}
void event_19(void)	//Sequência operacional para o evento 19
{
}
void event_21(void)	//Sequência operacional para o evento 21
{
}
void event_23(void)	//Sequência operacional para o evento 23
{
}
void event_25(void)	//Sequência operacional para o evento 25
{
}
void event_2(void)	//Sequência operacional para o evento 2
{
	gerar_evento=1;
}
void event_4(void)	//Sequência operacional para o evento 4
{
	gerar_evento=1;
}
void event_8(void)	//Sequência operacional para o evento 8
{
	gerar_evento=1;
}
void event_10(void)	//Sequência operacional para o evento 10
{
	gerar_evento=1;
}
void event_14(void)	//Sequência operacional para o evento 14
{
	gerar_evento=1;
}
void event_16(void)	//Sequência operacional para o evento 16
{
	gerar_evento=1;
}
void event_20(void)	//Sequência operacional para o evento 20
{
	gerar_evento=1;
}
void event_22(void)	//Sequência operacional para o evento 22
{
	gerar_evento=1;
}
void event_24(void)	//Sequência operacional para o evento 24
{
	gerar_evento=1;
}
void event_30(void)	//Sequência operacional para o evento 30
{
	gerar_evento=1;
}
void event_34(void)	//Sequência operacional para o evento 34
{
	gerar_evento=1;
}
