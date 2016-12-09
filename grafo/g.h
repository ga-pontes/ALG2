#ifndef G_H_
#define G_H_

#include <stdio.h>
#include <stdlib.h>
#include "dimensao.h"

/// ESTRUTURA DO ALGORITMO DETALHADA NO RELATÓRIO
/// FUNÇOES DESCRITAS EM "g.c"
struct lista_de_arestas;

/// DO VÉRTICE DO GRAFO
typedef struct vertice {
    int i; //EXEMPLO DE CONTEÚDO

    struct lista_de_arestas *A; //ENDERÇO DA LISTA DE ARESTAS DESTE VÉRICE
    struct vertice *prox; //PRÓX VERTICE DO GRAFO

    char sigla[100];

    struct dimensao *dim;
    int nvl_de_cada_dimensao[10];

    int dimensoes_disponiveis[100];
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


int estaVazioV(V *LV);
v cria_vertice(int n, char *s, dimensao *dim);
v* insere_vertice(struct lista_de_vertices *LV, v *novo);
a cria_aresta(v* origem, v *destino);
int estaVazioA(A *LA);
void insere_aresta(v *origem, a *novo);
void gerarSigladoVertice(v *vert, int qd);
void gerarSigladoVerticeD(v *vert, int qd);
void permuta_dim(V *LV, v *vert, int qd, char **ST, int flag_isolados[], int total_de_elementos);
v* cria_arestas_das_isoladas(V *LV, int qd, char **ST, int total_de_elementos, dimensao *dimensoes);
v* cria_arestas_das_isoladas(V *LV, int qd, char **ST, int total_de_elementos, dimensao *dimensoes);
void gera_grafo_de_dimensoes(lista_de_dimensao *LD);
#endif
