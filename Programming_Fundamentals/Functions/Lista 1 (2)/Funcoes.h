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

int MDC (int Num1, Num2)
{
    int Cont,Cont2,Aux=0;

    if(Num2 > Num1)
    {
        Aux = Num1;
        Num1 = Num2;
        Num2 = Aux;
    }
    for(Cont=Num2;Cont>=1;Cont--)
    {
       // for(Cont2=Num1;Cont>=1;Cont--)
        {
            if(Num2 % Cont == 0 && Num1 % Cont == 0)
            {
                return(Cont);
            }
        }

    }
}

