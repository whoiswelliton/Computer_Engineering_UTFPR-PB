int Funcao1 (void)
{
    int Cont;
    int LimSup,Incre;

            printf("Informe o limite Superior: ");
            scanf("%d",&LimSup);
            printf("Informe o Incremento: ");
            scanf("%d",&Incre);
            for(Cont=0;Cont<=LimSup;Cont+Incre)
            {
                printf("%d\t",Cont);
            }
}
