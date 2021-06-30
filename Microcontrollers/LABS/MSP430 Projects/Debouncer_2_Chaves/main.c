/*
 *  EX. de Debouncer para as chave S2 e S3 (P1.5).
 *
 */
#include <msp430.h> 


#define     LED_VM      BIT0
#define     LED_VD      BIT6
#define     CH_S2       BIT3
#define     CH_S3       BIT5


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

//----------------------------------------------------------------------------------------



// RTI DA PORTA 1
#pragma  vector=PORT1_VECTOR
__interrupt void RTI_da_Porta_1(void){

    // PASSO 1: desabilitar interrupcoes das entradas

    P1IE &= ~(BIT3 + BIT5);

    // PASSO 2: iniciar temporizador

    TA0CTL |= MC0; // Coloca o contador no modo UP

}


// RTI DA PORTA 2
#pragma  vector=PORT2_VECTOR
__interrupt void RTI_da_Porta_2(void){

    // Chave S4 sem debouncer

    P2IFG &= ~BIT0; // OBRIGATORIO: Limpar flag de int. de P2.0

    // PASSO 2: inverter o estado de ambos os leds

    P1OUT ^= BIT0 + BIT6;

}



// RTI DO MODULO 0 DO TIMER 0
#pragma  vector=TIMER0_A0_VECTOR
__interrupt void RTI_do_modulo_0_do_Timer_0(void){

    // PASSO 1:  parar temporizador
    TA0CTL &= ~MC0;

    // PASSO 2: identificar qual entrada provou a interrupcao
    switch(P1IFG & (BIT3 + BIT5) ){
        case BIT3: // Foi a entrada da chave S2 que provocou a int.
            // 1 - Verificar estado da entrada e validar tecla
            if( (~P1IN) & BIT3 ){
                P1OUT ^= BIT0; // Alterna o estado do LED VM
                P1IFG &= ~BIT3;
            }
        break;

        case BIT5:
            // 1 - Verificar estado da entrada e validar tecla
            if( (~P1IN) & BIT5 ){
                P1OUT ^= BIT6; // Alterna o estado do LED VD
                P1IFG &= ~BIT5;
            }
        break;

        default: // Se as duas entradas provocaram int. ao mesmo tempo
            // O que fazer? R.: atender uma delas primeiro. Escolhi P1.3

            // 1 - Verificar estado da entrada e validar tecla
            if( (~P1IN) & BIT3 ){
                P1OUT ^= BIT0; // Alterna o estado do LED VM
                P1IFG &= ~BIT3;
            }
        break;

    }

    P1IE |= BIT3 + BIT5;
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
    TA0CTL = TASSEL1;
    TA0CCTL0 = CCIE;
    TA0CCR0 = 13999;
}



void ini_uCon(void){

    WDTCTL = WDTPW | WDTHOLD;

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
    */
   P1DIR = BIT0 + BIT1 + BIT2 + BIT4 + BIT6 + BIT7;
   P1REN = BIT3 + BIT5;  // Resistores de P1.3 e P1.5 habilitados.
   P1OUT = BIT3 + BIT5;  // Resistores de pull-up para BIT3 e BIT5,
                         // os demais como saida em nivel logico baixo.
   P1IES = BIT3 + BIT5;  // Interrupcao por borda de descida.

   P1IFG = 0;   // Limpa as flags da P1, evitando que uma
                // interrupcao ocorra de forma indevida.

   P1IE = BIT3 + BIT5;   // Interrupcao de P1.3 e P1.5 habilitadas.

   /* CONFIG. DA PORTA 2
    *
    * P2.0 - CH_S4 - Entrada com resistor de pull-down
    *
    *        Vcc
    *        ---
    *         |
    *         |
    *          \
    *         |
    *          ----> P2.0
    *
    * P2.X - N.C. - Saidas em nivel baixo, exceto os pinos 18 e 19
    *               que se mantem nas funcoes nativas deles (XIN/XOUT)
    *
    *
    *           bit  7  6  5  4  3  2  1  0
    *        BIT0    0  0  0  0  0  0  0  1
    *       ~BIT0    1  1  1  1  1  1  1  0 -> P2DIR
    *                                     |
    *                     |-------------|  ---> Entrada
    *                     Saidas digitais
    */
   P2DIR = ~BIT0;

   P2REN = BIT0; // Liga resistor em P2.0

   P2OUT = 0x00; // Saidas em nivel baixo/Resistor de pull-down em P2.0

   P2IES = 0; // Detecta int. por borda de SUBIDA

   P2IFG = 0;

   P2IE = BIT0; // Habilita int. para P2.0 - CHAVE S4 sem debouncer
}




