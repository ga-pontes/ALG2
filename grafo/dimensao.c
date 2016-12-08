#include "dimensao.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/* Fun��o: criarDimens�o
    argumentos:
        nome: nome da dimens�o a ser gerada.
        dimensoes: vetor de dimensoes
        n: numero de dimensoes preenchidas.
        maxAtributos: quantos atributos est�o relacionados
        a esta dimens�o.
    retorno:
        nenhum.
*/
void criarDimensao(char nome[16], dimensao * dimensoes, int n, int maxAtributos){
    dimensao d;
    d.atributos = (atributo *) malloc (maxAtributos * sizeof(atributo));
    d.numAtributos = 0;
    strcpy(d.nome, nome);
    //gerar sigla
    char * sigla = (char *) malloc (3*sizeof(char));
    sigla = gerarSigla(dimensoes, n, d.nome);
    strcpy(d.sigla, sigla);
    dimensoes[n] = d;
}


void inserirAtributo(char nome[16], dimensao *dim, int nvl){
    atributo a;
    strcpy(a.nome, nome);
    char * sigla = (char *) malloc(3*sizeof(char));
    sigla = gerarSiglaAtrib(dim->atributos, dim->numAtributos, nome);
    strcpy(a.sigla, sigla);
    a.nvl_hierarquia = nvl;
    dim->atributos[dim->numAtributos] = a;
    dim->numAtributos++;
}


/*Fun�ao gerarSiglaAtrib
documentar*/

char * gerarSiglaAtrib(atributo * atributos, int n, char nome[16]){
    char * sigla = (char *) malloc(2*sizeof(char));

    //variavel indice mantem registro de qual foi a ultima letra utilizada para gerar sigla.
    int indice = 0;

    //Por convencao do codigo, nome deve ser preenchido com \0 quando nao existir mais caracteres validos.
    if(nome[indice] != '\0'){
        sigla[0] = nome[indice];
        indice++;
        sigla[1] = '\0';
        sigla[2] = '\0';
        //checa se � primeira dimensao inserida
        if(n == 0){
            return sigla;
        }
    }
    else
        printf("Erro! Tentativa de gerar sigla a partir de nome vazio.");
    //Checa se a sigla � repetida em outra dimensao
    int i, igual = 0, siglaCorreta = 0;
    while(!siglaCorreta){
        igual = 0;
        for(i = 0; i < n; i++){
            if((sigla[0] == atributos[i].sigla[0] && sigla[1] == '\0') || (sigla[0] == atributos[i].sigla[0] && sigla[1] == atributos[i].sigla[1])){
                igual = 1;
                break;
            }
        }
        //A sigla est� igual a de outra dimens�o e deve ser mudada
        if(igual){
            if(nome[indice] != '\0') {
                //Usa proxima letra no nome
                sigla[1] = nome[indice];
                indice++;
            } else {
                //Nao h� mais letras no nome da dimensao.
                sigla[1] = '2';
            }
        } else {
            //Condicao de parada
            siglaCorreta = 1;
            return sigla;
        }
    }
    return sigla;
}


/* Fun��o: gerarSigla
    argumentos:
        dimensoes: lista de dimensoes ja existentes
        n: tamanho da lista de dimensoes
        nome: nome gerador da sigla.
        tamSigla: tamanho da sigla sem contar '\0'
    retorno:
        sigla de 3 caracteres referente ao nome, caracter fina denota fim de string.
*/
char * gerarSigla(dimensao *dimensoes, int n, char nome[15]){
    char * sigla = (char *) malloc(2*sizeof(char));

    //variavel indice mantem registro de qual foi a ultima letra utilizada para gerar sigla.
    int indice = 0;

    //Por convencao do codigo, nome deve ser preenchido com \0 quando nao existir mais caracteres validos.
    if(nome[indice] != '\0'){
        sigla[0] = nome[indice];
        indice++;
        sigla[1] = '\0';
        sigla[2] = '\0';
        //checa se � primeira dimensao inserida
        if(n == 0){
            return sigla;
        }
    }
    else
        printf("Erro! Tentativa de gerar sigla a partir de nome vazio.");
    //Checa se a sigla � repetida em outra dimensao
    int i, igual = 0, siglaCorreta = 0;
    while(!siglaCorreta){
        igual = 0;
        for(i = 0; i < n; i++){
            if((sigla[0] == dimensoes[i].sigla[0] && sigla[1] == '\0') || (sigla[0] == dimensoes[i].sigla[0] && sigla[1] == dimensoes[i].sigla[1])){
                igual = 1;
                break;
            }
            //Para cada dimensao, ve tambem as siglas de seus atributos.
            int iter;
            for(iter = 0; iter < dimensoes[i].numAtributos; iter++){
                if((sigla[0] == dimensoes[i].atributos[iter].sigla[0] && sigla[1] == '\0') || (sigla[0] == dimensoes[i].atributos[iter].sigla[0] && sigla[1] == dimensoes[i].atributos[iter].sigla[1])){
                    igual = 1;
                    break;
                }
            }
        }
        //A sigla est� igual a de outra dimens�o e deve ser mudada
        if(igual){
            if(nome[indice] != '\0') {
                //Usa proxima letra no nome
                sigla[1] = nome[indice];
                indice++;
            } else {
                //Nao h� mais letras no nome da dimensao.
                sigla[1] = '2';
            }
        } else {
            //Condicao de parada
            siglaCorreta = 1;
            return sigla;
        }
    }
    return sigla;
}





