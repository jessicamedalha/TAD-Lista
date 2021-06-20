#include "lista_privado.h"

/*
 * Cria uma lista e a inicializa como lista vazia. 
 * "imp" eh um ponteiro para uma funcao de impressao dos dados armazenados dentro da lista. Deve ser usado em "lista_imprime". 
 * o argumento "libera" prove uma maneira de liberar dinamicamente os dados dentro da celula quando "lista_destroi" eh chamada. 
 * Para uma lista onde os dados nao devem ser liberados, libera deve ser NULL 
 * "comparar" eh um ponteiro para funcao de comparacao entre dois dados armazenados na lista. 
 * Deve retornar -1 se o primeiro eh menor que o segundo, 0 se forem iguais, ou 1 se o primeiro for maior que o segundo   
 * Pre: nenhuma
 * Pos: Retorna um ponteiro para uma lista vazia se houver memaria disponivel
 */
lista_t *lista_cria(void (*imp)(const void *), void (*libera)(void *), int (*comparar)(const void *, const void *)){

	lista_t *ptr_lista = (lista_t*)malloc(sizeof(lista_t)*1);
	if (ptr_lista == NULL)
	{
		return NULL;
	}

	ptr_lista->cabeca = NULL;
	ptr_lista->cauda = NULL;
	ptr_lista->tamanho = 0;
	ptr_lista->destruir = libera;
	ptr_lista->imprime = imp;
	ptr_lista->compara = comparar;

	return ptr_lista;
}

/*
 * Destroi a lista especificada em "l". Nenhuma operacao eh permitida apos a funcao, a nao ser que lista cria seja chamada novamente. 
 * Destroi todos os elementos armazenados na lista se o ponteiro "destruir" for valido
 * Pre: "l" deve ser uma lista valida criada previamente atraves da funcao lista cria
 * Pos: os recursos da lista foram liberados com sucesso e a lista "l" torna-se nula
 */
void lista_destroi(lista_t **l){
	if((l)== NULL || (*l)== NULL){
		return;
	}

	celula_t *ptr_guarda;
	celula_t *ptr_destroi;
	celula_t *p;
	ptr_destroi = (*l)->cabeca;

	if ((*l)->destruir != NULL)
	{
		for (p = (*l)->cabeca; p != (*l)->cauda; p = p->proximo)
		{

			ptr_destroi = ptr_proximo;
			ptr_proximo = ptr_proximo->prox;
			(*l)->destruir(ptr_destroi->dado);
			free(ptr_destroi);

		}
	{

	else
	{
		for (p = (*l)->cabeca; p != (*l)->cauda; p = p->proximo)
		{

			ptr_destroi = ptr_proximo;
			ptr_proximo = ptr_proximo->prox;		
			free(ptr_destroi);
		}

	}
	free(*l);
	(*l)= NULL;
}

/*
 * Retorna 1 se a lista estiver vazia, 0 caso contrario
 * Pre: a lista deve existir
 * Pos: retorna 1 caso a lista estiver vazia, 0 se nao estiver. Retorna -1 caso a lista nao existir
 */
int lista_vazia(lista_t *l){
	if (l == NULL)
	{
		return -1;
	}

	if (l->tamanho == 0)
	{
		return 1;
	}

	return 0;
}

/*
 * Retorna o tamanho da lista
 * Pre: a lista deve existir
 * Pos: retorna o tamanho da lista. Retorna -1 caso a lista nao existir
 */
int lista_tamanho(lista_t *l){
	if (l == NULL)
	{
		return -1;
	}

	return l->tamanho;
}

/*
 * Retorna a celula cabeca da lista
 * Pre: a lista deve existir
 * Pos: retorna a celula cabeca da lista. Retorna NULL caso a lista estiver vazia ou nao existir
 */
celula_t *lista_cabeca(lista_t *l){
	if (l == NULL || (lista_vazia(l) == 1))
	{
		return NULL;		
	}

	return l->cabeca;
}

/*
 * Retorna a celula cauda da lista
 * Pre: a lista deve existir
 * Pos: retorna a celula cauda da lista. Retorna NULL caso a lista estiver vazia ou nao existir
 */
celula_t *lista_cauda(lista_t *l){
	if (l == NULL || (lista_vazia(l) == 1))			
	{
		return NULL;
	}

	return l->cauda;
}

/*
 * Retorna o dado armazenado dentro da celula "c".
 * Pre: a celula deve existir
 * Pos: retorna o dado armazenado dentro de "c" ou NULL caso "c" for invalido
 */
void *lista_dado(celula_t *c){
	if (c == NULL)
	{
		return NULL;
	}

	return c->dado;
}

/*
 * Retorna a celula que esta imediamente apos a celula recebida como parametro.
 * Pre: a celula deve existir
 * Pos: retorna a celula apos "c" ou NULL caso "c" for invalido
 */
celula_t *lista_proximo(celula_t *c){
	if (c == NULL)
	{
		return NULL;
	}

	return c->prox;

}

/*
 * Retorna a celula que esta imediamente antes a celula recebida como parametro.
 * Pre: a celula deve existir
 * Pos: retorna a celula que esta antes de "c" ou NULL caso "c" for invalido
 */
celula_t *lista_anterior(celula_t *c){
	if (c == NULL)
	{
		return NULL;
	}

	return c->ant;
}

/*
 * Retorna 1 caso a celula recebida como parametro for a celula cabeca da lista "l", 0 caso contrario.
 * Pre: a lista deve existir e a celula recebida como parametro deve ser valida
 * Pos: retorna 1 se "c" for cabeca de "l", 0 caso contrario. Retorna -1 se a lista "l" ou a celula "c" forem invalidas ou se a lista estiver vazia
 */
int lista_eh_cabeca(lista_t *l, celula_t *c){
	if (l == NULL  || (lista_vazia(l) == 1) || c ==NULL)
	{
		return -1;
	}

	if (lista_cabeca(l) == c)
	{
		return 1;
	}

	return 0;
}

/*
 * Retorna 1 caso a celula recebida como parametro for a celula cauda da lista "l", 0 caso contrario.
 * Pre: a lista deve existir e a celula recebida como parametro deve ser valida
 * Pos: retorna 1 se "c" for cauda de "l", 0 caso contrario. Retorna -1 se a lista "l" ou a celula "c" forem invalidas ou se a lista estiver vazia
 */
int lista_eh_cauda(lista_t *l, celula_t *c){
	if (l == NULL  || (lista_vazia(l) == 1) || c ==NULL)
	{
		return -1;
	}

	if (lista_cauda(l) == c)
	{
		return 1;
	}

	return 0;
}

/*
 * Insere um elemento na lista imeadiamente apos um elemento determinado e recebido como parametro da funcao (celula "c").
 * Caso esse parametro seja invalido, insere o novo elemento na cabeca da lista. 
 * Retorna 1 caso conseguir inserir, 0 caso contrario
 * Pre: A lista e o novo elemento a ser inserido devem ser validos
 * Pos: O elemento recebido como parametro eh inserido logo apos a celula "c" ou na cabeca da lista
 */
int lista_insere_proximo(lista_t *l, celula_t *c, const void *elem){
	if (l == NULL || elem == NULL)
	{
		return 0;
	}

	celula_t *nova_celula = (celula_t*)malloc(sizeof(celula_t)*1);
	if (nova_celula == NULL)
	{
		return 0;
	}
	nova_celula->dado = (void *)elem;

	if (lista_vazia(l) == 1)
	{
		l->cabeca = nova_celula;
		l->cauda = nova_celula;
		nova_celula->prox = NULL;
		nova_celula->ant = NULL;
		l->tamanho ++;

		return 1;
	}

	if (c == NULL)
	{
		nova_celula->prox = l->cabeca;
		nova_celula->ant = NULL;
		l->cabeca->ant = nova_celula;
		l->cabeca = nova_celula;
		l->tamanho ++;

		return 1;
		
	}

	if (lista_eh_cauda(l,c) == 1)
	{
		l->cauda->prox = nova_celula;
		nova_celula->ant = l->cauda;
		nova_celula->prox = NULL;
		l->cauda = nova_celula;
		l->tamanho ++;

		return 1;
	}

	c->prox->ant = nova_celula;
	nova_celula->prox = c->prox;
	nova_celula->ant = c;
	c->prox = nova_celula;
	l->tamanho ++;

	return 1;
}

/*
 * Insere um elemento na lista imeadiamente antes a um elemento determinado e recebido como parametro da funcao (celula "c").
 * Caso esse parametro seja invalido, insere o novo elemento na cabeca da lista. 
 * Retorna 1 caso conseguir inserir, 0 caso contrario
 * Pre: A lista e o novo elemento a ser inserido devem ser validos
 * Pos: O elemento recebido como parametro eh inserido antes da celula "c" ou na cabeca da lista
 */
int lista_insere_anterior(lista_t *l, celula_t *c, const void *elem){
		if (l == NULL || elem == NULL)
	{
		return 0;
	}

	celula_t *nova_celula = (celula_t*)malloc(sizeof(celula_t)*1);
	if (nova_celula == NULL)
	{
		return 0;
	}
	nova_celula->dado = (void *)elem;

	if (lista_vazia(l) == 1)
	{
		l->cabeca = nova_celula;
		l->cauda = nova_celula;
		nova_celula->prox = NULL;
		nova_celula->ant = NULL
		l->tamanho ++;

		return 1;	}
	}

	if (c == NULL)
	{
		l->cabeca->ant = nova_celula;
		nova_celula->prox = l->cabeca;
		nova_celula->ant = NULL;
		l->cabeca = nova_celula;
		l->tamanho ++;

		return 1;	
	}

	if (lista_eh_cabeca(l,c) == 1)
	{
		l->cabeca->ant = nova_celula;
		nova_celula->prox = l->cabeca;
		nova_celula->ant = NULL;
		l->cabeca = nova_celula;
		l->tamanho ++;

		return 1;
	}

	c->ant->prox = nova_celula;
	nova_celula->ant = c->ant;
	nova_celula->prox = c;
	c->ant = nova_celula;
	l->tamanho ++;

	return 1;

}

/*
 * Insere um elemento na lista na posicao especificada por "posicao". Caso "posicao" seja maior que o tamanho da lista, insere o elemento na cauda da lista.
 * A ordem das posicoes da lista segue a mesma utilizada em vetores (0 eh equivalente a primeira posicao na lista, 1 a segunda e assim por diante)
 * Retorna 1 caso conseguir inserir, 0 caso contrario
 * Pre: A lista e o novo elemento a ser inserido devem ser validos
 * Pos: O elemento recebido como parametro eh inserido logo apos a celula "c" ou na cabeca da lista. Retorna 1 caso conseguir inserir, 0 caso contrario
 */
int lista_insere_posicao(lista_t *l, const unsigned int posicao, const void *elem{
	if (l == NULL || elem == NULL)
	{
		return 0;
	}

	if (lista_vazia(l) == 1)
	{
		lista_insere_proximo(l, l->cabeca, elem);
		return 1;
	}

	if (posicao >= (l->tamanho))
	{
		lista_insere_proximo(l, l->cauda, elem);
        return 1;
		
	}

	celula_t *procura_posicao = l->cabeca;
	for (int i = 0; i < posicao; ++i)
	{
		procura_posicao = procura_posicao->prox;
	}

	lista_insere_anterior(l,procura_posicao, elem);
	return 1;
}

/* 
 * Remove o elemento conhecido e recebido como parametro. Retorna o conteudo do elemento removido em uma variavel recebida como parametro. 
 * Retorna 1 caso conseguir remover, 0 caso contrario.
 * Pre: a lista deve existir e nao deve estar vazia, a celula a ser removida e a variavel recebida para armazenar o conteudo removido devem ser validas
 * Pos: a lista tera um elemento a menos e seu conteudo sera retornado dentro de uma variavel recebida como parametro
 * Retorna 1 caso conseguir remover, 0 caso contrario
 */
int lista_remove(lista_t *l, celula_t *c, void **elem){
	if(l == NULL || c == NULL || elem == NULL || (*elem) == NULL || lista_vazia(l) == 1)
    {
        return 0;
    }

    (*elem) = c->dado;
    if(l->tamanho == 1) 
    {
    	free(l->cabeca);
    	l->cauda = NULL;
        l->cabeca = NULL;
        l->tamanho--;
        return 1;
    }
    if (lista_eh_cabeca(l, c) == 1) 
    {
        l->cabeca->prox->ant = NULL;
        l->cabeca = l->cabeca->prox;
        free(c);
    	l->tamanho--;
    	return 1;
    }
    if (lista_eh_cauda(l,c) == 1) 
    {
        l->cauda->ant->prox = NULL;
        l->cauda = l->cauda->ant;
        free(c);
    	l->tamanho--;
    	return 1;
    }

    c->prox->ant = c->ant;
    c->ant->prox = c->prox; 
    free(c);
    l->tamanho--;
    return 1;
}

/*
 * Imprime os elementos da lista atraves do ponteiro de funcao "imprime", comecando pela cabeca da lista
 * Pre: a lista deve existir e o ponteiro "imprime" deve ser valido
 * Pos: Os elementos sao impressos usando o ponteiro "imprime"
 */
void lista_imprime(lista_t *l){
	if(l == NULL || l->imprime == NULL || lista_vazia(l) == 1)
    {
        return;
    }
    celula_t *celula = l->cabeca;
    for(int i = 0; i<(l->tamanho); i++)
    {
        l->imprime(celula->dado);
        celula = celula->prox;
    }
}

/*
 * Insere um novo elemento na lista de forma ordenada (crescente). Caso o ponteiro "elem" tenha um valor igual a um elemento que estiver na lista, a insercao de "elem" deve ser feita logo apos.
 * Eh responsabilidade de quem chama o gerenciamento da memoria de "elem", onde ela devera permanecer valida enquanto estiver dentro da lista.
 * Caso o ponteiro de funcao "compara" for NULL, a insercao de "elem" deve ser feita na cauda da lista.
 * Retorna 1 caso conseguir inserir, 0 caso contrario
 * Pre: a lista deve existir e "elem" deve ser valido
 * Pos: o elemento recebido pela operacao eh inserido de forma ordenada (crescente)
 * OBS: considere que a lista ja esta ordenada, ou seja, nao precisa ordenar antes de usar a funcao
 */
int lista_insere_ordenado(lista_t *l, const void *elem){
	if(l == NULL || elem == NULL)
    {
        return 0;
    }
    if(l->compara == NULL)
    {
        lista_insere_proximo(l, l->cauda, elem);
        return 1;
    }
    if(lista_vazia(l) == 1)
    {
        lista_insere_proximo(l, l->cabeca, elem);
        return 1;
    }
    celula_t *aux = l->cabeca;
    while(l->compara(elem, aux->dado) == 1)
    {
        if(aux->prox == NULL)
        {
            lista_insere_proximo(l, aux, elem);
            return 1;
        }
        aux = aux->prox;
    }
    if(l->compara(elem, aux->dado) == -1 || l->compara(elem, aux->dado) == 0)
    {
        lista_insere_anterior(l, aux, elem);
    }
    return 1;
}

/*
 * Funcao recursiva que retorna a celula da lista que contem o elemento recebido como parametro. A comparacao deve ser feita usando ponteiros, e nao a funcao de comparacao internda da lista.
 * A celula "c" recebida deve ser usada para finalizar a recursao.
 * Pre: a lista, o elemento e a celula recebidas devem ser validas. A lista nao pode estar vazia
 * Pos: Retorna a celula que contem o elemento ou NULL caso o elemento nao estiver na lista recebida
 */
celula_t *lista_busca_recursiva(lista_t *l, const void *elem, celula_t *c){
	if(l == NULL || elem == NULL || c == NULL || lista_vazia(l) == 1)
    {
        return NULL;
    }
    if(c->dado != elem)
    {
         c = lista_busca_recursiva(l, elem, c->prox);
    }
    return c;
}

/*
 * Separa a lista recebida como parametro em duas, de tal forma que a segunda lista comece na primeira celula logo apos a celula que contem o elemento recebido como parametro.
 * A funcao deve retornar um ponteiro para a segunda sub-divisao da lista original, enquanto l deve continuar apontando para o primeiro elemento da primeira sub-divisao da lista.
 * Se o elemento recebido como parametro for NULL ou nao estiver na lista "l", a funcao nao faz nada e retorna NULL. 
 * A nova lista deve ter os mesmos ponteiros internos (imprime, compara e destruir) da lista "l"
 * Pre: lista deve existir e o elemento recebido como parametro deve ser valido
 * Pos: retorna um ponteiro para a nova lista que inicia logo apos a celula que contem "elem". Esta celula torna-se a cauda da lista "l". Retorna NULL caso nao conseguir separar a lista
 */
lista_t *lista_separa(lista_t *l, const void *elem){
	if(l == NULL || elem == NULL)
    {
        return NULL;
    }
    celula_t *celula_auxiliar = lista_busca_recursiva(l, elem, l->cabeca);
    if(celula_auxiliar == NULL)
    {
        return NULL;
    }
    lista_t *nova_lista = lista_cria(l->imprime, l->destruir, l->compara);
    int contador = 1; 
    for(celula_t *celula = celula_auxiliar->prox; celula != NULL; celula = celula->prox)
    {
        lista_insere_posicao(nova_lista, contador, celula->dado);
        contador++;
    }
    celula_t *celula_auxiliar_2 = nova_lista->cabeca; 
    for(celula_t *celula = celula_auxiliar->prox; celula != NULL; celula = celula->prox)
    {
        lista_remove(l, celula, celula_auxiliar_2->dado);
        celula_auxiliar_2 = celula_auxiliar_2->prox;
    }
    return nova_lista;

}

/*
 * Concatena duas listas recebidas como parametro e retorna a lista resultante da concatenacao.
 * Depois da funcao ser chamada, as listas "l1" e "l2" nao sao mais validas (serao destruidas) e suas celulas estarao dentro da lista retornada.
 * A nova lista deve ter os mesmos ponteiros internos (imprime, compara e destruir) da lista "l1" ou da lista "l2" se a "l1" for vazia
 * Pre: "l1" e "l2" devem ser listas validas (observe que elas podem ser vazias).
 * Pos: retorna uma nova lista contendo a concatenacao das duas listas recebidas como parametro. Retorna NULL caso nao conseguir concatenar as duas listas. 
 * Retorna NULL se ambas forem vazias (sem destrui-las). 
 * Apos a execucao, l1 e l2 nao sao mais listas validas e foram destruidas.
 */
lista_t *lista_concatena_e_destroi(lista_t **l1, lista_t **l2){
	    if(l1==NULL || l2==NULL)
    {
        return NULL;
    }
    if(lista_vazia((*l1)) == 1 && lista_vazia((*l2))== 1)
    {
        return NULL;
    }
    lista_t *nova_lista;
    if(lista_vazia((*l1)) == 1)
    {
        nova_lista = lista_cria((*l2)->imprime, (*l2)->destruir, (*l2)->compara);
    }
    else
    {
        nova_lista = lista_cria((*l1)->imprime, (*l1)->destruir, (*l1)->compara);
    }
    int contador = 1;
    celula_t *aux = (*l1)->cabeca;
    for(int i = 0; i < (lista_tamanho(*l1)); i++)
    {
        lista_insere_posicao(nova_lista,contador,aux->dado);
        contador++;
        aux = aux->prox;
    }
    aux = (*l2)->cabeca;
    for(int i = 0; i < (lista_tamanho(*l2)); i++)
    {
        lista_insere_posicao(nova_lista,contador,aux->dado);
        contador++;
        aux = aux->prox;
    }
    lista_destroi(l1);
    lista_destroi(l2);
    return nova_lista;
}
