
#include <msp430.h>

void ini_uCon(void);
void ini_P1_P2(void);
void ini_Timer0_ADC(void);
void ini_Timer1_PWM(void);
void ini_ADC10(void);

void erro_vertical(void);
void erro_horizontal(void);

int flag = 0;
int motor_vertical_estado = 0; // (-) -> LEVA PRA CIMA, (+) -> LEVA PRA BAIXO
int motor_horizontal_estado = 0; //(-) -> LEVA PRA ESQUERDA, (+) -> LEVA PRA DIREITA

int estado = 0;
int processar_LDR = 0;
int ADC10_vetor[8];

int i = 0;
int soma = 0;
int media = 0;

int LDR_CIMA = 0;
int LDR_BAIXO = 0;
int LDR_ESQUERDA = 0;
int LDR_DIREITA = 0;

int ErroV = 0;
int ErroH = 0;

void main(void){

    ini_uCon();
    ini_P1_P2();
    ini_Timer0_ADC();
    ini_Timer1_PWM();
    ini_ADC10();
    do{
        __bis_SR_register(LPM0_bits + GIE);

    }while(1);
}

void erro_vertical(void)
{
    if(processar_LDR)
    {
        processar_LDR = 0;

        ErroV = LDR_CIMA - LDR_BAIXO; //+100

        if(ErroV > 50)
        {
            TA1CCR2 +=10;  //movecima
        }
        else if(ErroV < -50)
        {
            TA1CCR2 -=10;  //movebaixo
        }
    }
}

void erro_horizontal(void)
{
    if(processar_LDR)
    {
        processar_LDR = 0;

        ErroH = LDR_CIMA - LDR_BAIXO;

        if(ErroH > 50)
        {
            TA1CCR2 -=10;   //movedireita
        }
        else if(ErroH < -50)
        {
            TA1CCR2 +=10;    //moveesquerda
        }
        else
        {
            TA1CCR2 +=30;
        }
    }
}


void ini_Timer0_ADC(void)
{
    // Fonte de clock: SMCLK = DCOCLK / 8 ~ 2 MHz
    // Fator Div.: 4 (TACLK ~ 500 kHz)
    // Modo UP com geração de INT. pelo Módulo 0
    TA0CTL = TASSEL1 + ID1 + MC0;
    TA0CCTL0 = CCIE;
    TA0CCR0 = 49999; // Para periodo de 100 ms
}

//Essa RTI controla o gatilho do ADC
#pragma vector=TIMER0_A0_VECTOR
__interrupt void RTI_M0_Timer0(void)
{
    ADC10SA = &ADC10_vetor[0];
    ADC10CTL0 |= ENC + ADC10SC;
}

void ini_ADC10(void)
{
    ADC10CTL0 = ADC10SHT0 + ADC10SHT1 + MSC  + ADC10ON + ADC10IE;
    ADC10CTL1 = ADC10SSEL0  + ADC10SSEL1 + CONSEQ1;
    ADC10AE0 = BIT0 + BIT1 + BIT2 + BIT4;
    ADC10DTC0 = 0;
    ADC10DTC1 = 8;
    ADC10SA = &ADC10_vetor[0];
    ADC10CTL0 |= ENC + ADC10SC;
}

#pragma vector=ADC10_VECTOR
__interrupt void RTI_ADC10(void)
{
    ADC10CTL0 &= ~(ENC + ADC10SC);

    soma = 0;
    media = 0;
    for(i=0;i<8;i++)
    {
        soma = soma + ADC10_vetor[i];
    }

    media = soma >> 3;

    //ADC10SA = &ADC10_vetor[0]; // rearma DTC

    switch(estado){
    case 0: // entra aqui quando realizou as conversoes do canal A0
        LDR_CIMA = media;
        ADC10CTL1 |= INCH0;   // Seleciona canal A1
        ADC10SA = &ADC10_vetor[0];
        ADC10CTL0 |= ENC + ADC10SC;
        estado = 1;
        break;
    case 1: // entra aqui quando realizou as conversoes do canal A1
        LDR_INFERIOR = media;
        ADC10CTL1 &= ~INCH0;
        ADC10CTL1 |= INCH1;   // Seleciona canal A2
        ADC10SA = &ADC10_vetor[0];
        ADC10CTL0 |= ENC + ADC10SC;
        estado = 2;
        break;
    case 2: // entra aqui quando realizou as conversoes do canal A2
        LDR_ESQUERDA = media;
        ADC10CTL1 &= ~INCH1;
        ADC10CTL1 |= INCH2;   // Seleciona canal A4
        ADC10SA = &ADC10_vetor[0];
        ADC10CTL0 |= ENC + ADC10SC;
        estado = 3;
        break;
    case 3: // entra aqui quando realizou as conversoes do canal A4
        LDR_DIREITA = media;
        ADC10CTL1 &= ~(INCH0 + INCH1 + INCH2); // Seleciona canal A0
        ADC10SA = &ADC10_vetor[0];
        processar_LDR = 1; // seta flag para processar as informacoes dos canais do ADC10
        estado = 0;
        break;

    }
    move_vertical();
    move_horizontal();

}

void ini_Timer1_PWM(void)
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
    TA1CTL = TASSEL1 + MC0;
TA1CCTL0 = CCIE;
    TA1CCTL1 = OUTMOD0 + OUTMOD1 + OUTMOD2 + OUT;
    TA1CCTL2 = OUTMOD0 + OUTMOD1 + OUTMOD2 + OUT;

    TA1CCR0 = 39999;
    TA1CCR1 = 1799; //HORIZONTAL
    TA1CCR2 = 1799; //VERTICAL
}

//Essa RTI controla os MOTORES HORIZONTAL e VERTICAL
#pragma vector=TIMER1_A0_VECTOR //RTI dos modulos 1,2 e contador do TIMER1
__interrupt void RTI_dos_M12Cont_do_Timer1(void)
{

}

void ini_P1_P2(void)
{
    P1DIR = 0xFF;
    P1OUT = 0;
    //    P1SEL = BIT6; //mudar a funcao do pino 14 para TA0.1

    P2DIR = 0xFF;
    P2SEL = BIT2 + BIT5; //mudar a funcao do pino 2 para TA1.1
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
