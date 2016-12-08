#include "arquivo.h"

/*Função criarGrafo
    Descrição: obtém do teclado do usuário as informações necessarias para a geração do grafo de derivação.
    Isto é, numero de dimensoes, numero de atributos, nome das dimensoes e nome dos atributos.
    parâmetros: nenhum.
    retorno: nenhum.
*/
void criarGrafo(){
    int numDim, numAtr;
    //Coletando informações do usuario
    printf("Digite o numero de dimensoes que o grafo possuirá. \n");
    fflush(stdin);
    scanf("%d", &numDim);

    //Alocando vetor de dimensoes
    dimensao * dimensoes = (dimensao *) malloc(numDim*sizeof(dimensao));

    //Coletando informações sobre as dimensoes
    int i;
    for(i = 0; i < numDim; i++){
        printf("Digite o nome da dimensao %d\n", i+1);
        fflush(stdin);
        char nome[16];
        fflush(stdin);
        fgets(nome, 16, stdin);
        printf("Digite a quantidade de atributos dessa dimensao.\n");
        fflush(stdin);
        scanf("%d", &numAtr);
        criarDimensao(nome, dimensoes, i, numAtr);

        int j;
        //Coletando informações sobre atributos
        for(j = 0; j < numAtr; j++){
            printf("Digite, em ordem crescente de hierarquia, o nome dos atributos dessa dimensão.\n");
            printf("Atributo %d: \n", j + 1);
            fflush(stdin);
            fgets(nome, 16, stdin);
            inserirAtributo(nome, &dimensoes[i]);
        }
    }
    salvarDados(dimensoes, numDim);
}

/*Função: recuperarDados
    Descrição:
    Permite ao usuario printar na tela todos os dados salvos em modo binario sobre as dimensoes e atributos.
    parâmetros: nenhum.
    retorno: nenhum.
*/
void recuperarDados(){
    FILE * arquivo = fopen("dados.bin", "rb");
    char buffer;
    int test;
    char bufferNome[16];
    char bufferSigla[3];
    int bufferNumAtrib;
    char bufferNomeAtributo[16];
    char bufferSiglaAtributo[3];
    int i;
    dimensao d;
    char sentinela;
    int counter = 0;
    while(!feof(arquivo)){
        if(counter != 0)
            fread(&sentinela, 1, 1, arquivo);
        if(sentinela == '*'){
            while(fread(&sentinela, 1, 1, arquivo) && sentinela != '|');
        } else if(sentinela != '|' )
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
            strcpy(d.atributos[i].nome, bufferNomeAtributo);
            strcpy(d.atributos[i].sigla, bufferSiglaAtributo);
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
    char buffer;
    int test;
    char bufferNome[16];
    char bufferSigla[3];
    int bufferNumAtrib;
    char bufferNomeAtributo[16];
    char bufferSiglaAtributo[3];
    int i;
    dimensao d;
    int counter = 0;
    char sentinela;
    while(!feof(arquivo)){
        if(counter != 0)
            fread(&sentinela, 1, 1, arquivo);
        if(sentinela == "|")
            printf("ok!");
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
                strcpy(d.atributos[i].nome, bufferNomeAtributo);
                strcpy(d.atributos[i].sigla, bufferSiglaAtributo);
            }
            printarRegistroFormatado(d, counter);
            counter++;
            free(d.atributos);
        } else {
            fseek(arquivo, sizeof(d.nome) + sizeof(d.sigla) + d.numAtributos*sizeof(atributo) ,SEEK_CUR);
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
    printf("-Nome: %s", d.nome);
    printf("-Sigla: %s\n", d.sigla);
    printf("-Numero de atributos: %d\n", d.numAtributos);
    printf("-Vetor de atributos: \n");
    int i;
    for(i = 0; i < d.numAtributos; i++){
        printf("---> Atributo %d\n", i);
        printf("----Nome: %s", d.atributos[i].nome);
        printf("----Sigla: %s\n", d.atributos[i].sigla);
    }
}
