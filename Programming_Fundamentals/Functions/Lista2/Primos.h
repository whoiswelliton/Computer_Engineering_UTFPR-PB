
//função para verificar se o numero e primo
//retornar 0 se primo e 1 se não primo

int Primo (int Num)
{
    int Qtdivisores=0;
    int Div;

    for(Div=2;Div<=Num/2;Div++)
    {
        if (Num % Div ==0)
        {
            Qtdivisores++;
            break;
        }
    }
    return(Qtdivisores);
}
