#include <msp430.h> 

/* Exemplo debouncer para as chaves S2 e chave S3 (P1.5)
 * A chave S4 (P2.0) sem debouncer.
 *
 *  - Ao pressionar S2, deve-se alternar o estado do LED VM (P1.0)
 *
 *  - Ao pressionar S3, deve-se alternar o estado do LED VD (P1.6)
 *
 *  - Ao pressionar S4, deve-se alternar o estado dos LEDs VM e VD
 *
 */



void ini_P1_P2(void);
void ini_uCon(void);
void ini_TA0(void);


// -------------------------------------------------------------------


void main(void)
{
    ini_uCon();
    ini_P1_P2();
    ini_TA0();

    do{

    }while(1);
}

// -------------------------------------------------------------------


// RTI DA PORTA 1
#pragma vector=PORT1_VECTOR
__interrupt void RTI_da_Porta_1(void){

    // NAO LIMPAR FLAGS DE INTERRUPCAO

    // PASSO 1: Desabilitar int. das entradas P1.3 e P1.5

    P1IE &= ~(BIT3 + BIT5);


    // PASSO 2 - Iniciar temporizador

    TA0CTL |= MC0;  // Coloca o contador no modo UP

}

// RTI DO MODULO 0 DO TIMER 0
#pragma vector=TIMER0_A0_VECTOR
__interrupt void RTI_do_M0_do_Timer_0(void){

    // Entra aqui apos 7 ms da int. da Porta 1

    // PASSO 1: Parar o Timer0
    TA0CTL &= ~MC0;

    // PASSO 2: Verificar qual entrada provocou a int.

    switch( P1IFG & (BIT3 + BIT5)  ){
        /*
         *         bit     7  6   5  4   3  2  1  0
         *     P1IFG       X  X  Y2  X  Y1  X  X  X
         * BIT3 + BIT5 ->  0  0   1  0   1  0  0  0
         *  AND B-A-B    ---------------------------
         *                 0  0  Y2  0  Y1  0  0  0
         *
         *
         */
         case BIT3:
             // Verificar chave S2

             /*
              *          -------> P1.3
              *         |
              *          / S2
              *         |
              *        ---
              *         -
              *
              *         bit     7  6   5  4   3  2  1  0
              *      ~P1IN     /X /X  /X /X  /Y /X /X /X
              *       BIT3  ->  0  0   1  0   1  0  0  0
              *  AND B-A-B    ---------------------------
              *                 0  0   0  0  /Y  0  0  0 -> if(...)
              *
              *
              */

             if( (~P1IN) & BIT3 ){
                 P1OUT ^= BIT0; // Realiza a acao da tecla: alterna LED VM
             }

             P1IFG &= ~BIT3;

         break;

         case BIT5:
             // Verificar chave S3

             /*
              *          -------> P1.5
              *         |
              *          / S3
              *         |
              *        ---
              *         -
              *
              *         bit     7  6   5  4   3  2  1  0
              *      ~P1IN     /X /X  /Y /X  /X /X /X /X
              *       BIT5  ->  0  0   1  0   0  0  0  0
              *  AND B-A-B    ---------------------------
              *                 0  0  /Y  0   0  0  0  0 -> if(...)
              *
              *
              */

             if( (~P1IN) & BIT5 ){
                 P1OUT ^= BIT6; // Realiza a acao da tecla: alterna LED VD
             }

             P1IFG &= ~BIT5;

         break;

         default:
             // Tratar um dos eventos de int. apenas, pois o
             // outro pode ser tratado na sequencia

             if( (~P1IN) & BIT3 ){
                 P1OUT ^= BIT0; // Realiza a acao da tecla: alterna LED VM
             }

             P1IFG &= ~BIT3;
         break;

    }

    P1IE |= BIT3 + BIT5; // Habilita as interrupcoes

}

// RTI DA PORTA 2
#pragma vector=PORT2_VECTOR
__interrupt void RTI_da_PORTA_2(void){

    // CHAVE S4 SEM DEBOUNCER

    // PASSO 1: Limpar a flag de int.
    P2IFG &= ~BIT0;

    // PASSO 2: Realiza a acao de S4
    P1OUT ^= BIT3 + BIT5; // Alterna o estado dos LEDs VM e VD

}

// -------------------------------------------------------------------


void ini_uCon(void){

    WDTCTL = WDTPW | WDTHOLD; // Watchdog Timer Parado

    // Configuracoes do BCS
    // MCLK = DCOCLK ~ 16 MHz
    // ACLK = LFXT1CLK = 32768 Hz
    // SMCLK = DCOCLK / 8 ~ 2 MHz
    DCOCTL = CALDCO_16MHZ;
    BCSCTL1 = CALBC1_16MHZ;
    BCSCTL2 = DIVS0 + DIVS1;
    BCSCTL3 = XCAP0 + XCAP1;

    while(BCSCTL3 & LFXT1OF);

    __enable_interrupt();

}


void ini_P1_P2(void){

   /* CONFIG. DA PORTA 1
    *
    * P1.0 - LED VM - Saida em nivel baixo
    * P1.3 - CH_S2 - Entrada com resistor de pull-up
    * P1.5 - CH_S3 - Entrada com resistor de pull-up
    * P1.6 - LED VD - Saida em nivel baixo
    * P1.X - N.C. - Saidas em nivel baixo
    *
    *
    *
    *
    *          -------> P1.3
    *         |
    *          / S2
    *         |
    *        ---
    *         -
    *
    *          -------> P1.5
    *         |
    *          / S3
    *         |
    *        ---
    *         -
    *
    */

    P1DIR = BIT0 + BIT1 + BIT2 + BIT4 + BIT6 + BIT7;

    P1REN = BIT3 + BIT5;

    P1OUT = BIT3 + BIT5;

    P1IES = BIT3 + BIT5;

    P1IFG = 0;

    P1IE = BIT3 + BIT5;

    /* CONFIG. DA PORTA 2
     *
     * P2.0 - S4 (externa ao kit) - entrada com resistor de pull-down
     *                            - Interrupcao por borda de subida
     *         Vcc
     *         ---
     *          |
     *          |
     *           \
     *          |
     *           ------> P2.0
     *
     * P2.X - N.C. - Saidas em nivel baixo, exceto os
     *               os pinos 18 e 19 que ficam com a
     *               funcao nativa (XIN/XOUT) para que
     *               o oscilador LFXT1 se conecte ao
     *               cristal via pinos 18 e 19.
     *
     */

    P2DIR = ~BIT0;

    P2REN = BIT0;

    P2OUT = 0;

    P2IES = 0;

    P2IFG = 0;

    P2IE = BIT0;

}



void ini_TA0(void){

    /* Configuracoes iniciais do Timer0 para o Debouncer Das chaves S2 e S3
     *
     * CONTADOR
     *      - Fonte de Clock: SMCLK ~ 2 MHz
     *      - Fdiv clock: 1
     *      - Modo cont.: Inicialmente >>>> PARADO!
     *      - Int. cont.: desabilitada
     *
     * MODULO 0
     *      - Modo: Comparacao (default)
     *      - Interrupcao: Habilitada
     *      - TA0CCR0 = (SMCLK * 0.007) - 1 = 13999
     *
     */
    TA0CTL = TASSEL1; // Configura modulo CONTADOR do Timer0

    TA0CCTL0 = CCIE;  // Configura o MODULO 0 do Timer0
    TA0CCR0 = 13999;
}








