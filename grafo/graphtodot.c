#include "graphtodot.h"
#include <stdlib.h>

void generateDot(v * vertice){
    FILE * dotFile = fopen("dotFile.dot", "w+");
    a* aresta;
    while(vertice != NULL){
        aresta = vertice->A->inicio;
        while(aresta != NULL){
            fprintf(dotFile, "EsseVertice -> ");
            fprintf(dotFile, " ProxVertice\n");
            aresta = aresta->prox;
            aresta = NULL;
        }
        vertice = vertice->prox;
    }
    fclose(dotFile);
}
