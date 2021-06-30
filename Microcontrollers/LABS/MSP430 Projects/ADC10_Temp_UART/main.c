/* *******************************************************
 * Exemplo: Medidor Temperatura + UART
 *
 *      - Uso do sensor de temp. interno do ADC
 *          -> Sem usar recursos para economia de energia
 *          -> Clock: ADC10OSC - osc. interno
 *          -> Media de 8 amostras. Implica em:
 *              - Uso do DTC no modo 1 Bloco.
 *          -> Tensao de ref.: 1,5 V gerado internam.
 *          -> Gatilho por HW
 *
 *      - Timer0 config. para gerar sinal de gatilho por
 *        HW. Freq. de amostragem = 1 Hz.
 *
 *      - USCI A0 config. no modo UART.
 *          -> Apenas TX.
 *          -> 9600 bps, 8 bits dados, 1 stop bit, sem
 *             paridade.
 *
 *      - Geracao de string via sprintf(...) e envio
 *        a cada 1 segundo.
 *
 *
 * ******************************************************/




#include <msp430.h> 
#include <stdio.h>

void ini_uCOn(void);
void ini_P1_P2(void);
void ini_Timer0_PWM_Gatilho_ADC(void);
void ini_ADC10(void);
void ini_USCI_A0_UART(void);


unsigned char m = 0, i = 0, TX_data[32], tx_index = 0;
long Tc_long = 0, aux = 0, aux_dec = 0;
unsigned int ADC10_vetor[8], Tc_int = 0, Tc_dec = 0;
unsigned int media = 0, soma = 0;



/**
 * main.c
 */

void main(void)
{
    ini_uCOn();
    ini_P1_P2();
    ini_Timer0_PWM_Gatilho_ADC();
    ini_ADC10();
    ini_USCI_A0_UART();


	do{
	    // Loop infinito
	}while(1);

}

//--------------------------------------------------------------------------

// RTI de TX da UART
#pragma vector=USCIAB0TX_VECTOR
__interrupt void RTI_da_USCI_A0_TX(void){

    IFG2 &= ~UCA0TXIFG;

    if(tx_index > 31){
        tx_index = 0;
    }else{
        if(TX_data[tx_index] == '\0'){
            tx_index = 0;

        }else{
            UCA0TXBUF = TX_data[tx_index];
            tx_index++;
        }
    }
}


// RTI do ADC10
#pragma vector=ADC10_VECTOR
__interrupt void RTI_ADC10(void){

    // 1 - Desabilitar a conversao

    ADC10CTL0 &= ~ENC;

    soma = 0;
    for(i=0;i<8;i++){
        soma = soma + ADC10_vetor[i];
    }
    media = soma >> 3; // Divide por 8

    // Usar principio da base Q para multiplicacao

    Tc_long = 27066*(long)media - 18210684;

    Tc_int = Tc_long >> 16;

    aux = Tc_int << 3;    //  -> Multiplica por 2^3
    aux_dec = Tc_long >> 13;

    // -> Valores de 0 a 7, correspondendo multiplos de 0,125
    m = (unsigned char) (aux_dec - aux);

    Tc_dec = 0;
    for(i=0;i<m;i++){ //  -> multiplicacao de m*125 por meio de somas
       Tc_dec = Tc_dec + 125;
    }

    // Agora eh soh transmitir pela UART

    sprintf(&TX_data[0],"Temperatura = %d,%d graus C \n", Tc_int, Tc_dec);

    IFG2 |= UCA0TXIFG; // CPU vai para RTI de TX, a qual operacionaliza
                       // a TX de toda a string no vetor TX_data[]

    ADC10SA = &ADC10_vetor[0];
    ADC10CTL0 |= ENC;
}




void ini_USCI_A0_UART(void){
   /* USCI A0 UART CONFIG.
    *
    * Parametros da interface:
    *   - Taxa: 9600 bps
    *   - bits de dados: 8
    *   - Paridade: nenhuma
    *   - Stop bits: 1
    *
    *   - Modo: UART normal
    *   - Clock: SMCLK ~ 8MHz
    *   - Int.: TX e RX
    *
    *
    */

   // PRIMEIRO Passo
    UCA0CTL1 |= UCSWRST;

   // SEGUNDO passo
    UCA0CTL0 = 0; // Opcional

    UCA0CTL1 = UCSSEL1 + UCSWRST;

    UCA0BR0 = 0x41;  // fator de div.: 833
    UCA0BR1 = 0x03;

    UCA0MCTL = UCBRS1; // UCBRSx = 2

   // TERCEIRO Passo
    P1SEL |= BIT1 + BIT2; // Pinos 3 e 4 como RXD e TXD
    P1SEL2 |= BIT1 + BIT2;

   // QUARTO Passo
    UCA0CTL1 &= ~UCSWRST;

   // QUINTO Passo
    IFG2 &= ~UCA0TXIFG;
    IE2 |= UCA0TXIE;
}



void ini_ADC10(void){

    /* Especificacoes:
     *
     *     - Sample Time (Ts): > 30 us
     *          - Ts = 2 M * 30 u  <=  64 ciclos de ADC10CLK
     *
     *     - Clock: SMCLK ~ 8 MHz
     *         - FDiv: 4
     *         - ADC10CLK ~ 2 MHz
     *
     *     - Taxa de conversao maxima
     *         - Num. ciclos de clock do ADC usados
     *             -> 64 ciclos para amostragem
     *             -> 13 ciclos para conversao
     *         - Total ciclos = 77 ciclos
     *         - Tempo Total de Conversao - TTc:
     *             ->  (1/2M) * 77 = 38,5 us
     *         - Taxa max. conversao ~ 26 ksps
     *
     *     - Para 8 amostras consecutivas/repetidas, o tempo
     *       total de aquisicao leva:
     *         TT8c = 38,5u * 8 = 308 us
     *
     *     - Gatilho: HW - Modulo 1 do Timer 0
     *
     *     - Referencia: 0 V - 1,5 V interno
     *        - Buffer de ref.: sempre ligado, corrente nominal.
     *     - Canal entrada: A10 (sinal sensor vai para A10).
     *     - Modo canal unico
     *     - Obter 8 amostras consecutivas e calcular media
     *         - Habilitar conversoes multiplas/repetidas
     *         - DTC: modo 1 bloco
     */

    ADC10CTL0 = SREF0 + ADC10SHT0 + ADC10SHT1 + MSC + REFON + ADC10ON + ADC10IE;

    ADC10CTL1 = INCH1 + INCH3 + SHS0 + ADC10SSEL0 + ADC10SSEL1 + ADC10DIV0 + ADC10DIV1 + CONSEQ1;

    ADC10DTC0 = 0;

    ADC10DTC1 = 8;

    ADC10SA = &ADC10_vetor[0];

    // Habilita as conversoes

    ADC10CTL0 |= ENC;

}



void ini_Timer0_PWM_Gatilho_ADC(void){

    /* TIMER 0 - Gerar PWM de 1 Hz para ADC10
     *
     *      -> Clock: ACLK = 32768 Hz
     *           - Fdiv: 1
     *      -> Modo contador: UP
     *      -> Modo Saida Modulo 1: Reset/Set (Modo 7)
     *      -> TA0CCR0: 1s*32768 - 1 = 32767
     *      -> TA0CCR1: RC -> 50% -> 16383
     *
     */
    TA0CTL = TASSEL0 + MC0;

    TA0CCTL1 = OUTMOD0 + OUTMOD1 + OUTMOD2 + OUT;

    TA0CCR0 = 32767;

    TA0CCR1 = 16383;
}



void ini_P1_P2(void){

    /* PORTA 1
     *   - P1.x - N.C. - Todos como saida em nivel baixo
     */
    P1DIR = 0xFF;
    P1OUT = 0;

    /* PORTA 2
     *   - P2.x - N.C. - Todos como saida em nivel baixo
     *   - Pinos 18 e 19 com funcao XIN/XOUT
     */
    P2DIR = 0xFF;
    P2OUT = 0;
}


void ini_uCOn(void){

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    /* Config. do BCS
     *
     * MCLK = DCOCLK ~ 16 MHz
     * SMCLK = DCOCLK / 2 ~ 8 MHz
     * ACLK = LFXT1 = 32.768 Hz
     */

    DCOCTL = CALDCO_16MHZ;
    BCSCTL1 = CALBC1_16MHZ;
    BCSCTL2 = DIVS0;
    BCSCTL3 = XCAP0 + XCAP1;

    while( BCSCTL3 & LFXT1OF ){
       // Aguarda LFXT1 atingir a freq. XTAL
    }

    __enable_interrupt();// Config. CPU para aceitar IRQ dos perif.

}




