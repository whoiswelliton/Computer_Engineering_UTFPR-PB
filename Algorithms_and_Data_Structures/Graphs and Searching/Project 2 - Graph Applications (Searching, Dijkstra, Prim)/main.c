#include"trabalho.h"
int main(){
	grafo* g=new_grafo(); int i=0,v,e,p;
	insert_vertex(g,1);
	insert_vertex(g,2);
	insert_vertex(g,3);
	insert_vertex(g,4);
	insert_vertex(g,5);
	insert_vertex(g,6);
	insert_vertex(g,7);
	insert_vertex(g,8);
	insert_vertex(g,9);
	insert_vertex(g,10);

	insert_edge(g, 1, 2,7);
	insert_edge(g, 1, 4,9);
	insert_edge(g, 1, 5,10);
	insert_edge(g, 1, 6,8);
	insert_edge(g, 1, 8,9);
	insert_edge(g, 1, 10,8);
	insert_edge(g, 2, 3,4);
	insert_edge(g, 2, 4,5);
	insert_edge(g, 2, 9,9);
	insert_edge(g, 2, 10,9);
	insert_edge(g, 3, 4,1);
	insert_edge(g, 3, 5,4);
	insert_edge(g, 4, 5,3);
	insert_edge(g, 5, 6,18);
	insert_edge(g, 6, 7,9);
	insert_edge(g, 6, 8,9);
	insert_edge(g, 7, 8,3);
	insert_edge(g, 7, 9,6);
	insert_edge(g, 8, 9,4);
	insert_edge(g, 8, 10,2);
	insert_edge(g, 9, 10,2);

	do{
	printf("1. Inserir Vértices\n");
	printf("2. Inserir Arestas\n");
	printf("3. Remover Vértices\n");
	printf("4. Remover Arestas\n");
	printf("5. Visualizar Grafo\n");
	printf("6. Informar grau de um vértice\n");
	printf("7· Informar se o grafo é conexo\n");
	printf("8· Converter grafo para Matriz de Adjacência\n");
	printf("9· Caminhamento em Amplitude (Busca em Largura)\n");
	printf("10· Caminhamento em Profundidade\n");
	printf("11. Caminho Mı́nimo (Algoritmo de Dijkstra)\n");
	printf("12· Árvore Geradora Mı́nima (Algoritmo de Prim)\n");
	printf("13. Sair\n");
	scanf("%d",&i);
		if(i==1){
			printf("Digite o vértice a ser inserido!\nEX: Vert\n");
			scanf("%d",&v);
			insert_vertex(g,v);
			sleep(5);
			system("clear");
		}
		else if(i==2){
			printf("Digite quais vértices serão ligados e o peso da aresta!\nEX: Vert1 Vert2 Peso\n");
			scanf("%d",&v);
			scanf("%d",&e);
			scanf("%d",&p);
			insert_edge(g,v,e,p);
			sleep(5);
			system("clear");
		}
		else if(i==3){
			printf("Digite o vértice a ser removido!\nEX: Vert\n");
			scanf("%d",&v);			
			remove_vertex(g,v);
			sleep(5);
			system("clear");
		}
		else if(i==4){
			printf("Digite em quais vértices será removido a aresta!\nEX: Vert1 Vert2\n");
			scanf("%d",&v);				
			scanf("%d",&e);
			remove_edge(g,v,e);
			sleep(5);
			system("clear");
		}
		else if(i==5){
			sleep(3);
			system("clear");
			print_grafo(g);
		}
		else if(i==6){
			printf("Deseja saber o grau de qual vértice?\n");
			scanf("%d",&v);
			sleep(3);
			system("clear");
			degree(g,v);
			sleep(5);
			system("clear");
		}
		else if(i==7){
			sleep(3);
			system("clear");
			if(grafo_connected(g)==true){
				printf("O GRAFO É CONEXO!\n");
			}
			else{
				printf("O GRAFO NÃO É CONEXO!\n");
			}
			sleep(5);
			system("clear");
		}
		else if(i==8){
			sleep(3);
			system("clear");
			print_grafo(g);			
			matriz(g);
		}
		else if(i==9){
			printf("Digite o Vértice inicial para a busca\n");
			scanf("%d",&v);
			sleep(3);
			system("clear");
			breadth_first_search(g,v);
		}
		else if(i==10){
			sleep(3);
			system("clear");		
			depth_first_search(g);
		}
		else if(i==11){
			printf("Digite o Vértice inicial para constuir a arvore de caminho minimo!\n");
			scanf("%d",&v);
			sleep(3);
			system("clear");
			dijkstra(g,v);
		}
		else if(i==12){
			printf("Digite o Vértice inicial para contruir a arvore geradora minima!\n");
			scanf("%d",&v);
			sleep(3);
			system("clear");
			prim(g,v);
		}
		else if(i==13){
			free_grafo(g);
		}
		else{
			printf("Digite um numero correspondente a uma das opcoes!\n");
			sleep(5);
			system("clear");
		}
	}while(i!=13);
}
