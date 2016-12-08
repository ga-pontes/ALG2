#include "arquivo.h"
#include <stdlib.h>
#include <stdio.h>
/*Função registrarDados
    Descrição: obtém do teclado do usuário as informações necessarias para a geração do grafo de derivação.
    Isto é, numero de dimensoes, numero de atributos, nome das dimensoes e nome dos atributos.
    parâmetros: nenhum.
    retorno: nenhum.
*/
lista_de_dimensao * registrarDados(FILE * fonte){
    int numDim, numAtr;

    lista_de_dimensao * lista = (lista_de_dimensao *) malloc(sizeof(lista_de_dimensao));

    //Coletando informações do usuario
    if(fonte == stdin){
        printf("Digite o numero de dimensoes que o grafo possuirá. \n");
        fflush(fonte);
    }
    fscanf(fonte, "%d", &numDim);

    if(fonte != stdin)
        fscanf(fonte, "\n");

    //Alocando vetor de dimensoes
    dimensao * dimensoes = (dimensao *) malloc(numDim*sizeof(dimensao));
    //Coletando informações sobre as dimensoes
    int i;
    for(i = 0; i < numDim; i++){
        if(fonte == stdin)
            printf("Digite o nome da dimensao %d\n", i+1);
        char nome[16];
        char bufferLinha[200];
        if(fonte == stdin)
            fflush(fonte);
        fgets(bufferLinha, 200, fonte);
        strncpy(nome, bufferLinha, 15);
        nome[15] = '\0';
        if(fonte == stdin)
            printf("Digite a quantidade de atributos dessa dimensao.\n");
        if(fonte == stdin)
            fflush(fonte);
        fscanf(fonte, "%d", &numAtr);
        if(fonte != stdin)
            fscanf(fonte, "\n");
        criarDimensao(nome, dimensoes, i, numAtr);
        int j;
        int prioridade = 0;
        //Coletando informações sobre atributos
        for(j = 0; j < numAtr; j++){
            if(fonte == stdin)
                printf("Digite, em ordem crescente de hierarquia, o nome dos atributos dessa dimensão.\n");
            if(fonte == stdin)
                fflush(fonte);
            fgets(bufferLinha, 200, fonte);
            strncpy(nome, bufferLinha, 15);
            nome[15] = '\0';
            inserirAtributo(nome, &dimensoes[i], prioridade);
            prioridade++;
        }
    }
    salvarDados(dimensoes, numDim);
    lista->dimensoes = dimensoes;
    lista->tamanho = numDim;
    return lista;
}

/*Função: recuperarDados
    Descrição:
    Permite ao usuario printar na tela todos os dados salvos em modo binario sobre as dimensoes e atributos.
    parâmetros: fonte. Stdin para entrada por teclado ou pode ser arquivo de teste.
    retorno: nenhum.
*/
void recuperarDados(){
    FILE * arquivo = fopen("dados.bin", "rb");
    char bufferNome[16];
    char bufferSigla[3];
    int bufferNumAtrib;
    char bufferNomeAtributo[16];
    char bufferSiglaAtributo[3];
    int bufferNvHierarquia;
    int i;
    dimensao d;
    char sentinela;
    int counter = 0;
    while(!feof(arquivo)){
        if(counter != 0)
            fread(&sentinela, 1, 1, arquivo);
        if(sentinela == '*'){
            while(fread(&sentinela, 1, 1, arquivo) && sentinela != '|');
        } else if(sentinela != '|' && counter != 0)
            printf("WARNING: DELIMITADOR DE REGISTRO INCORRETO FOI LIDO!");
        if(!fread(&bufferNumAtrib, sizeof(bufferNumAtrib), 1, arquivo))
            break;
        fread(&bufferNome, sizeof(bufferNome), 1, arquivo);
        fread(&bufferSigla, sizeof(bufferSigla), 1, arquivo);

        strcpy(d.nome, bufferNome);
        strcpy(d.sigla, bufferSigla);
        d.numAtributos = bufferNumAtrib;
        d.atributos = (atributo *) malloc(d.numAtributos * sizeof(atributo));
        for(i = 0; i < bufferNumAtrib; i++){
            fread(&bufferNomeAtributo, sizeof(bufferNomeAtributo), 1, arquivo);
            fread(&bufferSiglaAtributo, sizeof(bufferSiglaAtributo), 1, arquivo);
            fread(&bufferNvHierarquia, sizeof(bufferNvHierarquia), 1, arquivo);
            strcpy(d.atributos[i].nome, bufferNomeAtributo);
            strcpy(d.atributos[i].sigla, bufferSiglaAtributo);
            d.atributos[i].nvl_hierarquia = bufferNvHierarquia;
        }
        counter++;
        printarRegistroFormatado(d, counter);
        free(d.atributos);
    }
    fclose(arquivo);
}

/*Função: recuperarRegistroN
    Descrição:
    Permite ao usuario recuperar o enésimo registro escrito em arquivo.
    parâmetros:
    n: numero do registro, começando do 0.
    retorno: enésimo registro.
*/
void recuperarRegistroN(int n){
    FILE * arquivo = fopen("dados.bin", "rb");
    char bufferNome[16];
    char bufferSigla[3];
    int bufferNumAtrib;
    char bufferNomeAtributo[16];
    char bufferSiglaAtributo[3];
    int bufferNvHierarquico;
    int i;
    dimensao d;
    int counter = 0;
    char sentinela = '|';
    while(!feof(arquivo)){
        if(counter != 0)
            fread(&sentinela, 1, 1, arquivo);
        if(sentinela != '|')
            printf("Atencao! Leitura de delimitador de fim de registro incorreto.\n");

        //Leitura do numero de atributos do registro de dimensao
        if(!fread(&bufferNumAtrib, sizeof(bufferNumAtrib), 1, arquivo))
            break;
        d.numAtributos = bufferNumAtrib;

        if(counter == n){
            fread(&bufferNome, sizeof(bufferNome), 1, arquivo);
            fread(&bufferSigla, sizeof(bufferSigla), 1, arquivo);

            strcpy(d.nome, bufferNome);
            strcpy(d.sigla, bufferSigla);
            d.atributos = (atributo *) malloc(d.numAtributos * sizeof(atributo));
            for(i = 0; i < bufferNumAtrib; i++){
                fread(&bufferNomeAtributo, sizeof(bufferNomeAtributo), 1, arquivo);
                fread(&bufferSiglaAtributo, sizeof(bufferSiglaAtributo), 1, arquivo);
                fread(&bufferNvHierarquico, sizeof(bufferNvHierarquico), 1, arquivo);
                strcpy(d.atributos[i].nome, bufferNomeAtributo);
                strcpy(d.atributos[i].sigla, bufferSiglaAtributo);
                d.atributos[i].nvl_hierarquia = bufferNvHierarquico;
            }
            printarRegistroFormatado(d, counter);
            counter++;
            free(d.atributos);
            break;
        } else {
            fseek(arquivo, sizeof(d.nome) + sizeof(d.sigla) + d.numAtributos*(sizeof(((struct atributo*)0)->nome) + sizeof(((struct atributo*)0)->nvl_hierarquia) + sizeof(((struct atributo*)0)->sigla)),SEEK_CUR);
            counter++;
        }
    }
    fclose(arquivo);
}


/*Função: salvarDados()
    Descrição:
    Salva os dados fornecidos pelo usuario em um arquivo em modo binario.
    parâmetros: vetor de dimensoes.
    retorno: nenhum.
*/
int salvarDados(dimensao * dimensoes, int numDim){
    FILE * arquivo = fopen("dados.bin", "wb");
    if(!arquivo){
        printf("Nao foi possível abrir o arquivo!");
        return -1;
    }
    int i;
    char delimitador = '|';
    for(i = 0; i < numDim; i++){
        fwrite(&dimensoes[i].numAtributos, sizeof(dimensoes[i].numAtributos), 1, arquivo);
        fwrite(&dimensoes[i].nome, sizeof(dimensoes[i].nome), 1, arquivo);
        fwrite(&dimensoes[i].sigla, sizeof(dimensoes[i].sigla), 1, arquivo);
        int j;
        for(j = 0; j < dimensoes[i].numAtributos; j++){
            fwrite(&dimensoes[i].atributos[j].nome, sizeof(dimensoes[i].atributos[j].nome), 1, arquivo);
            fwrite(&dimensoes[i].atributos[j].sigla, sizeof(dimensoes[i].atributos[j].sigla), 1, arquivo);
            fwrite(&dimensoes[i].atributos[j].nvl_hierarquia, sizeof(int), 1, arquivo);
        }
        fwrite(&delimitador, 1, 1, arquivo);
    }

   fclose(arquivo);
    return 1;
}

/*Função: printarRegistroFormatado()
    Descrição:
    Printa de forma organizada os dados sobre a dimensao d, que é o registo n.
    Parâmetros:
    d: dimensao a ser printada
    n: numero do registro dessa dimensao. Esse parametro é necessario pois a dimensao nao guarda em si qual posição no arquivo
    ele ocupa.
    retorno: nenhum.
*/
void printarRegistroFormatado(dimensao d, int n){
    printf("*********************************\n");
    printf("Registro numero %d.\n", n);
    printf("Campos: \n");
    printf("-Nome: %s\n", d.nome);
    printf("-Sigla: %s\n", d.sigla);
    printf("-Numero de atributos: %d\n", d.numAtributos);
    printf("-Vetor de atributos: \n");
    int i;
    for(i = 0; i < d.numAtributos; i++){
        printf("---> Atributo %d\n", i);
        printf("----Nome: %s\n", d.atributos[i].nome);
        printf("----Sigla: %s\n", d.atributos[i].sigla);
        printf("----Nivel Hierarquico: %d\n\n", d.atributos[i].nvl_hierarquia);
    }
}
