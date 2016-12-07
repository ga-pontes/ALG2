#include "dimensao.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void criarDimensao(char nome[15], dimensao * dimensoes, int n){
    dimensao d;
    strcpy(d.nome, nome);
    //gerar sigla
    char * sigla = (char *) malloc(3*sizeof(char));
    sigla = gerarSiglaDim(dimensoes, n, d.nome);
    strcpy(d.sigla, sigla);

    dimensoes[n] = d;
    printf("Dimensao %s criada. Sigla: %s\n", nome, d.sigla);
}

/* Função: gerarSiglaDim
    argumentos:
        dimensoes: lista de dimensoes ja existentes
        n: tamanho da lista de dimensoes
        nome: nome gerador da sigla.
    retorno:
        sigla de 2 caracteres referente ao nome
*/
char * gerarSiglaDim(dimensao *dimensoes, int n, char nome[15]){
    char * sigla = (char *) malloc(2*sizeof(char));

    //variavel indice mantem registro de qual foi a ultima letra utilizada para gerar sigla.
    int indice = 0;

    //Por convencao do codigo, nome deve ser preenchido com \0 quando nao existir mais caracteres validos.
    if(nome[indice] != '\0'){
        sigla[0] = nome[indice];
        indice++;
        sigla[1] = '\0';
        sigla[2] = '\0';
        //checa se é primeira dimensao inserida
        if(n == 0){
            return sigla;
        }
    }
    else
        printf("Erro! Tentativa de gerar sigla a partir de nome vazio.");
    //Checa se a sigla é repetida em outra dimensao
    int i, igual = 0, siglaCorreta = 0;
    while(!siglaCorreta){
        igual = 0;
        for(i = 0; i < n; i++){
            if((sigla[0] == dimensoes[i].sigla[0] && sigla[1] == '\0') || (sigla[0] == dimensoes[i].sigla[0] && sigla[1] == dimensoes[i].sigla[1])){
                igual = 1;
                break;
            }
        }
        //A sigla está igual a de outra dimensão e deve ser mudada
        if(igual){
            if(nome[indice] != '\0') {
                //Usa proxima letra no nome
                sigla[1] = nome[indice];
                indice++;
            } else {
                //Nao há mais letras no nome da dimensao.
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
