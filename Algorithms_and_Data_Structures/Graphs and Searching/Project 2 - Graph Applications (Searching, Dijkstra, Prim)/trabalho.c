#include"trabalho.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//FUNÇOES DO GRAFO

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool exist_vertex(grafo* g,int v){		//verifica se um vertice existe
	node* n=g->head;
	while(n!=NULL){
		if(n->vertex==v){
			return true;
		}
		n=n->bellow;
	}
	return false;	
}
bool exist_edge(node* v,int e){   // verifica se uma aresta existe
	edge* n=v->head;
	while(n!=NULL){
		if(n->vertex==e){
			return true;
		}
		n=n->next;
	}
	return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void new_vertex(grafo* g,int value){  // cria uma nova estrutura do tipo node
	node*n =(node*)malloc(sizeof(node));	
	if(g->size==0){		//1º caso o grafo nao ter nenhum vertice
		n->vertex=value;
		n->size=0;
		n->head=NULL;
		n->tail=NULL;
		n->up=NULL;
		n->bellow=NULL;
		g->head=n;
		g->tail=n;
	}
	else{				//2º caso o grafo ja tenha vertices
		n->vertex=value;
		n->size=0;
		n->head=NULL;
		n->tail=NULL;
		n->up=g->tail;
		g->tail->bellow=n;
		n->bellow=NULL;
		g->tail=n;	
	}
	g->size++;
}
void insert_vertex(grafo* g,int value){ // inserir um vertice, sempre inserindo o vertice no final da lista
	bool a=exist_vertex(g,value); //verificar se o vertice ja existe no grafo	
	if(a==false){
		new_vertex(g,value);
	}
	else{
		printf("IMPOSSIVEL INSERIR O VERTICE, O MESMO JA EXISTE!\n");
	}
}
void new_edge(node* n,int v,int p){     // cria uma nova estrutura do tipo edge 
	edge* e=(edge*)malloc(sizeof(edge));
	if(n->size==0){	
		e->peso=p;
		e->vertex=v;
		e->prev=NULL;
		e->next=NULL;
		n->head=e;
		n->tail=e;
	}
	else{
		e->peso=p;
		e->vertex=v;
		e->prev=n->tail;
		e->next=NULL;
		n->tail->next=e;
		n->tail=e;
	}
	n->size++;
}
void insert_edge(grafo* g,int v, int e,int p){	// inserir uma aresta, sempre inserindo a aresta no final da lista
	if(v!=e && p>0){	// verifica se a aresta que vai ser inserida sera um laço
		bool a=exist_vertex(g,v);
		bool b=exist_vertex(g,e);
		if(a==true && b==true){ 	//verifica se os vertices existem
			node* v1=search_vertex(g,v);
			bool c=exist_edge(v1,e);	// verifica se ja existe uma aresta entre os vertices
			if(c==false){
				new_edge(v1,e,p);
				new_edge(search_vertex(g,e),v,p);			
			}
			else{
				printf("IMPOSSIVEL INSERIR A ARESTA, POIS A MESMA JA EXISTE!\n");
			}
		}
		else{
			if(a==false && b==false){
				printf("IMPOSSIVEL INSERIR A ARESTA,POIS OS VERTICES NAO EXISTEM!\n");
			}
			else if(a==true && b==false){
				printf("IMPOSSIVEL INSERIR A ARESTA,POIS O VERTICE %d NAO EXISTE!\n",e);
			}
			else{
				printf("IMPOSSIVEL INSERIR A ARESTA,POIS O VERTICE %d NAO EXISTE!\n",v);
			}
		}
	}
	else{
		if(v==e){
			printf("IMPOSSIVEL INSERIR UMA ARESTA LAÇO!\n");
		}
		else{
			printf("IMPOSSIVEL INSERIR UMA ARESTA COM PESO MENOR QUE ZERO!\n");
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
node* search_vertex(grafo* g,int v){    //caso um vertice exista entao procuramos pelo seu endereço
	node* n=g->head;
	while(n->vertex!=v){
		n=n->bellow;
	}
	return n;
}
edge* search_edge(node* n,int a){	//caso uma aresta exista entao procuramos pelo seu endereço
	edge* e=n->head;
	while(e->vertex!=a){
		e=e->next;
	}
	return e;
} 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void r_edge(node* n,edge* e){ // apaga a estrutura edge
	if(e->prev==NULL && e->next==NULL){  //UNICA ARESTA,ELA É O INICIO E FIM DA LISTA
		n->head=NULL;
		n->tail=NULL;
		n->size--;
		free(e);
	}
	else if(e->prev==NULL && e->next!=NULL){  //ARESTA NO INICIO DA LISTA  
		n->head=e->next;
		e->next->prev=NULL;
		n->size--;
		free(e);
	}
	else if(e->next==NULL && e->prev!=NULL){  //ARESTA NO FIM DA LISTA
		n->tail=e->prev;
		e->prev->next=NULL;
		n->size--;
		free(e);
	}
	else/*(e->prev!=NULL && e->next!=NULL)*/{   // ARESTA NO MEIO DA LISTA
		e->prev->next=e->next;
		e->next->prev=e->prev;
		n->size--;
		free(e);
	}
}
void remove_edge(grafo*g,int v1,int v2){  // Remove aresta
	if(v1!=v2){	//verifica se a aresta a ser removida é do tipo laço
		bool a=exist_vertex(g,v1);  
		bool b=exist_vertex(g,v2);	
		if(a==true && b==true){ // verifica se os vertices que nao serao mais incidentes existem
			node* n1=search_vertex(g,v1); //busca pelo vertice
			bool c=exist_edge(n1,v2); // verifica se os vertices sao incidentes
			if(c==true){  // aresta entre os vertices existem, entao remove-se as arestas nos dois vertices
				edge* e1=search_edge(n1,v2);
				r_edge(n1,e1);
				node* n2=search_vertex(g,v2);
				edge* e2=search_edge(n2,v1);
				r_edge(n2,e2);	
			}
			else{
				printf("IMPOSSIVEL REMOVER ARESTA, ELA NAO EXISTE!\n");
			}
		}
		else{
			if(a==false && b==false){
				printf("IMPOSSIVEL REMOVER ARESTA ENTRE OS VERTICES, POIS OS VERTICES NAO EXISTEM!\n");
			}
			else if(a==true && b==false){
				printf("IMPOSSIVEL REMOVER A ARESTA ENTRE OS VERTICES, POIS O VERTICE %d NAO EXISTE!\n",v2);
			}
			else{
				printf("IMPOSSIVEL REMOVER A ARESTA ENTRE OS VERTICES, POIS O VERTICE %d NAO EXISTE!\n",v1);
			}
		}
	}
	else{
		printf("IMPOSSIVEL REMOVER ARESTA, ELA NAO EXISTE!\n");
	}
}
void r_vertex(grafo* g,node* n){  // apaga a estrutura node
	if(n->up==NULL && n->bellow==NULL){  //UNICO VERTICE, INICIO E FIM DA LISTA
		g->head=NULL;
		g->tail=NULL;
		g->size--;
		free(n);
	}
	else if(n->up==NULL && n->bellow!=NULL){  //VERTICE NO INICIO DA LISTA  
		g->head=n->bellow;
		n->bellow->up=NULL;
		g->size--;
		free(n);
	}
	else if(n->bellow==NULL && n->up!=NULL){  //VERTICE NO FIM DA LISTA
		g->tail=n->up;
		n->up->bellow=NULL;
		g->size--;
		free(n);
	}
	else/*(n->up!=NULL && n->bellow!=NULL)*/{   // VERTICE NO MEIO DA LISTA
		n->up->bellow=n->bellow;
		n->bellow->up=n->up;
		g->size--;
		free(n);
	}
}
void remove_vertex(grafo *g,int v){ //remove o vertice
	bool a=exist_vertex(g,v);		
	if(a==true){		//verifica se o vertice a ser removido existe
		node* n=search_vertex(g,v); //procura pelo vertice
		edge* e=n->head;			// verifica se o vertice tem arestas e remove todas antes de apagar o vertice
		int x;
		while(e!=NULL){
			x=e->vertex;
			e=e->next;
			remove_edge(g,x,v);		//funçao que remove arestas
		}
		r_vertex(g,n);				//apos remover todas as arestas, chama a funçao que remove o vertice
	}
	else{
		printf("IMPOSSIVEL REMOVER POIS O VERTICE NAO EXISTE!\n");
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_grafo(grafo* g){ // IMPRIMIR O GRAFO COMPLETO	
	node* n=g->head;
	edge* e=NULL;
	if(n!=NULL){
		e=n->head;
	}
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	if(g->size==0){	
		printf("GRAFO NULO\n");
	}
	while(n!=NULL){
		printf("[%d/%d]",n->vertex,n->size);
		while(e!=NULL){
			printf("->");
			printf("(%d/%d)",e->vertex,e->peso);
			e=e->next;
		}
		printf("\n");
		n=n->bellow;
		if(n!=NULL){
			e=n->head;
		}
		
	}
	printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
grafo* new_grafo(){  //alocar memoria para uma estrutura grafo
	grafo* g = (grafo*) malloc(sizeof(grafo));
	g->size=0;
	g->head=NULL;
	g->tail=NULL;
	return g;
}
void free_grafo(grafo *g){  // desaloca memoria do grafo todo, apagando a estrutura sem deixar memoria alocada!
	if(g->size!=0){
		node* n=g->head;
		int x;
		while(n!=NULL){
			x=n->vertex;
			n=n->bellow;
			remove_vertex(g,x);
		}
		free(g);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int degree(grafo* g,int v){ // função que retorna o grau de um vértice
	if(exist_vertex(g,v)==true){
		node* n=search_vertex(g,v);
		printf("O grau do vértice %d é %d\n",v,n->size);
	}
	else{
		printf("O vértice informado não existe!\n");
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// FUNÇOES DO VECTOR 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector* new_vector(){      			   // Aloca memória para uma estrutura do tipo vector, faz o head e tail apontar para NULL 	
	vector* v = (vector*) malloc(sizeof(vector));
	v->size=0;
	v->head=NULL;
	v->tail=NULL;
	return v;
}
void free_vector(vector* v){		// libera a memoria de todos os nós e do vector	
	if(v->size!=0){
		elem*n=v->head;
		elem*x=NULL;
			while(n->next!=NULL)
			{
				x=n;
				n=n->next;
				free(x);
			}
			free(n);			
			free(v);
	}		
	else{
		free(v);
	}
}
void vector_push_front(vector* v,node* end,int vert,int p,int d,int f,int c){ // inserir no inicio
	elem* n=(elem*) malloc(sizeof(elem));
	if(v->size==0){		// lista esta vazia
		v->head=n;
		v->tail=n;
		n->next=NULL;
		n->prev=NULL;
		n->end=end;
		n->v=vert;
		n->p=p;
		n->d=d;
		n->f=f;
		n->c=c;
		v->size++;	
	}
	else{               // lista com elementos
		n->next=v->head;
		n->prev=NULL;
		v->head->prev=n;
		v->head=n;
		n->end=end;
		n->v=vert;
		n->p=p;
		n->d=d;
		n->f=f;
		n->c=c;
		v->size++;
	}
}
void vector_push_back(vector* v,node* end,int vert,int p,int d,int f,int c){  //inserir no fim
	elem* n=(elem*) malloc(sizeof(elem));
	if(v->size==0){		// lista esta vazia
		v->head=n;
		v->tail=n;
		n->next=NULL;
		n->prev=NULL;
		n->end=end;
		n->v=vert;
		n->p=p;
		n->d=d;
		n->f=f;
		n->c=c;
		v->size++;
	}
	else{               // lista com elementos
		n->next=NULL;
		n->prev=v->tail;
		v->tail->next=n;
		v->tail=n;
		n->end=end;
		n->v=vert;
		n->p=p;
		n->d=d;
		n->f=f;
		n->c=c;
		v->size++;
	}				
}
void vector_pop_back(vector* v){ // remove no fim
	if(v->size==1){
		elem*n=v->head;
		v->head=NULL;
		v->tail=NULL;
		free(n);
		v->size--;	
	}
	else{
		elem*n=v->tail;
		v->tail=n->prev;
		v->tail->next=NULL;
		free(n);		
		v->size--;
	}				
}
void vector_pop_front(vector* v){ // remove no inicio
	if(v->size==1){
		elem*n=v->head;
		v->head=NULL;
		v->tail=NULL;
		free(n);
		v->size--;	
	}
	else{
		elem*n=v->head;
		v->head=n->next;
		v->head->prev=NULL;
		free(n);		
		v->size--;
	}					
}
bool vector_empty(vector* v){ //verifica se o vector esta vazio
	if(v->size!=0){
		return false;
	}
	else{
		return true;
	}
}
elem* vector_search(vector* v,int vert){ // funçao de busca de um elemento
	elem* n=v->head;
	while(n->v!=vert){
		n=n->next;
	}
	return n;

}
elem* vector_head(vector* v){  // retorna o inicio do vector
	return v->head;
}
elem* vector_tail(vector* v){ //retorna o fim do vector
	return v->tail;
}
int vector_white_search(vector* v){ // verifica se tem elemento marcado em branco no vector
	elem* n=v->head;
	for(int i=0; i<(v->size); i++){
		if(n->c==0){
			return n->v;
		}
		n=n->next;
	}
	return -1;
}
void vector_print_dfs(vector* v){  // funçao para imprimir a busca em profundidade
	elem* n=v->head; 
	printf("------------------------------------------------------------------\n");
	printf("Vértice		Descoberta		Finalização 	  Pai\n"); 
	printf("------------------------------------------------------------------\n");	
	while(n!=NULL){
	    printf("%d		%d		        %d          	  %d\n",n->v,n->d,n->f,n->p);
			printf("------------------------------------------------------------------\n");
		n=n->next;
	}

}
void vector_print_bfs(vector* v){ // funçao para imprimir a busca em largura
	elem* n=v->head; 
	printf("------------------------------------------\n");
	printf("Vértice		Pai		Distância\n"); 
	printf("------------------------------------------\n");
	while(n!=NULL){
	    printf("%d		%d		%d\n",n->v,n->p,n->d);
		printf("------------------------------------------\n");
		n=n->next;
	}

}
void vector_print_prim(vector* v){ //funçao para imprimir  a arvore geradora minima
	elem* n=v->head; 
	printf("------------------------------------------\n");
	printf("Vértice		Pai		key\n"); 
	printf("------------------------------------------\n");
	while(n!=NULL){
	    printf("%d		%d		%d\n",n->v,n->p,n->d);
		printf("------------------------------------------\n");
		n=n->next;
	}

}
void vector_print_d(vector* v){ //funçao para imprimir  a arvore de caminho  minimo
	elem* n=v->head; 
	printf("------------------------------------------\n");
	printf("Vértice		Pai		Distância\n"); 
	printf("------------------------------------------\n");
	while(n!=NULL){
	    printf("%d		%d		%d\n",n->v,n->p,n->d);
		printf("------------------------------------------\n");
		n=n->next;
	}

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dfs(vector* aux,int* f,int v){ // funçao recursiva do busca em profundidade
	elem* raiz=vector_search(aux,v);  //  busca o vertice inicial
	raiz->c=1;						  //marca como visitado
	raiz->d=*f;						  //marca a descoberta
	edge* e=raiz->end->head;		  // pega suas arestas
	while(e!=NULL){  // percoremos as arestas
		elem* a=vector_search(aux,e->vertex); // busca a aresta e verificamos se ja foi visitada	
		if(a->c == 0){          // caso nao foi visitada chamamos a funçao que visita recursivamente
			a->p=raiz->v;
			*f=(*f)+1;
			dfs(aux,f,e->vertex);	
		}
		e=e->next;
	}
	*f=(*f)+1;     
	raiz->f=*f;    // marca o tempo de finalizaçao
	raiz->c=-1;		//marca o vertice como finalizado
}	
void depth_first_search(grafo *g){ // funçao de busca em profundidade
	if((g->size)>0){
		vector* vectoraux=new_vector();		//vetor auxiliar que armazenara todos os vertices
		node*n=g->head; 					//endereço do primeiro vertice do grafo
		while(n!=NULL){						//inicializamos o vetor auxiliar inserindo todos os vertices e marcando-os como branco...
			vector_push_back(vectoraux,n,n->vertex,-1,-22,-22,0);
			n=n->bellow;	
		}
		int* f=(int*)malloc(sizeof(int)); *f=0;    //alocamos uma variavel para contar a descoberta e finalizaçao
		while(vector_white_search(vectoraux) !=-1){ // busca um vertice em branco para começar a busca
			*f=(*f)+1; 								// inicia-se a busca em profundidade 
			dfs(vectoraux,f,vector_white_search(vectoraux));  // chama a funçao que visita os vertices
		}
		free(f); //libera memoria
		vector_print_dfs(vectoraux); //imprime o resultado
		free_vector(vectoraux); // libera o vetor auxiliar														
	}
	else{
		printf("IMPOSSIVEL REALIZAR A BUSCA EM PROFUNDIDADE SEM TER VERTICES!\n");
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void breadth_first_search(grafo* g, int v){ // funçao de busca em largura
	if(exist_vertex(g,v)==true){	//funçoes de verificaçao se o vertice existe no grafo
		vector* vectoraux=new_vector();		//vetor auxiliar que armazenara todos os vertices
		vector* queue=new_vector();			//inicializamos uma estrutura do tipo fila simples

		node*n=g->head; 							//endereço do primeiro vertice do grafo
		while(n!=NULL){							//inicializamos o vetor auxiliar inserindo todos os vertices e marcando-os como branco...
			vector_push_back(vectoraux,n,n->vertex,-22,-22,-22,0);
			n=n->bellow;	
		}
		edge* e=NULL; elem* atual=NULL; elem* aux=NULL;   // inicializamos variveis que utilizaremos
		atual=vector_search(vectoraux,v); //buscamos o elemento inicial no vetor auxiliar
		atual->p=-1; //marcamos o vertice incial como pai dele -1 ele nao tendo pai no vetor auxiliar
		atual->c=1; //marcamos o vertice inicial como cinza "visitado pela primera vez" no vetor auxiliar
		atual->d=0; //marcamos o vertice incial como sua distancia da origem sendo 0 no vetor auxiliar
		vector_push_back(queue,atual->end,atual->v,atual->p,atual->d,-22,atual->c); //inserimos o vertice incial na fila.	
						
		while(vector_empty(queue)!=true){// repete enquanto a fila nao esta vazia.
			atual=vector_head(queue);
			e=atual->end->head;
			atual=vector_search(vectoraux,atual->v);
			vector_pop_front(queue);
			while(e!=NULL){ //percoremos todas as arestas do vertice inicial
				aux=vector_search(vectoraux,e->vertex);
				if(aux->c==0){
					aux->c=1;
					aux->p=atual->v;
					aux->d=((atual->d) +1);
					vector_push_back(queue,aux->end,aux->v,aux->p,aux->d,-22,aux->c); //inserimos na fila.	
				}
				e=e->next;
			}
			atual=vector_search(vectoraux,atual->v); //buscamos o vertice
			atual->c=-1;   							// marcamos como preto
		}
		vector_print_bfs(vectoraux);   //imprime o resultado da busca em largura
		free_vector(queue);				// libera memoria
		free_vector(vectoraux);	
	} 
	else{
		printf("IMPOSSIVEL REALIZAR A BUSCA EM LARGURA POIS O VERTICE INICIAL NAO EXISTE!\n");

	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int busca_indice(grafo* g,int vert){  //busca o indice do vertice no grafo
	node* n=g->head;	
	for(int i=0; i<(g->size); i++){	
		if(n->vertex==vert){
			return i;
		}
		n=n->bellow;	
	}
}
void matriz(grafo* g){   // imprimir o grafo em matriz de adjacencias
	int matriz[g->size][g->size];
	node*n=g->head; edge* e; int k;
	for(int i=0; i<(g->size); i++){   		// setar a matriz com zeros
		for(int j=0; j<(g->size); j++){
			matriz[i][j]=0;
			
		}
	}	

	n=g->head;								//marcar a matriz com os pesos nas devidas arestas.
	for(int i=0; i<(g->size); i++){	
		e=n->head;	
		while(e!=NULL){
			k=busca_indice(g,e->vertex);
			matriz[i][k]=e->peso;
			e=e->next;
		}	
		n=n->bellow;
	}

	n=g->head;							//imprimir a matriz de adjacencias
	printf("VERT|");
	for(int i=0; i<(g->size); i++){
		printf("   %.2d",n->vertex);
		n=n->bellow;
	}
	printf("\n");
	for(int i=0; i<(g->size)+1; i++){
		printf("_____");
	}
	printf("\n");

	n=g->head;
	for(int i=0; i<(g->size); i++){
		printf("%.2d  |",n->vertex);
		for(int j=0; j<(g->size); j++){
			printf("   %.2d",matriz[i][j]);
		}
		printf("\n");
		n=n->bellow;
	}	
	printf("\n");	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool grafo_connected(grafo* g){        // funçao que verifica se o grafo é conexo
	vector* vectoraux=new_vector();		//vetor auxiliar que armazenara todos os vertices
	vector* queue=new_vector();			//inicializamos uma estrutura do tipo fila simples

	node*n=g->head; 							//endereço do primeiro vertice do grafo
	while(n!=NULL){							//inicializamos o vetor auxiliar inserindo todos os vertices e marcando-os como branco...
		vector_push_back(vectoraux,n,n->vertex,-22,-22,-22,0);
		n=n->bellow;	
	}
	int v=vector_white_search(vectoraux);
	edge* e=NULL; elem* atual=NULL; elem* aux=NULL;   // inicializamos variveis que utilizaremos
	atual=vector_search(vectoraux,v); //buscamos o elemento inicial no vetor auxiliar
	atual->p=-1; //marcamos o vertice incial como pai dele -1 ele nao tendo pai no vetor auxiliar
	atual->c=1; //marcamos o vertice inicial como cinza "visitado pela primera vez" no vetor auxiliar
	atual->d=0; //marcamos o vertice incial como sua distancia da origem sendo 0 no vetor auxiliar
	vector_push_back(queue,atual->end,atual->v,atual->p,atual->d,-22,atual->c); //inserimos o vertice incial na fila.	
						
	while(vector_empty(queue)!=true){// repete enquanto a fila nao esta vazia.
		atual=vector_head(queue);
		e=atual->end->head;
		atual=vector_search(vectoraux,atual->v);
		vector_pop_front(queue);
		while(e!=NULL){ //percoremos todas as arestas do vertice inicial
			aux=vector_search(vectoraux,e->vertex);
			if(aux->c==0){
				aux->c=1;
				aux->p=atual->v;
				aux->d=((atual->d) +1);
				vector_push_back(queue,aux->end,aux->v,aux->p,aux->d,-22,aux->c); //inserimos na fila.	
			}
			e=e->next;
		}
		atual=vector_search(vectoraux,atual->v);   //buscamos o vertice
		atual->c=-1;                             //marcamos como preto
	}
	if(vector_white_search(vectoraux)==-1){   // apos realizar a busca em largura verificamos se atingimos todos os vertices
		free_vector(queue);
		free_vector(vectoraux);	
		return true;
	}
	else{
		free_vector(queue);
		free_vector(vectoraux);
		return false;
	}
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool exist_vector(vector* v,int i){ // funçao que verifica se existe o elemento no vector
	elem* n=v->head;
	while(n!=NULL){
		if(n->v==i){
			return true;
		}		
		n=n->next;
	}
	return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
elem* extract_min(vector* v){ // funçao que extrai o minino na fila de prioridade e retorna o elemento e finaliza o vertice
	elem* n=vector_search(v,vector_white_search(v)); elem* aux=n; int i=n->d;
	while(n!=NULL){
		if((n->d)< i && n->c ==0){
			i=n->d;
			aux=n;
		}
		n=n->next;
	}
	aux->c=-1;
	return aux;	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void prim(grafo*g, int v){  // funçao para arvore geradora minima
	if(grafo_connected(g)==true){ // verificamos se o grafo é conexo
		if(exist_vertex(g,v)==true){ //verificamos se o vertice inicial existe no grafo									
			vector* queue=new_vector();			//inicializamos uma estrutura do tipo fila simples
			node*n=g->head; 				//endereço do primeiro vertice do grafo
			while(n!=NULL){					//inicializamos o vetor auxiliar inserindo todos os vertices e marcando-os pai -1 e key infinito
				if(n->vertex==v){ // marcamos o vertice de origem
					vector_push_back(queue,n,n->vertex,-1,0,-22,0);
				}
				else{
					vector_push_back(queue,n,n->vertex,-1,INFINITY,-22,0);
				}
				n=n->bellow;	
			}
			edge* e=NULL; elem* atual=NULL; elem* aux=NULL;  // inicializamos variveis que utilizaremos
			while(vector_white_search(queue)!=-1){ //repete enquanto a fila esta vazia
				atual=extract_min(queue);     // extrai o minimo da fila
				e=atual->end->head; // pegamos suas arestas
				while(e!=NULL){
					aux=vector_search(queue,e->vertex);  // buscamos a aresta na fila
					if((e->peso)<(aux->d) && aux->c ==0){  			// atualizamos os pesos e pais caso necessario
						aux->p=atual->v;
						aux->d=e->peso;
					}	
					e=e->next;
				}
			}
			vector_print_prim(queue); // funçao para imprimir a arvore 
			free_vector(queue);				// libera a memoria
		}
		else{
			printf("O VERTICE INICIAL INFORMADO NÃO EXISTE!\n");
		}
	}
	else{
		printf("IMPOSSIVEL CONSTRUIR A ARVORE GERADORA MINIMA EM UM GRAFO DESCONEXO!\n");
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dijkstra(grafo* g,int v){
	if(exist_vertex(g,v)==true){
		vector* queue=new_vector();			//inicializamos uma estrutura do tipo fila simples
		node*n=g->head; 				//endereço do primeiro vertice do grafo
		while(n!=NULL){					//inicializamos o vetor auxiliar inserindo todos os vertices e marcando-os pai -1 e key infinito
			if(n->vertex==v){ // marcamos o vertice de origem
				vector_push_back(queue,n,n->vertex,-1,0,-22,0);
			}
			else{
				vector_push_back(queue,n,n->vertex,-1,INFINITY,-22,0);
			}
			n=n->bellow;
		}
		elem* atual=NULL; edge* e=NULL; elem* aux=NULL; // inicializa variaveis que utilizamos como auxiliar

		while(vector_white_search(queue)!=-1){  // retepe enquanto a ter vertice marcado como branco na fila
			atual=extract_min(queue);			// extrai o minimo da fila
			e=atual->end->head;
			while(e!=NULL){ // percorre as arestas 
				aux=vector_search(queue,e->vertex);
				if(aux->c==0 && ((atual->d) +(e->peso)) < (aux->d) ){   //atualiza na fila os pesos de menor caminho
					aux->d=((atual->d) +(e->peso));
					aux->p=atual->v;
				}
				e=e->next;
			}
		}
		vector_print_d(queue); // imprimi o vetor com a arvore de caminho minimo
		free_vector(queue);	 // desaloca memora do vetor
	}
	else{
		printf("O VERTICE INICIAL INFORMADO NÃO EXISTE!\n");
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




	

















