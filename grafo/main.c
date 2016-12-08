#include "g.h"
#include "graphtodot.h"
#include "dimensao.h"
#include "arquivo.h"

void printaAjuda();
//MAIN DE TESTES DE CRIAÇÃO
int main(){
//<<<<<<< HEAD
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

    char siglas_geral[5][5];
    strcpy(siglas_geral[0], dimensoes[0].sigla);
    strcpy(siglas_geral[1], dimensoes[1].atributos[0].sigla);
    strcpy(siglas_geral[2], dimensoes[1].sigla);
    strcpy(siglas_geral[3], dimensoes[1].atributos[0].sigla);
    strcpy(siglas_geral[4], dimensoes[1].atributos[1].sigla);

    int *flag_isolados;
    flag_isolados = (int*) calloc (5, sizeof(int));
    int it;
    for(it = 0; it < 5; it++){
        flag_isolados[it] = 0;
    }

/*
    criarDimensao("Tempo", dimensoes, 2, 1); qd++;
    inserirAtributo("Dia", &dimensoes[2], 0);*/

    //TOTAL DE ELEMENTOS = NRO DE DIMENSOES + NRO DE ATRIBUTOS D1 + NRO AT D2 + NRO AT D3.........
    int total_de_elementos = 2 + 1 + 2;
    //CONJUNTO VAZIO É QUANDO UMA SIGLA É ISOLADA DE TODAS AS OUTRAS.
    //PRECISA SER PASSADO COMO REF PARA SER OPERADO POR FUNCOES EXTERNAS
    int flag_continuidade = 1;
    v vert = cria_vertice(0, "", dimensoes);
    vert.i = 0;
    gerarSigladoVertice(&vert, qd);

    v *aux_v = &vert;
    v *aux_final;

    V nova_lista;
    nova_lista.inicio = &vert;

    while(flag_continuidade){
        int contador = 0;
        aux_final = &vert;
        while(aux_final->prox != NULL){
            aux_final = aux_final->prox;
        }
        v* aux_v7 = &vert;

        //gera "filhos" do vértice atual no final da lista
        permuta_dim(&nova_lista, aux_v, qd, siglas_geral, flag_isolados);

        //passa para o próximo vertice
        aux_v = aux_v->prox;

        int cnt = 0;
        for(it = 0; it < 5; it++){
            if(flag_isolados[it] == 1)
                cnt++;
        }
        if(cnt == 5) flag_continuidade = 0;
    }

        printf("\n");
        //remove_duplicata(&vert);

        v* aux_v7 = &vert;
        while(aux_v7 != NULL){
            puts(aux_v7->sigla);
            aux_v7=aux_v7->prox;
        }



        ///printa o grafo
        printf("\n\n\n");
        v *cor = &vert;
        a *cora;
        while(cor != NULL){
            printf("Vertice %s:\n", cor->sigla);
             cora = cor->A->inicio;
            while(cora != NULL){
                printf("Aresta de %s para %s.\n", cora->origem->sigla, cora->destino->sigla);
                cora = cora->prox;
            }
            cor = cor->prox;
        }

    generateDot(&vert);
    return 0;
}



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
/*=======
    int n;
    char tecla;
    FILE * teste = NULL;
    //Vetor de dimensoes
    lista_de_dimensao * lista_dimensoes;
    do{
        printf("Selecione a opcao desejada pelo teclado:\n\n");
        printf("1) Novo Grafo de Derivacao\n");
        printf("2) Recuperar Dimensoes e Atributos Salvos\n");
        printf("3) Recuperar Registro de Numero N (comecando pelo 0)\n");
        printf("4) Ajuda\n");
        printf("5) Executar bateria de testes.\n");
        printf("6) Sair\n");
        fflush(stdin);
        scanf("%c", &tecla);
        switch(tecla){
        case '1':
            lista_dimensoes = registrarDados(stdin); //Retorna a lista de dimensoes que sera gerada e salva.
            //Criar grafo com essa lista.
            //Exemplo de acesso:
            printf("Nome da dimensao em [0]: %s", lista_dimensoes->dimensoes[0].nome);
            break;
        case '2':
            recuperarDados(stdin);
            break;
        case '3':
            printf("Digite o numero do registro que deseja recuperar: \n");
            fflush(stdin);
            scanf("%d", &n);
            recuperarRegistroN(n);
            break;
        case '4':
            printaAjuda();
            break;
        case '5':
            teste = fopen("test.txt", "r");
            if(teste == NULL){
                printf("Arquivo nulo");
                return -1;
            } else {
                lista_dimensoes = registrarDados(teste);
                fclose(teste);
                printf("Teste carregado!");
            }
            break;
        }

    } while(tecla != '6');

    free(lista_dimensoes);
   return 0;
}

void printaAjuda(){
                printf("AJUDA  -  Pressione 'enter' para voltar ao menu anterior\n\n");

                //pergunta e resposta 1
                printf("1. Como comeco a criacao de um grafo de derivacao?\n");
                printf("R) Para iniciar a criacao de um grafo de derivacao basta selecionar a opcao '1) Novo Grafo de Derivacao' pelo teclado, pressionando as teclas 1 + 'enter'.\n\n");

                //pergunta e resposta 2
                printf("2. O que devo ter em mente para criar um grafo de derivacao?\n");
                printf("R) Para criar seu grafo de derivacao sera necessario incluir alguns dados como numero de dimensoes, quantos atributos cada uma tera, as hierarquias e os nomes das dimensoes e atributos. Lembre-se de que os nomes devem ter entre 2 e 15 letras.\n\n");


                //pergunta e resposta 3
                printf("3. Como eh o procedimento de inserir as informaçoes necessarias?\n");
                printf("R) Eh muito simples, uma pergunta por vez aparecera na tela, entao basta inserir a resposta e pressionar 'enter' ao terminar. Em seguida a próxima pergunta sera mostrada e voce deve seguir o mesmo procedimento até terminar de iserir todas as informacoes.\n\n");

                //pergunta e resposta 4
                printf("4. O que devo fazer quando terminar de inserir todas as informações?\n");
                printf("R) Basta aguardar enquanto o programa gera o grafo de derivacao e apresenta-o na tela.\n\n");

                 //pergunta e resposta 5
                printf("5. Consigo recuperar os atributos e dimensoes que salvei no arquivo?\n");
                printf("R) Sim, basta selecionar a opcao 2 no menu.\n\n");

                 //pergunta e resposta 6
                printf("6. Eh possivel gerar o grafo de derivacao apos ler o aquivo?\n");
                printf("R) Sim, essa opcao aparecera depois que as dimensoes e atributos forem recuperados.\n\n");
>>>>>>> origin/master
}
*/
