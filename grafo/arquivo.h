#ifndef _ARQUIVO_H
#define _ARQUIVO_H
#include "dimensao.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Fun��o: recuperarDados
    Descri��o:
    Permite ao usuario recuperar dados salvos em modo binario sobre as dimensoes e atributos.
    par�metros: nenhum.
    retorno: nenhum.
*/
void recuperarDados();

/*Fun��o registrarDados
    Descri��o: obt�m do teclado do usu�rio as informa��es necessarias para a gera��o do grafo de deriva��o.
    Isto �, numero de dimensoes, numero de atributos, nome das dimensoes e nome dos atributos.
    par�metros: nenhum.
    retorno: nenhum.
*/
lista_de_dimensao * registrarDados(FILE * fonte);


/*Fun��o: salvarDados()
    Descri��o:
    Salva os dados fornecidos pelo usuario em um arquivo em modo binario.
    par�metros: vetor de dimensoes.
    retorno: nenhum.
*/
int salvarDados(dimensao * dimensoes, int numDim);

/*Fun��o: printarRegistroFormatado()
    Descri��o:
    Printa de forma organizada os dados sobre a dimensao d, que � o registo n.
    Par�metros:
    d: dimensao a ser printada
    n: numero do registro dessa dimensao. Esse parametro � necessario pois a dimensao nao guarda em si qual posi��o no arquivo
    ele ocupa.
    retorno: nenhum.
*/
void printarRegistroFormatado(dimensao d, int n);
void recuperarRegistroN(int n);

#endif // _ARQUIVO_H
