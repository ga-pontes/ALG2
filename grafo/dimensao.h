#ifndef _DIMENSAO_H
#define _DIMENSAO_H



//Estrutura que receberá as dimensões
typedef struct dimensao {
    char nome[15];
    char sigla[2];
    struct atributo * atributos;
} dimensao;


//Estrutura que receberá os atributos
typedef struct atributo {
    char nome[15];
    char sigla[3];
} atributo;

char * gerarSiglaDim(dimensao *dimensoes, int n, char nome[15]);
void criarDimensao(char nome[15], dimensao * dimensoes, int n);

#endif // _DIMENSAO_H
