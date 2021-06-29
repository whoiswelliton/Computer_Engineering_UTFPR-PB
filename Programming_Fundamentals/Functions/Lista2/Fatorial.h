int Fatorial (int Num)
{
    int Fat=1,Cont;

    for(Cont=1;Cont<=Num;Cont++)
    {
        Fat*=Cont;
    }

    return(Fat);
}
