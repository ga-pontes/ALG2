#include "g.h"
#include "graphtodot.h"
#include "dimensao.h"
#include "arquivo.h"

//MAIN DE TESTES DE CRIAÇÃO
int main(){
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
}
