/* EXEMPLO 2 ADC10 - Medidor temperatura interna
 * Com GATILHO por HW
 *
 */

#include <msp430.h> 

void ini_uCOn(void);
void ini_P1_P2(void);
void ini_TA0_PWM(void);
void ini_ADC10(void);
/**
 * main.c
 */

void main(void)
{
    ini_uCOn();
    ini_P1_P2();
    ini_TA0_PWM();
    ini_ADC10();


    do{
       // Loop infinito

    }while(1);

}
//////////////////////////////////////////////////////////////////

#pragma vector=ADC10_VECTOR
__interrupt void RTI_do_ADC10(void){

    ADC10CTL0 &= ~ENC;

    // Processar o resultado da conv.


    ADC10CTL0 |= ENC;
}


//---------------------------------------------------------------
void ini_ADC10(void){

    /*  GATILHO POR HW - gerado pelo Timer0
     *
     * Taxa de conversao: ate 200 ksps
     * Clock:
     *   - Oscilador: ADC10OSC (3,7 - 6,3 MHz)
     *   -
     *
     * Tensao de Ref.: 2,5 V do gerador interno, saindo pelo A4
     *
     * Interrupcao habilitada
     */

       ADC10CTL0 = SREF0 + ADC10SHT1 + REFOUT + REF2_5V + REFON + ADC10ON + ADC10IE;

       ADC10CTL1 = SHS0;  // VR+ = Vref  | VR- = GND

       ADC10AE0 = BIT0 + BIT4;   // Habilita canal A0

       ADC10CTL0 |= ENC;  // Habilita convesao (gera borda de subida)

}



void ini_TA0_PWM(void){
    /* Inicializacao do Timer 0
     *
     * CONTADOR
     *      - Clock: ACLK
     *      - Fdiv: 1
     *      - Modo cont.: UP
     *      - Int. cont.: desabilitada
     *
     * MODULO 0
     *      - Funcao: Comparacao (nativa)
     *      - TA0CCR0: 32768 * 1 - 1 = 32767
     *      - Int.: desabilitada
     *
     * MODULO 1:
     *      - Vai gerar o sinal PWM
     *      - Funcao: Comparacao
     *      - Modo de saida: 7 (Reset/Set)
     *      - TA0CCR1 = 16383;
     *      - Int.: desabilitada
     *
     */

     TA0CTL = TASSEL0 + MC0;

     TA0CCTL1 = OUTMOD0 + OUTMOD1 + OUTMOD2 + OUT;

     TA0CCR0 = 32767;

     TA0CCR1 = 16383;

}



void ini_uCOn(void){

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    /* Config. do BCS
     *
     * MCLK = DCOCLK ~ 1 MHz
     * SMCLK = DCOCLK / 8 ~ 125 kHz
     * ACLK = LFXT1 = 32.768 Hz
     */

    DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;
    BCSCTL2 = DIVS0 + DIVS1;
    BCSCTL3 = XCAP0 + XCAP1;

    while( BCSCTL3 & LFXT1OF ){
       // Aguarda LFXT1 atingir a freq. XTAL
    }

    __enable_interrupt();// Config. CPU para aceitar IRQ dos perif.

}

void ini_P1_P2(void){
    /* Config. da Porta 1
     *   P1.0 - N.C.
     *   P1.x - N.C. - saidas em nivel baixo
     *
     */
    P1DIR = BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7;
    P1OUT = 0;

    /* Config. da Porta 2
     *
     *   P2.x - N.C. - saidas em nivel baixo
     *   -> Os pinos 18 e 19 permanecem com as funcoes nativas XIN/XOUT
     */
    P2DIR = BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7;
    P2OUT = 0;

}








