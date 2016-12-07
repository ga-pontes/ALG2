#include "g.h"
#include "graphtodot.h"
#include "dimensao.h"

#define N_DIM 5
//MAIN DE TESTES DE CRIAÇÃO
int main(){
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

    //Coletando informações sobre a estrutura do grafo
    int nDimensoes;
    printf("Digite o numero de Dimensoes que o grafo possuirá: ");
    fflush(stdin);
    scanf("%d", &nDimensoes);

    //Alocando espaço para as dimensoes
}*/
