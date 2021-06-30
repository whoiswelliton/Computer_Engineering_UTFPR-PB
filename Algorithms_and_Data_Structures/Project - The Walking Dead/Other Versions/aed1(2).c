#include <stdio.h>
#include <stdlib.h>

struct lol
{
	int Linha,Coluna;
	int direcao;
};

typedef struct lol Loc;

Loc ll[250000];

int andar(int c, int col,char matriz[][c], int lin, int cont)
{
	if (matriz[lin][col+1]=='S')
	{
		return (cont);

	}
	else if (matriz[lin][col+1]=='.' && matriz[lin][col+1] != 'x' && matriz[lin][col+1] != '#')
	{
		ll[cont].direcao=1;
		matriz[lin][col+1]='R';
		matriz[lin][col]='x';
		cont++;
		ll[cont].Linha=lin;
		ll[cont].Coluna=col+1;

		andar (c, ll[cont].Coluna ,matriz, ll[cont].Linha, cont);

    }
    else
    {
        if (matriz[lin+1][col]=='S')
        {
            return (cont);

        }
        else if (matriz[lin+1][col]=='.' && matriz[lin+1][col] != 'x' && matriz[lin+1][col] != '#')
        {
            ll[cont].direcao=2;
            matriz[lin+1][col]='R';
            matriz[lin][col]='x';
            cont++;
            ll[cont].Linha=lin+1;
            ll[cont].Coluna=col;

            andar (c, ll[cont].Coluna ,matriz, ll[cont].Linha, cont);

        }
        else
        {
            if (matriz[lin][col-1]=='S')
            {
                return (cont);
            }
            else if (matriz[lin][col-1]=='.' && matriz[lin][col-1] != 'x' && matriz[lin][col-1] != '#')
            {
                ll[cont].direcao=3;
                matriz[lin][col-1]='R';
                matriz[lin][col]='x';
                cont++;
                ll[cont].Linha=lin;
                ll[cont].Coluna=col-1;

                andar (c, ll[cont].Coluna ,matriz, ll[cont].Linha, cont);

            }
            else
            {
                if (matriz[lin-1][col]=='S')
                {
                    return (cont);
                }
                else if (matriz[lin-1][col]=='.' && matriz[lin-1][col] != 'x' && matriz[lin-1][col] != '#')
                {
                    ll[cont].direcao=4;
                    matriz[lin-1][col]='R';
                    matriz[lin][col]='x';
                    cont++;
                    ll[cont].Linha=lin-1;
                    ll[cont].Coluna=col;

                    andar (c, ll[cont].Coluna ,matriz, ll[cont].Linha, cont);
                }
                else
                {
                    for (i=0;i<c;i++)
                    {
                        for (f=0;f<l;f++)
                        {
                            if(matriz[i][f] == 'R')
                            {
                            ll[0].Linha=i;
                            ll[0].Coluna=f;
                            }
                        }
                    }


                    matriz[lin][col]='x';
                    cont--;
                    if(matriz[i][f-1] == 'x')
                    {
                        matriz[i][f-1]='R';
                    }
                    else
                    {
                        if(matriz[i-1][f] == 'x')
                        {
                            matriz[i-1][f]='R';
                        }
                        else
                        {
                            if(matriz[i][f+1] == 'x')
                            {
                                matriz[i][f+1]='R';
                            }
                            else
                            {
                                else
                                {
                                if(matriz[i+1][f] == 'x')
                                    {
                                        matriz[i+1][f]='R';
                                    }
                                }
                            }
                        }
                    }
                    //matriz[ll[cont].Coluna][ll[cont].Linha]='R';

                    andar (c, ll[cont].Coluna ,matriz, ll[cont].Linha, cont);
                }
            }
        }
    }
}

int main()
{

	int l,c,i,f,LocS[2],re;

	scanf("%d %d",&l,&c);

	char matriz[l][c];

	for (i=0;i<c;i++)
	{
		scanf("%s",&matriz[i]);
	}

	for (i=0;i<c;i++)
	{
		for (f=0;f<l;f++)
		{
			if(matriz[i][f] == 'Z')
			{
				if(matriz[i+1][f]!='Z')
				{
					matriz[i+1][f] = '#';
				}
				if(matriz[i-1][f]!='Z')
				{
					matriz[i-1][f] = '#';
				}
				if(matriz[i][f+1]!='Z')
				{
					matriz[i][f+1] = '#';
				}
				if(matriz[i][f-1]!='Z')
				{
					matriz[i][f-1] = '#';
				}
			}
		}
	}


	for (i=0;i<c;i++)
	{
		for (f=0;f<l;f++)
		{
			if(matriz[i][f] == 'R')
			{
				ll[0].Linha=i;
				ll[0].Coluna=f;
			}
		}
	}

	for (i=0;i<c;i++)
	{
		for (f=0;f<l;f++)
		{
			if(matriz[i][f] == 'S')
			{
				LocS[0]=i;
				LocS[1]=f;
			}
		}
	}

	i=0;

	re = andar(c ,ll[0].Coluna ,matriz, ll[0].Linha, i);

	for(i=0;i<re;i++)
	{
		if(ll[i].direcao==1)
		{
			printf("direita\n");
		}
		else if(ll[i].direcao==2)
		{
			printf("baixo\n");
		}
		else if(ll[i].direcao==3)
		{
			printf("esquerda\n");
		}
		else if(ll[i].direcao==4)
		{
			printf("cima\n");
		}
		return(0);
	}
}

