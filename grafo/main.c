#include "g.h"
#include "graphtodot.h"
#include "dimensao.h"
#include "arquivo.h"

void printaAjuda();
//MAIN DE TESTES DE CRIAÇÃO
int main(){
    /*lista_de_dimensao LD;

    criarDimensao("Produto", LD.dimensoes, 0, 1);
    inserirAtributo("Marca", &(LD.dimensoes[0]), 0);

    criarDimensao("Filial", LD.dimensoes, 1, 2);
    inserirAtributo("Cidade", &(LD.dimensoes[1]), 0);
    inserirAtributo("Estado", &(LD.dimensoes[1]), 1);

    return 0;*/
    int n;
    char tecla, tecla2;
    FILE * teste = NULL;
    int countTeste = 1;
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
            //printf("%d\n", lista_dimensoes->totalElementos);
            printf("Nome da dimensao em [0]: %s", lista_dimensoes->dimensoes[0].nome);
            gerar_grafo_de_derivacao(&lista_dimensoes);
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
            printf("\n\nBateria de testes: selecione o teste que deseja executar: \n");
            printf("1 - Centro de pesquisas.\n");
            printf("2 - Gastos de hospital com produtos.\n");
            printf("3 - Taxa de ocupacao em hospital.\n");
            printf("4 - Projetos\n");
            printf("Atencao! A geracao do grafo pode demorar um pouco.\n");
            fflush(stdin);
            scanf("%c", &tecla2);
            switch(tecla2){
            case '1':
                teste = fopen("centro_pesquisas.txt", "rb");
                break;
            case '2':
                teste = fopen("hospital_gastos_produtos.txt", "rb");
                break;
             case '3':
                teste = fopen("hospital_rede_taxa_de_ocupacao.txt", "rb");
                break;
            case '4':
                teste = fopen("projetos.txt", "rb");
                break;
            default: break;
            }
            if(teste == NULL){
                printf("Arquivo nulo");
                return -1;
            } else {
                lista_dimensoes = registrarDados(teste);
                printf("%d\n", lista_dimensoes->totalElementos);
                gerar_grafo_de_derivacao(lista_dimensoes);
               // gera_grafo_de_dimensoes(lista_dimensoes);
                fclose(teste);
                printf("Teste carregado!\n");
                printf("Selecionando a opcao 2, voce pode ver a organizacao dos registros.\n");
                printf("Foi gerado um arquivo .dot que pode ser usado para visualizar o grafo usando o programa gvedit para este teste.\n");
                printf("O arquivo encontra-se no diretorio do projeto.\n\n");
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

}
