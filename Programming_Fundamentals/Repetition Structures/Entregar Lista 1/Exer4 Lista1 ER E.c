#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
4) Existem normas para determinar a potência de iluminação por metro quadrado de uma residência que
é determinada pela utilização do cômodo, de acordo com a tabela seguinte:
Utilização
Classe
Potência (por m2)
Quarto
A
15
Sala de tv
A
15
Sala de estar e jantar
B
18
Cozinha
B
18
Escritório
C
20
Banheiro
C
20

Elaborar um programa para:
Ler a classe do cômodo e as suas duas dimensões. Calcular a quantidade de lâmpadas necessárias de
acordo com a tabela anterior. Suponha quer serão utilizadas somente lâmpadas de 60 wats. Prosseguir
 a leitura enquanto informada uma entrada válida para a classe do cômodo. Se informada uma classe
 inválida não ler as dimensões do cômodo. E informar a quantidade total de lâmpadas necessárias.
Observação: o número de lâmpadas informado deverá ser inteiro, por exemplo, se o algoritmo calcular
5,6 lâmpadas é necessário informar 6 lâmpadas. Uma forma de fazer o arredondamento para cima é
utilizando a função int ceil (float num) que está na biblioteca <math.h>.
*/
