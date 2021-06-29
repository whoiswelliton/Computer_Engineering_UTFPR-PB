#include <stdio.h>
#define MAX_ALUNOS 1000
int main()
{
  int i, indice_melhor, n;
  int turma=1 ,vet[1000];
  int z=1;
  struct
  {
    int codigo, media;
  } alunos[MAX_ALUNOS];
  /* le numero de alunos da primeira turma */
  scanf("%d", &n);
  while (n > 0)
    {
      /* le dados dos alunos */
      for (i = 0; i < n; i++)
         scanf("%d %d", &alunos[i].codigo, &alunos[i].media);
      /* procura aluno de maior media */
      indice_melhor = 0;
      vet[0]=alunos[0].codigo;
      for (i = 1; i < n; i++)
         if (alunos[i].media == alunos[indice_melhor].media){
           vet[z]=alunos[i].codigo;
           z++;
         }
         else if (alunos[i].media > alunos[indice_melhor].media){
             indice_melhor = i;
             z=0;
             vet[z]=alunos[i].codigo;
             z++;
         }
                  /* escreve resposta */
      printf("Turma %d\n", turma++);
      for(i=0; i<z; i++){
        printf("%d ", vet[i]);
      }
        /* le numero de alunos da proxima turma */
      z=1;
      printf("\n\n");
      scanf("%d", &n);
      
    }
  return 0;
}
