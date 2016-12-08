#include "g.h"
#include "graphtodot.h"
#include "dimensao.h"
#include "arquivo.h"

//MAIN DE TESTES DE CRIAÇÃO
int main(){
//<<<<<<< HEAD
    G grafo;
    grafo.listaV.inicio = NULL;
    int qd = 0;

    dimensao * dimensoes = (dimensao*) malloc(5*sizeof(dimensao));

    criarDimensao("Produto", dimensoes, 0, 1); qd++;
    inserirAtributo("Marca", &dimensoes[0], 0);

    criarDimensao("Filial", dimensoes, 1, 2); qd++;
    inserirAtributo("Cidade", &dimensoes[1], 0);
    inserirAtributo("Estado", &dimensoes[1], 1);
/*
    criarDimensao("Tempo", dimensoes, 2, 1); qd++;
    inserirAtributo("Dia", &dimensoes[2], 0);*/

    //TOTAL DE ELEMENTOS = NRO DE DIMENSOES + NRO DE ATRIBUTOS D1 + NRO AT D2 + NRO AT D3.........
    int total_de_elementos = 2 + 1 + 2;
    //CONJUNTO VAZIO É QUANDO UMA SIGLA É ISOLADA DE TODAS AS OUTRAS.
    //PRECISA SER PASSADO COMO REF PARA SER OPERADO POR FUNCOES EXTERNAS
    int *conjuntos_vazios_encontrados;
    conjuntos_vazios_encontrados = (int*) malloc (1 * sizeof(int));
    *conjuntos_vazios_encontrados = 0;

    v vert = cria_vertice(0, "", dimensoes);
    vert.i = 0;
    gerarSigladoVertice(&vert, qd);

    v *aux_v = &vert;
    v *aux_final;

    while(*conjuntos_vazios_encontrados < total_de_elementos){
        int contador = 0;
        aux_final = &vert;
        while(aux_final->prox != NULL){
            aux_final = aux_final->prox;
        }
        v* aux_v7 = &vert;

        //gera "filhos" do vértice atual no final da lista
        aux_final->prox = permuta_dim(aux_v, qd, conjuntos_vazios_encontrados)->inicio;

        //passa para o próximo vertice
        aux_v = aux_v->prox;
    }

        remove_duplicata(&vert);
        remove_duplicata(&vert);

        v* aux_v7 = &vert;
        while(aux_v7 != NULL){
            puts(aux_v7->sigla);
            aux_v7=aux_v7->prox;
        }

        printf("\n");

    return 0;
/*=======
    int n;
    char tecla;
    do{
    printf("\n\nSelecione o que deseja executar: \n");
    printf("1 - Novo Grafo de Derivacao.\n");
    printf("2 - Recuperar todos os dados do registro.\n");
    printf("3 - Recuperar o registro de numero n, comecando do 0.\n");
    printf("Envie 'q' para sair. \n");
    fflush(stdin);
    scanf("%c", &tecla);
    switch(tecla){
    case '1':
        criarGrafo();
        break;
    case '2':
        recuperarDados();
        break;
    case '3':
        printf("Digite o numero do regitro que deseja recuperar: \n");
        fflush(stdin);
        scanf("%d", &n);
        recuperarRegistroN(n);
        break;
    }

    } while(tecla != 'q');
   return 0;
>>>>>>> origin/master*/
}
