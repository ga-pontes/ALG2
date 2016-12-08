#include <stdio.h>
#include <stdlib.h>

//main do programa. O programa eh iniciado nesta tela, onde eh apresentado o menu de opcoes disponiveis para execucao
void main(){
    //variavel tipo int que recebe a opcao de menu selecionada
    int menu;
    //variavel tipo char
    char garbage;
    //Switch para controle das opcoes do menu: novo grafo, recuperar grafo, ajuda e sair.
    do{
        printf("Selecione a opcao desejada pelo teclado:\n\n");
        printf("1) Novo Grafo de Derivação\n");
        printf("2) Recuperar Grafo de Derivação Salvo\n");
        printf("3) Ajuda\n");
        printf("4) Sair\n");
        scanf("%d", &menu);
        garbage = getchar();
        system("cls");

        switch (menu){
            case 1: //novo grafo de derivação

                //chama a funcao que inicia a criacao do grafo adquirindo os dados necessarios
            break;

            case 2: //Recuperar grafo de derivação no arquivo

                //chama a funcao que le o arquivo e apresenta na tela
            break;

            case 3: //ajuda
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

                //retorna ao menu e limpa a tela
                garbage = getchar();
                system("cls");
            break;

            case 4: //sair
                printf("Saindo...");
                //fclose(fp);
                return 0;
            break;
        }
    }while (menu != 4);
}
