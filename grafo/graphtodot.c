#include "graphtodot.h"
#include <stdlib.h>


//Função que gera o arquivo .DOT a partir do grafo da g.c
void generateDot(v * vertice){
    FILE * dotFile = fopen("dotFile.dot", "w+");
    a* aresta;


    //Print da sintaxe do DOT no arquivo
    fprintf(dotFile, "digraph G {\n");
    while(vertice != NULL){
        aresta = vertice->A->inicio;
        if(aresta == NULL){
            fprintf(dotFile, "Vertice%d;\n", vertice->i);
        } else while(aresta != NULL){
            fprintf(dotFile, "Vertice%d -> ", vertice->i);
            fprintf(dotFile, " Vertice%d;\n", aresta->destino->i);
            aresta = aresta->prox;
        }
        vertice = vertice->prox;
    }
    fprintf(dotFile, "}");
    fclose(dotFile);
}
