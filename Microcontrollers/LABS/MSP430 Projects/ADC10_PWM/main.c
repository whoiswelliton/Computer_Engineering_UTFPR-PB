#include <msp430.h> 


void ini_uCon(void);
void ini_P1_P2(void);
void ini_ADC10(void);
void ini_Timer0_PWM_ADC(void);
void ini_Timer1_PWM_Conversor(void);

unsigned int ADC10_vetor[4], soma = 0, media = 0;
unsigned char i = 0;
long aux = 0;
/**
 * main.c
 */
void main(void)
{
    ini_uCon();
    ini_P1_P2();
    ini_ADC10();
    ini_Timer0_PWM_ADC();
    ini_Timer1_PWM_Conversor();

    do{
        // Loop funcao main
    }while(1);

}

//----------------------------------------------------------

// RTI do ADC10
#pragma vector=ADC10_VECTOR
__interrupt void RTI_ADC10(void){

    ADC10CTL0 &= ~ENC;

    soma = 0;
    for(i=0;i<4;i++){
        soma = soma + ADC10_vetor[i];
    }
    media = soma >> 2;

    /* Controlar PWM do Timer 1 - Ex.: sinal de ctrl do conversor
     *
     * - Faixa TA1CCR1: 0 (0%) a 800 (100%)     |    Faixa ADC (media): 0 a 1023
     *
     *     -> Adequacao de faixa:
     *           - Uso de variavel auxiliar (aux) para calculos
     *
     *                    aux = (media*800)/1023
     *
     *           - Tentar dividir por 1024, pois eh mais facil computacionamente. Isso vai
     *             provocar um erro de aprox. 0,1 %, mas por questoes praticas pode-se
     *             considerar valida a divisao por 1024 ao inves de 1023.
     *
     *           - Entao:
     *
     *                   aux = (long)media*800;
     *                   aux = aux >> 10;
     *
     */


    aux = (long)media*802; // Foi colocado um valor ligeiramente maior que 800 para
                           // garantir uma RC de 100%
    aux = aux >> 10;

    TA1CCR1 = (unsigned int)aux;


    ADC10SA = &ADC10_vetor[0];

    ADC10CTL0 |= ENC;
}


void ini_Timer1_PWM_Conversor(void){

    /* Sinal PWM para controle do Conversor
     *
     *    - Freq. Sinal = 10 kHz
     *
     *    - Rc ini = 0%
     *
     *    - SMCLK = 8 MHz
     *        - FDIV = 1
     *
     *    - Modo contador: UP
     *
     *    - TA0CCR0 = (8M / 10k) - 1 =  799
     *
     *    - Modo PWM = Reset/Set (modo 7)
     *
     *    - TA0CCR1 = 0; // RC = 0 %
     *
     */

    TA1CTL = TASSEL1 + MC0;

    TA1CCTL1 = OUTMOD0 + OUTMOD1 + OUTMOD2 + OUT;

    P2DIR |= BIT1; // Garante que pino sera saida digital

    P2SEL |= BIT1; // Muda a funcao de P2.1 para TA1.1

    TA1CCR0 = 799;

    TA1CCR1 = 0;

}




void ini_uCon(void){

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    /* Config. do BCS
     *
     * MCLK  -> 16 MHz
     * SMCLK ->  8 MHz
     * ACLK  -> 32768 Hz
     *
     * VLO - Nao utilizado
     * XT2 - Nao esta presente
     * LFXT1 - xtal 32k
     * DCO ~ 16 MHz
     */

    DCOCTL = CALDCO_16MHZ;
    BCSCTL1 = CALBC1_16MHZ;
    BCSCTL2 = DIVS0;
    BCSCTL3 = XCAP0 + XCAP1;

    while( BCSCTL3 & LFXT1OF);

    __enable_interrupt();

}


void ini_P1_P2(void){

    /* Inicializacao da P1
     *
     * P1.x - N.C.
     *
     */
    P1DIR = 0xFF;
    P1OUT = 0;


    /* Inicializacao da P2
     *
     * P2.x - N.C.
     *
     * Pinos 18 e 19 para LFXT1 - 32k
     *
     */
    P2DIR = 0xFF;
    P2OUT = 0;
}



void ini_ADC10(void){

    /* Inicializacao do ADC10
     *
     *   - Clock: MCLK / 3 = 16M/3 = 5,33M
     *   - Taxa conv. max.:  ~ 200 ksps
     *   - Tensao de REF:  Vcc = 3,6 V
     *   - Entrada: A5
     *   - Freq. de amostragem: 5 kHz (ta = 200 us)
     *   - Ts (Sample Time): Pot. 10 kohms
     *        -> (Rs + Ri).Ci.ln(2^11) = (10k + 2k).27pf.ln(2^11) = 2,5 us
     *            - Pior caso ADC10CLK = 5,3 MHz .:. num. ciclos = 2,5u * 5,3 M = 13,25 -> 16
     *   - Media de 4 amostras repetidas
     *       -> DTC para transf. no Modo 1 Bloco
     *
     *   - Recalculando taxa max. conv.: 5,3M / 30 = 176,7 ksps
     *
     *
     */

    ADC10CTL0 = ADC10SHT1 + MSC + ADC10ON + ADC10IE;

    ADC10CTL1 = INCH0 + INCH2 + SHS0 + ADC10SSEL1 + ADC10DIV1 + CONSEQ1;

    ADC10AE0 = BIT5;  // P1.5 para A5

    ADC10DTC0 = 0;

    ADC10DTC1 = 4;

    ADC10SA = &ADC10_vetor[0];

  //  -> Habiliar a Conversao

    ADC10CTL0 |= ENC;

}

void ini_Timer0_PWM_ADC(void){

    /* Sinal PWM para ADC10
     *
     *    - SMCLK = 8 MHz
     *        - FDIV = 1
     *
     *    - Modo contador: UP
     *
     *    - TA0CCR0 = (8M / 5k) - 1 =  1599
     *
     *    - Modo PWM = Reset/Set (modo 7)
     *
     *    - TA0CCR1 = 799; // RC ~ 50 %
     *
     */

    TA0CTL = TASSEL1 + MC0;

    TA0CCTL1 = OUTMOD0 + OUTMOD1 + OUTMOD2 + OUT;

    TA0CCR0 = 1599;

    TA0CCR1 = 799;

    /* Teste do sinal de gatilho saindo no pino 14 do uCon
        P1DIR |= BIT6;
        P1SEL |= BIT6;
    */
}

