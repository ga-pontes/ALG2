#ifndef _ARQUIVO_H
#define _ARQUIVO_H
#include "dimensao.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Função: recuperarDados
    Descrição:
    Permite ao usuario recuperar dados salvos em modo binario sobre as dimensoes e atributos.
    parâmetros: nenhum.
    retorno: nenhum.
*/
void recuperarDados();

/*Função registrarDados
    Descrição: obtém do teclado do usuário as informações necessarias para a geração do grafo de derivação.
    Isto é, numero de dimensoes, numero de atributos, nome das dimensoes e nome dos atributos.
    parâmetros: nenhum.
    retorno: nenhum.
*/
lista_de_dimensao * registrarDados(FILE * fonte);


/*Função: salvarDados()
    Descrição:
    Salva os dados fornecidos pelo usuario em um arquivo em modo binario.
    parâmetros: vetor de dimensoes.
    retorno: nenhum.
*/
int salvarDados(dimensao * dimensoes, int numDim);

/*Função: printarRegistroFormatado()
    Descrição:
    Printa de forma organizada os dados sobre a dimensao d, que é o registo n.
    Parâmetros:
    d: dimensao a ser printada
    n: numero do registro dessa dimensao. Esse parametro é necessario pois a dimensao nao guarda em si qual posição no arquivo
    ele ocupa.
    retorno: nenhum.
*/
void printarRegistroFormatado(dimensao d, int n);
void recuperarRegistroN(int n);

#endif // _ARQUIVO_H
