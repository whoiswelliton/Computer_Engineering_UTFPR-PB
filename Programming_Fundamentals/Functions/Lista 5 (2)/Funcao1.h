char Quadradoperfeito(int Num)
{
    int Cont, Soma=0;
    char Retorno='n';
    for(Cont=1;Cont<=Num;Cont=Cont+2)
    {
        Soma = Soma + Cont;
        if(Soma >= Num)
        {

            break;
        }
    }
    if(Soma == Num)
    {
        Retorno = 's';
    }
    return(Retorno);
}
