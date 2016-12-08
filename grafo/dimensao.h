#ifndef _DIMENSAO_H
#define _DIMENSAO_H

//Estrutura que receberá as dimensões
typedef struct dimensao {
    int numAtributos;
    char nome[16];
    char sigla[3];
    struct atributo * atributos;
} dimensao;


//Estrutura que receberá os atributos
typedef struct atributo {
    char nome[16];
    char sigla[3];
} atributo;

char * gerarSigla(dimensao *dimensoes, int n, char nome[16]);
void criarDimensao(char nome[15], dimensao * dimensoes, int n, int maxAtributos);
char * gerarSiglaAtrib(atributo * atributos, int n, char nome[16]);
void inserirAtributo(char nome[16], dimensao * dim);

#endif // _DIMENSAO_H
