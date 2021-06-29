#include<stdio.h> //biblioteca de funções
/* Programa em linguagem C para calcular a media de dois números
   Entrada:
      Numero 1
      Numero 2
   Processamento
      Média = (Número 1 + Número 2) / 2
   Saída
      Média
*/

int main (void)//função principal
{//chave de início de bloco de instruções
    printf("Cálculo da média \n");

    //declarar variáveis
    int Numero1; //reservar espaço de memória para armazenar um valor inteiro.
    int Numero2;//váriavel que identifica um endereço de memória que sera usado.
    float Media;//Media é o nome da variável

    //entrada
    printf("Informe o primeiro valor: ");
    scanf("%d",&Numero1);//armezenar valor na memória
    printf("Informe o segundo valor; ");
    scanf("%d",&Numero2);

    //processamento
    Media = (Numero1 + Numero2) / 2;

    //saída
    printf("A média é: %f \n",Media);
}//fim do bloco de instruções
