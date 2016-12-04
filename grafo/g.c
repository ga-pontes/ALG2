#include "g.h"

//VERIFICA SE A LISTA DE VERTICES ESTA VAZIA
int estaVazioV(V *LV){
    if(LV->inicio == NULL){
        printf("LV vazia.\n");
        return 1;
    }
    printf("LV nao vazia.\n");
    return 0;
}

//FUNÇÃO PARA CRIAR NOVO VÉRTICE
v cria_vertice(int n){
    v novo;
    novo.i = n;
    novo.prox = NULL;
    novo.A = (A*) malloc (1 * sizeof(A));
    novo.A->inicio = NULL;
    printf("\nVertice %d criado.\n", n);

    return novo;
}

//INSERE NOVO VERTICE NA LISTA DE VERTICES
void insere_vertice(struct lista_de_vertices *LV, v *novo){
    if(estaVazioV(LV)){
        LV->inicio = (v*) malloc (1 * sizeof(v));
        *LV->inicio = *novo;
    } else {
        v *aux;
        aux = LV->inicio;
        printf("Comecou no vertice %d\n", aux->i);
        while(aux->prox != NULL){
            printf("Passou pelo vertice %d\n", aux->i);
            aux = aux->prox;
        }
        printf("Parou no vertice %d\n", aux->i);
        aux->prox = (v*) malloc (1 * sizeof(v));
        *aux->prox = *novo;
    }
    printf("Vertice %d inserido no grafo.\n", novo->i);
}

//FUNÇÃO PARA CRIAR UMA NOVA ARESTA
a cria_aresta(v *destino){
    a novo;
    novo.prox = NULL;
    novo.destino = destino;
    printf("\nAresta para %d criada.\n", destino->i);
    return novo;
}

//VERIFICA SE A LISTA DE ARESTA ESTA VAZIA
int estaVazioA(A *LA){
    if(LA->inicio == NULL){
        return 1;
    }
    return 0;
}

//FUNÇÃO PARA INSERIR UMA ARESTA NUMA LISTA
void insere_aresta(A *LA, v *origem, a *novo){
    if(estaVazioA(LA)){
        printf("Lista de arestas estava vazia.\n");
        LA->inicio = (a*) malloc (1 * sizeof(a));
        *LA->inicio = *novo;
        printf("Aresta foi inserida no inicio da lista.\n");
    } else {
        a *aux;
        aux = LA->inicio;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox  = (a*) malloc (1 * sizeof(a));
        *aux->prox = *novo;
        printf("Aresta foi inserida no final da lista.\n");
    }
    printf("Aresta %d -> %d inserida no grafo.\n", origem->i, novo->destino->i);
}




