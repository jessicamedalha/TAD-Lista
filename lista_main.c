#include "lista_interface.h"
#include <stdio.h>
#include <stdlib.h>


void impr(const void *el);

int comp(const void *a1,const void *a2);

void lib(void *dado);


int comp(const void *a1,const void *a2){
	if(a1 == NULL || a2 == NULL){
		return -1;
	}
	const int *e1 = (const int *)a1;
	const int *e2 = (const int *)a2;
	if(*e1 > *e2){
		return 1;
	}
	if(*e1 < *e2){
		return -1;
	}
	if(*e1 == *e2){
		return 0;
	}
	return 1;
}

void lib(void *dado){
	free(dado);
	dado =NULL;
}

void impr(const void *el){
	if(el == NULL){
		return;
	}
	printf("Elemento: %d\n",*(const int *)el);
}



int main(void){
	int *hold ;



	printf("\n.,.,.,.Lista cria.,.,.,.\n");
	lista_t *l = lista_cria(impr, lib, comp);	
	if(!l){
		printf("Lista cria erro\n\n");
	}
	printf("Lista vazia? %d\n", lista_vazia(l));
	printf(".,.,.,.Fim Lista cria .,.,.,.\n\n");

/*

	printf(".,.,.,.Enfileirar.,.,.,.\n");

	int *aPtr;

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 5;
	fila_enfileira(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 3;
	fila_enfileira(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 6;
	fila_enfileira(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 7;
	fila_enfileira(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 0;
	fila_enfileira(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 1;
	fila_enfileira(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 2;
	fila_enfileira(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 4;
	fila_enfileira(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 8;
	fila_enfileira(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 9;
	fila_enfileira(f, (void *)aPtr);

	printf("Lista: \n");
	fila_imprime(f);
	printf("Lista tamanho: %d\n",fila_tamanho(f));
	printf("Lista vazia? %d\n", fila_vazia(f));
	printf(".,.,.,.Enfileirar fim.,.,.,.\n\n");



	printf(".,.,.,.Desenfileira.,.,.,.\n");
	fila_desenfileira(f,(void **)&hold);
	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n", fila_tamanho(f));
	printf("Elemento desenfileirado: %d\n", *hold);
	free(hold);
	printf(".,.,.,.Fim desenfileira.,.,.,.\n\n");
	
		printf(".,.,.,.Desenfileira.,.,.,.\n");
	fila_desenfileira(f,(void **)&hold);
	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n", fila_tamanho(f));
	printf("Elemento desenfileirado: %d\n", *hold);
	free(hold);
	printf(".,.,.,.Fim desenfileira.,.,.,.\n\n");
	
		printf(".,.,.,.Desenfileira.,.,.,.\n");
	fila_desenfileira(f,(void **)&hold);
	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n", fila_tamanho(f));
	printf("Elemento desenfileirado: %d\n", *hold);
	free(hold);
	printf(".,.,.,.Fim desenfileira.,.,.,.\n\n");
	
		printf(".,.,.,.Desenfileira.,.,.,.\n");
	fila_desenfileira(f,(void **)&hold);
	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n", fila_tamanho(f));
	printf("Elemento desenfileirado: %d\n", *hold);
	free(hold);
	printf(".,.,.,.Fim desenfileira.,.,.,.\n\n");

	printf(".,.,.,.Cabeca e cauda.,.,.,.\n");
	fila_cabeca(f,(void **)&hold);
	printf("Cabeca: %d\n", *hold);
	fila_cauda(f,(void **)&hold);
	printf("Cauda: %d\n", *hold);
	printf(".,.,.,.Fim c&c.,.,.,.\n\n");


	fila_destroi(&f);
	
	
	f = fila_cria(impr, lib, comp);
	printf(".,.,.,.Lista destruida.,.,.,.\n\n");



	printf(".,.,.,.Enfileira ordenado.,.,.,.\n");

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 5;
	fila_enfileira_ordenado(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 3;
	fila_enfileira_ordenado(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 6;
	fila_enfileira_ordenado(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 7;
	fila_enfileira_ordenado(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 0;
	fila_enfileira_ordenado(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 1;
	fila_enfileira_ordenado(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 2;
	fila_enfileira_ordenado(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 4;
	fila_enfileira_ordenado(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 8;
	fila_enfileira_ordenado(f, (void *)aPtr);

	aPtr = (int *)malloc(sizeof(int));
	*aPtr = 9;
	fila_enfileira_ordenado(f, (void *)aPtr);

	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n",fila_tamanho(f));
	printf(".,.,.,.Fim enfileira ordnado.,.,.,.\n\n");



	printf(".,.,.,.Desenfileira^2.,.,.,.\n");

	fila_desenfileira(f,(void**)&hold);
	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n", fila_tamanho(f));
	printf("Elemento desenfileirado: %d\n\n", *hold);
	free(hold);

	fila_desenfileira(f,(void**)&hold);
	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n", fila_tamanho(f));
	printf("Elemento desenfileirado: %d\n\n", *hold);
	free(hold);

	fila_desenfileira(f,(void**)&hold);
	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n", fila_tamanho(f));
	printf("Elemento desenfileirado: %d\n\n", *hold);
	free(hold);

	fila_desenfileira(f,(void**)&hold);
	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n", fila_tamanho(f));
	printf("Elemento desenfileirado: %d\n\n", *hold);
	free(hold);

	fila_desenfileira(f,(void**)&hold);
	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n", fila_tamanho(f));
	printf("Elemento desenfileirado: %d\n\n", *hold);
	free(hold);

	fila_desenfileira(f,(void**)&hold);
	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n", fila_tamanho(f));
	printf("Elemento desenfileirado: %d\n\n", *hold);
	free(hold);

	fila_desenfileira(f,(void**)&hold);
	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n", fila_tamanho(f));
	printf("Elemento desenfileirado: %d\n\n", *hold);
	free(hold);

	fila_desenfileira(f,(void**)&hold);
	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n", fila_tamanho(f));
	printf("Elemento desenfileirado: %d\n\n", *hold);
	free(hold);

	fila_desenfileira(f,(void**)&hold);
	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n", fila_tamanho(f));
	printf("Elemento desenfileirado: %d\n\n", *hold);
	free(hold);

	fila_desenfileira(f,(void**)&hold);
	printf("Lista: \n");
	fila_imprime(f);
	printf("Tamanho Lista: %d\n", fila_tamanho(f));
	printf("Elemento desenfileirado: %d\n\n", *hold);
	free(hold);



	printf(".,.,.,.Fim desenfileira^2.,.,.,.\n\n");
*/

	lista_destroi(&l);
	printf(".,.,.,.Fila destruida^2.,.,.,.\n\n");

	return 0;
}
