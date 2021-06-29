#include <stdio.h>
#include <stdlib.h>
/*
Uma indústria fabrica roupas categorizadas em masculinas, femininas e infantis. Ler a categoria
(M, F ou I) e a respectiva quantidade. Calcular:
	a) O total de produtos;
b) O percentual de produtos de cada categoria em relação ao total;
c) Validar para que seja informada uma categoria válida;
d) Parar a leitura quando informado um valor negativo para a quantidade. Ler primeiro a quantidade
e em seguida a categoria. Se informada uma quantidade negativa não ler a categoria.
*/
int main (void)
{

    char Categoria;
    int Quant;
    int Total=0,TotalM=0,TotalI=0,TotalF=0;
    float PercF,PercM,PercI;

    do
    {
        printf("Informe a quantidade ");
        scanf("%d",&Quant);
        if (Quant >0)
        {
            printf("informe a categoria: ");
            fflush(stdin);
            scanf("%c",&Categoria);
            if(Categoria=='M' || Categoria=='m')
            {
                TotalM=TotalM+Quant;
            }
            else if (Categoria=='F' || Categoria=='f')
            {
                TotalF=TotalI+Quant;
            }
            else if (Categoria == 'I' || Categoria =='i')
            {
                TotalI=TotalI+Quant;
            }

        }

    }while (Quant > 0);

    Total = TotalF+TotalM+TotalI;
    if (Total !=0)
    {
        PercF = TotalF*100/Total;
        PercI = TotalI*100/Total;
        PercM = TotalM*100/Total;
        printf("Infantil %.2f%% de %d\n",PercI,Total);
        printf("Feminino %.2f%% de %d\n",PercF,Total);
        printf("Masculino %.2f%% de %d\n",PercM,Total);
    }
    system("pause");
}
