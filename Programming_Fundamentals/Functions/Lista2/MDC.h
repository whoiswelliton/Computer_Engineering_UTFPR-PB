int MDC (int Num1,int Num2)
{
    int Div;
    int MDC;
    int Menor;

    if(Num1 < Num2)
    {
        Menor=Num1;
    }
    else
    {
        Menor=Num2;
    }
    for(Div=1;Div <=Menor;Div++)
    {
        if (Num2 % Div == 0 && Num1 % Div == 0)
        {
            MDC = Div;
        }
    }

    return(MDC);
}
