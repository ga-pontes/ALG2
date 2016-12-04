#include <stdio.h>
#include <stdlib.h>

struct lista_de_arestas;
stru;

typedef struct vertice {
    int i;
    struct lista_de_arestas *A;
    struct vertice *prox;
} v;

typedef struct aresta {
   v* destino;
   struct aresta *prox;
} a;


typedef struct lista_de_arestas{
    a* inicio;
} A;

v cria_vertice(int n){
    v novo;
    novo.i = n;
    novo.prox = NULL;
    novo.A = (A*) malloc (1 * sizeof(A));
    novo.A->inicio = NULL;
    printf("\nVertice %d criado.\n", n);

    return novo;
}

typedef struct lista_de_vertices{
    v* inicio;
} V;

int estaVazioV(V *LV){
    if(LV->inicio == NULL){
        printf("LV vazia.\n");
        return 1;
    }
    printf("LV nao vazia.\n");
    return 0;
}

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


typedef struct GRAFO{
    V listaV;
} G;


a cria_aresta(v *destino){
    a novo;
    novo.prox = NULL;
    novo.destino = destino;
    printf("\nAresta para %d criada.\n", destino->i);
    return novo;
}


int estaVazioA(A *LA){
    if(LA->inicio == NULL){
        return 1;
    }
    return 0;
}

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

int main(){
   G grafo;
   grafo.listaV.inicio = NULL;
   //grafo.listaA.inicio = NULL;

   int i;
   v v_aux;

   for(i = 0; i < 10; i++){
        v_aux = cria_vertice(i);
        insere_vertice(&(grafo.listaV), &v_aux);
   }

   printf("\n");
   v_aux = *(grafo.listaV.inicio);
   for(i = 0; i < 9; i++){
        printf("Vertice %d esta no grafo.\n", v_aux.i);
        v_aux = *(v_aux.prox);
   }

   a aresta_teste = cria_aresta(grafo.listaV.inicio->prox);
   insere_aresta(grafo.listaV.inicio->A, grafo.listaV.inicio, &aresta_teste);
   aresta_teste = cria_aresta(grafo.listaV.inicio->prox->prox);
   insere_aresta(grafo.listaV.inicio->A, grafo.listaV.inicio, &aresta_teste);

    printf("\n");
   a *AT = grafo.listaV.inicio->A->inicio;
   while(AT != NULL){
        printf("Aresta do vertice 0 para o vertice %d esta no grafo\n", AT->destino->i);
        AT = AT->prox;
   }

   return 0;
}




