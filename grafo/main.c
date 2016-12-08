#include "g.h"
#include "graphtodot.h"
#include "dimensao.h"
#include "arquivo.h"

//MAIN DE TESTES DE CRIAÇÃO
int main(){
<<<<<<< HEAD
    G grafo;
    grafo.listaV.inicio = NULL;

    dimensao * dimensoes = (dimensao *) malloc(5*sizeof(dimensao));

    criarDimensao("Produto", dimensoes, 0, 2);
    inserirAtributo("Marca", &dimensoes[0], 0);

    dimensao F;
    criarDimensao("Filial", dimensoes, 1, 3);
    inserirAtributo("Cidade", &dimensoes[1], 0);
    inserirAtributo("Estado", &dimensoes[1], 1);

    v vert = cria_vertice(0, "", dimensoes);
    gerarSigladoVertice(&vert);
    puts(vert.sigla);

    v *aux_v = &vert;
    aux_v->prox = permuta_dim(aux_v)->inicio;
    while(aux_v != NULL){
        gerarSigladoVertice(aux_v);
        puts(aux_v->sigla);
        aux_v = aux_v->prox;
    }


    /*dimensao S;
    criarDimensao("Tempo", dimensoes, 2, 1);
    inserirAtributo("Dia", &dimensoes[2], 0);

    v vert = cria_vertice(0, "", dimensoes);
    gerarSigladoVertice(&vert);

    int a = 0;

    v *aux_v = &vert;
    while(strlen(aux_v->sigla) > 1){
        aux_v->prox = permuta_dim(aux_v)->inicio;
        while(aux_v->prox != NULL){
            printf("%d\n", a++);
            gerarSigladoVertice(aux_v);
            puts(aux_v->sigla);
            aux_v = aux_v->prox;
        }
        printf("\n");
        gerarSigladoVertice(aux_v);
        puts(aux_v->sigla);
    }*/

    return 0;
=======
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
>>>>>>> origin/master
}
