#include <stdio.h>
#include <stdlib.h>

struct lista_de_arestas;
stru;

int estaVazioV(V*);
v cria_vertice(int);
void insere_vertice(lista_de_vertices*, v*);
a cria_aresta(v*);
int estaVazioA(A*);
void insere_aresta(A*, v*, a*);

//DEFINI��O DO V�RTICE DO GRAFO
typedef struct vertice {
    int i; //EXEMPLO DE CONTE�DO
    struct lista_de_arestas *A; //ENDER�O DA LISTA DE ARESTAS DESTE V�RICE
    struct vertice *prox; //PR�X VERTICE DO GRAFO
} v;

typedef struct aresta {
   v* destino; //DESTINO DA ARESTA (UMA DIMENS�O)
   struct aresta *prox; //PROX ARESTA DA LISTA DE ARESTAS
} a;


typedef struct lista_de_arestas{
    a* inicio; //INICIO DA LISTA
} A;

typedef struct lista_de_vertices{
    v* inicio; //INICIO DA LISTA
} V;

//GRAFO(LISTA DE VERTICES E LISTAS DE ARESTAS)
typedef struct GRAFO{
    V listaV;
} G;


