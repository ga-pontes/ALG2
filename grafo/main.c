#include "g.h"
#include "graphtodot.h"

//MAIN DE TESTES DE CRIAÇÃO
int main(){
    G grafo;
    grafo.listaV.inicio = NULL;

    v v_teste = cria_vertice(0, "ABCDE");
    insere_vertice(&(grafo.listaV), &v_teste);

    V nova_lista = *(gera_permutacao(&v_teste));
    (grafo.listaV.inicio)->prox = nova_lista.inicio;

    V nova_lista2 = *gera_permutacao(nova_lista.inicio) ;
    (grafo.listaV.inicio)->prox->prox->prox->prox->prox->prox = nova_lista2.inicio;

    v* aux = grafo.listaV.inicio;
    while(aux != NULL){
        int it;
        puts(aux->sigla);
        aux = aux->prox;
    }

    GG(&grafo);



   /*
   a aresta4 = cria_aresta(grafo.listaV.inicio->prox->prox->prox->prox);
   a aresta3 = cria_aresta(grafo.listaV.inicio->prox->prox->prox);
   a aresta5 = cria_aresta(grafo.listaV.inicio->prox->prox->prox->prox->prox);
   a aresta_teste = cria_aresta(grafo.listaV.inicio->prox);
   insere_aresta(grafo.listaV.inicio, &aresta_teste);
   aresta_teste = cria_aresta(grafo.listaV.inicio->prox->prox);
   insere_aresta(grafo.listaV.inicio, &aresta_teste);
   insere_aresta(grafo.listaV.inicio->prox->prox, &aresta5);
   insere_aresta(grafo.listaV.inicio->prox->prox->prox, &aresta4);
   insere_aresta(grafo.listaV.inicio->prox->prox->prox, &aresta3);

    printf("\n");
   a *AT = grafo.listaV.inicio->A->inicio;
   while(AT != NULL){
        printf("Aresta do vertice 0 para o vertice %d esta no grafo\n", AT->destino->i);
        AT = AT->prox;
   }

    generateDot(grafo.listaV.inicio);

    */
   return 0;
}
