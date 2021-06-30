#include <msp430.h>

void ini_uCon(void);
void ini_P1_P2(void);
void ini_Timer0_PWM(void);
int flag = 0;

int main(void)
{    ini_uCon();
    ini_P1_P2();
    ini_Timer0_PWM();
    do {

    } while (1);
}

//RTI dos modulos 1,2 e contador do TIMER0
#pragma vector=TIMER0_A1_VECTOR
__interrupt void RTI_dos_M12Cont_do_Timer0(void)
{
    //forma especial de fazer leitura da flag
    (void)TA0IV;//Registrador lido apenas para limpar flag de interrupcao
    /* Alterar a largura do pulso, incremento de 0.5% -> 0.02 * 0.5/100 = 0.1ms
     *  0.1ms = 0.0001s >> TA0CCR1 = (2MHz * 0.0001) - 1 = 199
     *  TA0CCR1 += 199
     */
    if (flag == 0)
    {
        if (TA0CCR1 <= 1999) {
            flag = 1;
        } else {
            TA0CCR1 += 100;
        }
    }else{
        if (TA0CCR1 >= 4199) {
            flag = 0;
        } else {
            TA0CCR1 -= 10;
        }
    }

}

void ini_Timer0_PWM(void)
{
    /*  Geracao de sinal PWM - baseado no datasheet HS422
         -Fonte do sinal de clock: SMCLK = DCOCLK / 8 ~ 2MHz

         -M0 tem funcao de ajustar o periodo (1/50Hz = 0.02s)
     *Quantas contagens para 0.02s? >> TA0CCR0 = (2MHz * 0.02) - 1 = 39999
     *Quantas
         -M1 tem funcao de ajustar a razao ciclica (0.9ms .. 2.1ms)
     *Quantas contagens para 0.9ms? >> TA0CCR1 = (2MHz * 0.0009) - 1 = 1799
     *Quantas contagens para 2.1ms? >> TA0CCR1 = (2MHz * 0.0021) - 1 = 4199
     */

    /*  Geracao de sinal PWM - baseado no datasheet do SG-90
             -Fonte do sinal de clock: SMCLK = DCOCLK / 8 ~ 2MHz

             -M0 tem funcao de ajustar o periodo (1/50Hz = 0.02s)
         *Quantas contagens para 0.02s? >> TA0CCR0 = (2MHz * 0.02) - 1 = 39999
         *Quantas
             -M1 tem funcao de ajustar a razao ciclica (0.9ms .. 2.1ms)
         *Quantas contagens para 1ms? >> TA0CCR1 = (2MHz * 0.001) - 1 = 1999
         *Quantas contagens para 2ms? >> TA0CCR1 = (2MHz * 0.002) - 1 = 3999
         */

    TA0CTL = TASSEL1 + MC0;
    TA0CCTL1 = OUTMOD0 + OUTMOD1 + OUTMOD2 + OUT + CCIE;
    TA0CCR0 = 39999;
    TA0CCR1 = 1799;
}

void ini_P1_P2(void)
{
    /*  P1.6 - Saida de PWM - Mudar funcao para TA0.1
     *  P1.x - Saida em nivel baixo
     */
    P1DIR = 0xFF;
    P1OUT = 0;
    P1SEL = BIT6; //mudar a funcao do pino 14 para TA0.1

    P2DIR = 0xFF;
    P2OUT = 0;
    //pinos 18 e 19 passam de XIN e XOUT para P2.6 e P2.7
    P2SEL &= ~(BIT6 + BIT7);
}

void ini_uCon(void) { // Configuracoes do BCS
    // MCLK = DCOCLK ~ 16 MHz
    // ACLK = LFXT1CLK = sem sinal
    // SMCLK = DCOCLK / 8 ~ 2MHz
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    DCOCTL = CALDCO_16MHZ;
    BCSCTL1 = CALBC1_16MHZ;
    BCSCTL2 = DIVS0 + DIVS1; //configurado para 2MHz
    __enable_interrupt();
}
