int Primos(int Num)
{
    int Qtd=0;
    int Cont;

    for(Cont=2;Cont<=Num/2;Cont++)
    {
        if(Num % Cont == 0)
        {
            Qtd++;
            break;
        }
    }
    return(Qtd);
}
int Primos1a100(int Cont)
{
    int Cont2,Qtd=0;
    for(Cont2=2;Cont2<=Cont/2;Cont++)
    {
        if(Cont % Cont2 == 0)
        {
            Qtd++;
            break;
        }
    }
    return(Qtd);
}

int Fatorial (int Num)
{

    int Cont,Fat=1;

    for(Cont=Num;Cont>1;Cont--)
    {
        Fat = Fat * Cont;
    }
    return(Fat);
}

int MDC (int Num1,int Num2)
{
    int Cont,Aux=0;

    if(Num2 > Num1)
    {
        Aux = Num1;
        Num1 = Num2;
        Num2 = Aux;
    }
    for(Cont=Num2;Cont>=1;Cont--)
    {
        if(Num2 % Cont == 0 && Num1 % Cont == 0)
        {
            return(Cont);
        }
    }
}
int MMC (int Num1,int Num2)
{
    int Cont,Aux,Cont2;

    if(Num2 > Num1)
    {
        Aux = Num1;
        Num1 = Num2;
        Num2 = Aux;
    }

    for(Cont=1;Cont<=Num1;Cont++)
    {
        for(Cont2=1;Cont2<=Num1;Cont++)
        {
            if(Num2 * Cont == Num1 * Cont2)
            {
                return(Cont);
            }
        }

    }

}

int Qtdivisores1 (int Num)
{
    int Cont;
    int Qtde=0;
    for(Cont=1;Cont<=Num;Cont++)
    {
        if(Num % Cont == 0)
        {
            Qtde++;
        }
    }
    return(Qtde);
}

int Qtdivisores2 (int Num)
{
    int Qtd=0;
    int Cont;

    for(Cont=1;Cont<=Num;Cont++)
    {
        if(Num % Cont == 0)
        {
            Qtd++;
        }
    }
    return(Qtd);
}

int mostrardivisores (int Num)
{
    int Cont;
    for(Cont=1;Cont<=Num;Cont++)
    {
        if(Num % Cont == 0)
        {
            printf("%d ",Cont);
        }
    }
}

int somardividores(int Num)
{
    int Cont,Soma=0;
    for(Cont=1;Cont<=Num;Cont++)
    {
        if(Num % Cont == 0)
        {
            Soma = Soma + Cont;
        }
    }
    return(Soma);
}

float Calculadora(int Num1,int Num2, char Opcao)
{
    float Retorno,Res;
    int Aux;

    if (Opcao == '1')
    {
        Res = Num1 + Num2;
        return(Res);
    }
    else if (Opcao == '2')
    {
        if(Num2 > Num1)
        {
            Aux = Num1;
            Num1 = Num2;
            Num2 = Aux;
        }
        Res = Num1 - Num2;
        return(Res);
    }
    else if (Opcao == '3')
    {
        Res = Num1*Num2;
        return(Res);
    }
    else if (Opcao == '3')
    {
        if(Num2 > Num1)
        {
            Aux = Num1;
            Num1 = Num2;
            Num2 = Aux;
        }
        Res = Num1/Num2;
        return(Res);
    }

}

