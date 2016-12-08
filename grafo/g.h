#ifndef G_H_
#define G_H_

#include <stdio.h>
#include <stdlib.h>
#include "dimensao.h"

struct lista_de_arestas;

//DEFINIÇÃO DO VÉRTICE DO GRAFO
typedef struct vertice {
    int i; //EXEMPLO DE CONTEÚDO

    struct lista_de_arestas *A; //ENDERÇO DA LISTA DE ARESTAS DESTE VÉRICE
    struct vertice *prox; //PRÓX VERTICE DO GRAFO

    char sigla[100];

    struct dimensao *dim;
    int nvl_de_cada_dimensao[10];
} v;

typedef struct aresta {
   v* origem;
   v* destino; //DESTINO DA ARESTA (UMA DIMENSÃO)
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


int estaVazioV(V*);
v cria_vertice(int n, char *s, dimensao *dim);
v* insere_vertice(V*, v*);
a cria_aresta(v* origem, v* destino);
int estaVazioA(A*);
void insere_aresta(v*, a*);
V* gera_permutacao(v *vt);
int fatorial(int a);
void GG(G *GRAFO);
void gerarSigladoVertice(v *vert, int qd);
void permuta_dim(V* LV, v *vert, int qd, char ST[][5], int flag_isolados[], int total_de_elementos);
v* cria_arestas_das_isoladas(V *LV, int qd, char ST[][5], int total_de_elementos, dimensao *dimensoes);
v* encontra_duplicata(v *LV);
void remove_duplicata(v *LV);
#endif
