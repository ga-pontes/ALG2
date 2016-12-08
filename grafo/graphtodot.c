#include "graphtodot.h"
#include <stdlib.h>
#include <string.h>

//Função que gera o arquivo .DOT a partir do grafo da g.c
void generateDot(v * vertice){

    FILE * tmp = fopen("tmp.txt", "w+");
    a* aresta;


    //Print da sintaxe do DOT no arquivo
    //fprintf(dotFile, "digraph G {\n");
    int numLinhas = 0;
    while(vertice != NULL){
        aresta = vertice->A->inicio;
        if(aresta == NULL){
            fprintf(tmp, "%s;\n", vertice->sigla);
            numLinhas++;
        } else while(aresta != NULL){
            if(strcmp(aresta->origem->sigla, aresta->destino->sigla) == 0){
                aresta = aresta->prox;
                continue;
            }
            fprintf(tmp, "%s -> ", vertice->sigla);
            fprintf(tmp, " %s;\n", aresta->destino->sigla);
            aresta = aresta->prox;
            numLinhas++;
        }
        vertice = vertice->prox;
    }

    char ** linhas = malloc(numLinhas * sizeof(char *));
    int i;
    int repetida;
    char buffer[200];
    fseek(tmp, 0, SEEK_SET);
    for(i = 0; i < numLinhas; i++){
        linhas[i] = malloc(200*sizeof(char));
        linhas[i][0] = 'c';
        fgets(buffer, 200, tmp);
        int j;
        repetida = 0;
        for(j = 0; j < i; j++){
            if(linhas[j][0] != '*' && strcmp(buffer, linhas[j])== 0){
                repetida = 1;
                break;
            }
        }
        if(!repetida){
            strcpy(linhas[i], buffer);
        }
        else
            linhas[i][0] = '*';
    }
    FILE * dotFile = fopen("dotFile.dot", "w+");
    fprintf(dotFile, "digraph G {\n");
    for( i = 0; i < numLinhas; i++){
        if(linhas[i][0] != '*')
        fprintf(dotFile, "%s", linhas[i]);
    }
    fprintf(dotFile, "}");
    fclose(dotFile);
    fclose(tmp);
    printf("NUMLINHAS: %d", numLinhas);
    printf(".DOT file gerada.\n");
}


