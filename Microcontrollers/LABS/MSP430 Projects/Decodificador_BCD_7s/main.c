#include <msp430.h> 



// Definindo constantes para os segmentos
#define     seg_a       BIT0
#define     seg_b       BIT1
#define     seg_c       BIT2
#define     seg_d       BIT3
#define     seg_e       BIT4
#define     seg_f       BIT5
#define     seg_g       BIT6
#define     seg_p       BIT7


// A partir das constantes dos segmentos, definir
// os DIGITOS

#define     ZERO    (seg_a + seg_b + seg_c + seg_d + seg_e + seg_f)
#define     UM      (seg_b + seg_c)
#define     DOIS    (seg_a + seg_b + seg_g + seg_d + seg_e)
#define     TRES    (seg_a + seg_b + seg_c + seg_d + seg_g)
#define     QUATRO  (seg_b + seg_c + seg_f + seg_g)
#define     CINCO   (seg_a + seg_f + seg_g + seg_c + seg_d)
#define     SEIS    (seg_a + seg_g + seg_c + seg_d + seg_e + seg_f)
#define     SETE    (seg_a | seg_b | seg_c)

void ini_P1_P2(void);

/**
 * main.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	ini_P1_P2();

	do{
	    // Programa principal

	    /* Passo 1: Como ler as entradas digitais P1.0-P1.2?
	     *   - Qual registrador deve ser lido? P1IN
	     *
	     *          bit    7  6  5  4  3  2  1  0
	     *         P1IN    X  X  X  X  X  Y  Y  Y
	     *      AND b-a-b  0  0  0  0  0  1  1  1 -> BIT0 + BIT1 + BIT2
	     *              -----------------------------
	     *                 0  0  0  0  0  Y  Y  Y
	     *
	     *      Operacao ->  P1IN & (BIT0 + BIT1 + BIT2) -> 0  0  0  0  0  Y  Y  Y
	     */

	    switch( P1IN & (BIT0 + BIT1 + BIT2) ){ // -> 0  0  0  0  0  Y  Y  Y
	        case 0:
	            P2OUT = ZERO;
	        break;
            case 1:
                P2OUT = UM;
            break;
            case 2:
                P2OUT = DOIS;
            break;
            case 3:
                P2OUT = TRES;
            break;
            case 4:
                P2OUT = QUATRO;
            break;
            case 5:
                P2OUT = CINCO;
            break;
            case 6:
                P2OUT = SEIS;
            break;
            case 7:
                P2OUT = SETE;
            break;
	    }

	}while(1);

}// Fim da funcao MAIN


//--------------------------------------------------

void ini_P1_P2(void){

/* Inicializacao da Porta 1
 *
 * P1.0-P1.2 - Chaves SW1-SW3 - Entradas com resistores de Pull-down
 * P1.3-P1.7 - N.C. - Saidas em nivel baixo.
 *
 * P1DIR - Configura os pinos como entrada/saida
 *
 *          bit     7  6  5  4  3  2  1  0
 *                  E  E  E  E  E  E  E  E
 *  P1DIR inicial   0  0  0  0  0  0  0  0
 *
 *                  S  S  S  S  S  E  E  E
 *  P1DIR desejado  1  1  1  1  1  0  0  0
 *
 *  P1DIR = 0xF8; ou P1DIR = BIT3 + BIT4 + BIT5 + BIT6 + BIT7;
 *
 *
 *  P1REN - Conecta os resisteres nos pinos
 *
 *          bit     7  6  5  4  3  2  1  0
 *                  -  -  -  -  -  -  -  --> R off
 *  P1REN inicial   0  0  0  0  0  0  0  0
 *
 *                  -  -  -  -  -  R  R  R
 *  P1REN desejado  0  0  0  0  0  1  1  1
 *
 *  P1REN = 0x07; ou P1REN = BIT0 + BIT1 + BIT2;
 *
 *
 *  P1OUT - Configura o estado das saidas/Funcao do resistor
 *
 *          bit     7  6  5  4  3  2  1  0
 *                 Nb Nb Nb Nb Nb Pd Pd Pd
 *  P1OUT inicial   0  0  0  0  0  0  0  0
 *
 *                 Nb Nb Nb Nb Nb Pd Pd Pd
 *  P1OUT desejado  0  0  0  0  0  0  0  0
 *
 *  P1OUT = 0x00;
 *
 *
 */
    P1DIR = 0xF8;
    P1REN = 0x07;
    P1OUT = 0x00;

/* Inicializacao Porta 2
 *
 * P2.0-P2.7 - Display - Saidas em nivel baixo
 *           -> Precisa mudar a funcal dos pinos 18 e 19!!!
 *
 * P2DIR - Direcao da Porta 2
 *
 * P2DIR = 0xFF;
 *
 * P2OUT - Saida da Porta 2
 *
 * P2OUT = 0x00;
 *
 * -->> Mudar a funcao dos Pinos 18 e 19
 *
 * P2SEL = 0x00;
 *
 *
 */
    P2DIR = 0xFF;
    P2OUT = 0x00;
    P2SEL = 0x00;
}








