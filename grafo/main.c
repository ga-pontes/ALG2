#include "g.h"
#include "graphtodot.h"

//MAIN DE TESTES DE CRIAÇÃO
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

    generateDot(grafo.listaV.inicio);
   return 0;
}
