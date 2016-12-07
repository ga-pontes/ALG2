#include "g.h"
#include "graphtodot.h"
#include "dimensao.h"

#define N_DIM 5
//MAIN DE TESTES DE CRIAÇÃO
int main(){
<<<<<<< HEAD
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
=======
    dimensao * d = malloc(sizeof(dimensao));
    criarDimensao("Dimensao1", d, 0, 5);
    inserirAtributo("Produto", d);
    inserirAtributo("Marca", d);
    inserirAtributo("Marrom", d);
    inserirAtributo("Marlon", d);

    /*
    char tecla = '\0';
    G * grafo;
    do{
    printf("\n\nSelecione o que deseja executar: \n");
    printf("1 - Novo Grafo de Derivação.\n");
    printf("2 - Ajuda\n");
    printf("Envie 'q' para sair. \n");
    fflush(stdin);
    scanf("%c", &tecla);

    switch(tecla){
    case '1':
        grafo = criarGrafo();
        break;
    }

    } while(tecla != 'q');*/
   return 0;
}

/*
void criarGrafo(){
    //Alocando espaço para o grafo
    G *g = (G *) malloc(sizeof(G));
>>>>>>> origin/master

    //Coletando informações sobre a estrutura do grafo
    int nDimensoes;
    printf("Digite o numero de Dimensoes que o grafo possuirá: ");
    fflush(stdin);
    scanf("%d", &nDimensoes);

<<<<<<< HEAD
    generateDot(grafo.listaV.inicio);

    */
   return 0;
}
=======
    //Alocando espaço para as dimensoes
}*/
>>>>>>> origin/master
