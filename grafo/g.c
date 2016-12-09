/// GABRIEL PONTES 9313030
/// ANDRÉ DAHER BENEDETTI 9622772
/// NATHALIA MORENO PEREIRA 9266560
/// RAFAEL YONEZAWA DE MELLO 9313026

#include "g.h"

/// VERIFICA SE A LISTA DE VERTICES ESTA VAZIA
/// LV é uma lista de vértices
int estaVazioV(V *LV){
    if(LV->inicio == NULL){
        //printf("LV vazia.\n");
        return 1;
    }
    //printf("LV nao vazia.\n");
    return 0;
}

/// FUNÇÃO PARA CRIAR NOVO VÉRTICE
/// n é um indice para o vertice
/// s é a sigla do vértice
/// dim é o conjunto de dimensoes
v cria_vertice(int n, char *s, dimensao *dim){
    v novo;
    novo.i = n;
    strcpy(novo.sigla, s);
    novo.prox = NULL;
    novo.A = (A*) malloc (1 * sizeof(A));
    novo.A->inicio = NULL;
   //printf("Vertice %d criado.\n", n);

    novo.dim = dim;

    int i;
    for(i = 0; i < 10; i++){
        novo.nvl_de_cada_dimensao[i] = 0;
    }

    for(i = 0; i < 100; i++){
        novo.dimensoes_disponiveis[i] = 1;
    }

    return novo;
}

/// INSERE NOVO VERTICE NA LISTA DE VERTICES
/// LV = LISTA DE VERTICES
/// V = VERTICE A SER INSERIDO
v* insere_vertice(struct lista_de_vertices *LV, v *novo){
    v *aux;
    if(estaVazioV(LV)){
        LV->inicio = (v*) malloc (1 * sizeof(v));
        *LV->inicio = *novo;
    } else {

        aux = LV->inicio;
        //printf("Comecou no vertice %d\n", aux->i);
        while(aux->prox != NULL){
           // printf("Passou pelo vertice %d\n", aux->i);
            aux = aux->prox;
        }
        //printf("Parou no vertice %d\n", aux->i);
        aux->prox = (v*) malloc (1 * sizeof(v));
        *aux->prox = *novo;
    }
    return aux->prox;
    //printf("Vertice %d inserido no grafo.\n", novo->i);
}

/// FUNÇÃO PARA CRIAR UMA NOVA ARESTA
/// ORIGEM É O VERTICE DE ORIGEM DA ARESTA
/// DESTINO É O VERTICE DE DESTINO DA ARESTA
a cria_aresta(v* origem, v *destino){
    a novo;
    novo.prox = NULL;
    novo.origem = origem;
    novo.destino = destino;
    //printf("\nAresta de %s para %s criada.\n", origem->sigla, destino->sigla);
    return novo;
}

/// VERIFICA SE A LISTA DE ARESTAS ESTA VAZIA
int estaVazioA(A *LA){
    if(LA->inicio == NULL){
        return 1;
    }
    return 0;
}

/// FUNÇÃO PARA INSERIR UMA ARESTA NUMA LISTA
void insere_aresta(v *origem, a *novo){
    A* LA = origem->A;
    if(estaVazioA(LA)){
        //printf("Lista de arestas estava vazia.\n");
        LA->inicio = (a*) malloc (1 * sizeof(a));
        *LA->inicio = *novo;
        //printf("Aresta foi inserida no inicio da lista.\n");
    } else {
        a *aux;
        aux = LA->inicio;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox  = (a*) malloc (1 * sizeof(a));
        *aux->prox = *novo;
        //printf("Aresta foi inserida no final da lista.\n");
    }
   /* printf("\nAresta de %s para %s criada.\n", novo->origem->sigla, novo->destino->sigla);
    printf("Aresta %d -> %d inserida no grafo.\n", origem->i, novo->destino->i);*/
}

/// FUNÇÃO PARA GERAR A SIGLA DE UM VÉRTICE
/// BASEADO NAS SUAS DIMENSOES E HIERARQUIA
/// qd = QNT TOTAL DE DIMENSOES + ATRIBUTOS
void gerarSigladoVertice(v *vert, int qd){
    char sigla[100];
    sigla[0] = '\0';
    int i;
    for(i = 0; i < qd; i++){
        if(vert->nvl_de_cada_dimensao[i] == 0){
            strcat(sigla, vert->dim[i].sigla);
        } else if(vert->nvl_de_cada_dimensao[i] <= vert->dim[i].numAtributos){
            strcat(sigla, vert->dim[i].atributos[vert->nvl_de_cada_dimensao[i]-1].sigla);
        }
    }
    strcpy(vert->sigla, sigla);
}

/// FUNÇÃO QUE GERA SIGLA DOS VERTICES
/// QUE CONTÉM SOMENTE DIMENSÕES
void gerarSigladoVerticeD(v *vert, int qd){
    char sigla[100];
    sigla[0] = '\0';
    int i;
    for(i = 0; i < qd; i++){
        if(vert->dimensoes_disponiveis[i]){
            strcat(sigla, vert->dim[i].sigla);
        }
    }
    strcpy(vert->sigla, sigla);
}

/// FUNÇÃO PARA GERAR AS COMBINAÇÕES "FILHAS"
/// DE UM VÉRICE DE DIMENSOES E HIERARQUIAS
/// LV = LISTA A SER ADD O VÉRTICE
/// VERTICE A SER RECOMBINADO
/// qd = QNT TOTAL DE DIMENSOES + ATRIBUTOS
/// ST MATRIZ DE SIGLAS DAS DIMENSOES E ATRIBUTOS
/// FLAG_ISOLADOS SERVE COMO INTERRUPÇÃO DA GEREAÇÃO DO GRAFO
void permuta_dim(V *LV, v *vert, int qd, char **ST, int flag_isolados[], int total_de_elementos){
    v nv;
    a ar;

    int flag_para_gerar_vertice = 0;
    int it_dim;
    for(it_dim = 0; it_dim < qd; it_dim++){
        if(vert->nvl_de_cada_dimensao[it_dim] <= vert->dim[it_dim].numAtributos){
            flag_para_gerar_vertice++;
        }
    }

    int i;
    if(flag_para_gerar_vertice > 1){
        for(it_dim=0; it_dim < qd; it_dim++){
            nv = cria_vertice(vert->i + (it_dim+1), "", vert->dim);
            for(i = 0; i < 10; i++)
                nv.nvl_de_cada_dimensao[i] = vert->nvl_de_cada_dimensao[i];
            nv.nvl_de_cada_dimensao[it_dim]++;
            gerarSigladoVertice(&nv, qd);

            v* end = insere_vertice(LV, &nv);

            ar = cria_aresta(vert, end);
            insere_aresta(vert, &ar);

        }
    } else {
        int m;
        for(m = 0; m < total_de_elementos; m++){
            printf("%s %s\n", ST[m], vert->sigla);
            if(strcmp(ST[m], vert->sigla) == 0){
                flag_isolados[m] = 1;
            }
        }
    }


    //return LV;
}

/// FUNÇÃO QUE APONTAS AS ARESTAS ISOLADAS
/// PARA OUTRAS ARESTAS ISOLADAS E PARA ALL.
v* cria_arestas_das_isoladas(V *LV, int qd, char **ST, int total_de_elementos, dimensao *dimensoes){
    dimensao *D_aux;
    v *buscador_atual;
    v *buscador_prox;
    v *all = (v*) calloc (1, sizeof(v));
    *all = cria_vertice(1000, "ALL", dimensoes);
    a nova_aresta;

    insere_vertice(LV, all);
    int i;
    for(i = 0; i < 3; i++){
        D_aux = &(dimensoes[i]);
        //SE NÃO EXISTEM ATRIBUTOS
        if(D_aux->numAtributos == 0){
            //APONTA VERTICE DA DIMENSAO ISOLADO PRA ALL
            buscador_atual = LV->inicio;
            while(strcmp(D_aux->sigla, buscador_atual->sigla) != 0){
                buscador_atual = buscador_atual->prox;
            }
            nova_aresta = cria_aresta(buscador_atual, all);
            insere_aresta(buscador_atual, &nova_aresta);
        }
        //SE EXISTEM ATRIBUTOS
        int NH;
        if(D_aux->numAtributos > 0){
            NH = 0;
            //ENQNT NH < NRO_ATRIBUTOS
            while(NH <= D_aux->numAtributos){
                buscador_atual = LV->inicio;
                buscador_prox = LV->inicio;
                //PROCURA NH ATUAL E PROX_NH
                //CRIA ARESTA ENTRE NH E PROX_NH
                if(NH == 0){
                    //printf("CASO 0: Nvl de hierarquia: %d\n", NH);

                    //printf("Estamos procurando a sigla %s.\n", D_aux->sigla);
                    while(strcmp(buscador_atual->sigla, D_aux->sigla) != 0){
                        buscador_atual = buscador_atual->prox;
                    }
                   // printf("Encontrou o vertice %s isolado.\n", buscador_atual->sigla);
                    buscador_prox = buscador_atual->prox;

                    //printf("Estamos procurando a sigla %s.\n", D_aux->atributos[NH].sigla);
                    while(strcmp(buscador_prox->sigla, D_aux->atributos[NH].sigla) != 0){
                        buscador_prox = buscador_prox->prox;
                    }
                    //printf("Encontrou o vertice maior na h %s isolado.\n", buscador_prox->sigla);
                    nova_aresta = cria_aresta(buscador_atual, buscador_prox);
                    insere_aresta(buscador_atual, &nova_aresta);

                    NH++;
                }
                if(NH > 0 && NH < D_aux->numAtributos){
                   // printf("CASO 1: Nvl de hierarquia: %d\n", NH);

                    //printf("Estamos procurando a sigla %s.\n", D_aux->atributos[NH-1].sigla);
                    while(strcmp(buscador_atual->sigla, D_aux->atributos[NH-1].sigla) != 0){
                        buscador_atual = buscador_atual->prox;
                    }
                    //printf("Encontrou o vertice %s isolado.\n", buscador_atual->sigla);
                    buscador_prox = buscador_atual->prox;
                    while(strcmp(buscador_prox->sigla, D_aux->atributos[NH].sigla) != 0){
                        buscador_prox = buscador_prox->prox;
                    }
                    //printf("Encontrou o vertice maior na h %s isolado.\n", buscador_prox->sigla);
                    nova_aresta = cria_aresta(buscador_atual, buscador_prox);
                    insere_aresta(buscador_atual, &nova_aresta);

                    NH++;
                }
                 //QUANDO NH == NRO_ATRIBUTOS
                if(NH == D_aux->numAtributos){
                    //printf("CASO 2: Nvl de hierarquia: %d\n", NH);
                    //APONTA VERTICE DA HRQUIA MAIS ALTO ISOLADO PRA ALL
                    //printf("Estamos procurando a sigla %s.\n", D_aux->atributos[NH-1].sigla);
                    while(strcmp(D_aux->atributos[NH-1].sigla, buscador_atual->sigla) != 0){
                        buscador_atual = buscador_atual->prox;
                    }
                    nova_aresta = cria_aresta(buscador_atual, all);
                    insere_aresta(buscador_atual, &nova_aresta);

                    NH++;
                }
            }
        }
    }
    return all;
}

///FUNÇÃO QUE GERA O GRAFO DE DERIVAÇÃO DAS HIERARQUIAS
void gerar_grafo_de_derivacao(lista_de_dimensao *LD){
    /*int qd = LD->tamanho;*/
    //int total_de_elementos;// = LD->TOTAL

    //SINALIZADOR DE DIM/ATRIBUTO JÁ ISOLADO
    int *flag_isolados;
    flag_isolados = (int*) calloc (LD->totalElementos, sizeof(int));

    //VETOR DE ISOLADOS
    int it;
    printf("%d\n", LD->totalElementos);
    for(it = 0; it < LD->totalElementos; it++){
        flag_isolados[it] = 0;
    }

    //CONJUNTO VAZIO É QUANDO UMA SIGLA É ISOLADA DE TODAS AS OUTRAS.
    //PRECISA SER PASSADO COMO REF PARA SER OPERADO POR FUNCOES EXTERNAS
    int flag_continuidade = 1;
    v vert = cria_vertice(0, "", LD->dimensoes);
    vert.i = 0;
    gerarSigladoVertice(&vert, LD->tamanho);



    //VARIÁVEIS QUE GERAM O GRAFO
    v *aux_v = &vert;
    v *aux_final;
    V nova_lista;
    nova_lista.inicio = &vert;
    int cnt;

    while(flag_continuidade){
        printf("ok1\n");

        //ENCONTRA FINAL "ATUAL" DA LISTA
        aux_final = &vert;
        while(aux_final->prox != NULL){
            aux_final = aux_final->prox;
        }
        v* aux_v7 = &vert;

        //gera "filhos" do vértice atual no final da lista
        printf("gerando filhos do vert %s\n", aux_v->sigla);
        permuta_dim(&nova_lista, aux_v, LD->tamanho, LD->siglas, flag_isolados, LD->totalElementos);
        printf("gerou.\n");

        //passa para o próximo vertice
        aux_v = aux_v->prox;

        //TESTA CONDIÇÃO DE PARADA
        cnt = 0;
        for(it = 0; it < LD->totalElementos; it++){
            printf("%d ", flag_isolados[it]);
            if(flag_isolados[it] == 1)
                cnt++;
        }
        printf("\n");

        if(cnt == LD->totalElementos)
            flag_continuidade = 0;
    }
        //CRIA AS ARESTAS ENTRE ISOLADOS E ALL
        cria_arestas_das_isoladas(&nova_lista, LD->tamanho, &(LD->siglas), LD->totalElementos, LD->dimensoes);

        //IMPRIME VERTICES DO GRAFO
        v* aux_v7 = &vert;
        while(aux_v7 != NULL){
            puts(aux_v7->sigla);
            aux_v7=aux_v7->prox;
        }

       /* aux_v7 = &vert;
        a aux_A;
        while(aux_v7 != NULL){

            aux_v7=aux_v7->prox;
        }

        */
        generateDot(&vert);
}

/// FUNÇAO QUE GERA O GRAFO DOS CORTES DAS DIMENSOES
void gera_grafo_de_dimensoes(lista_de_dimensao *LD){
    lista_de_dimensao NOVA_LISTA;
    int i;

    NOVA_LISTA.siglas = (char**) malloc (10 * sizeof(char*));
    NOVA_LISTA.dimensoes = (dimensao*) malloc (10 * sizeof(dimensao));

    for(i = 0; i < LD->tamanho; i++){
        NOVA_LISTA.siglas[i] = (char*) malloc (10* sizeof(char));
        strcpy(NOVA_LISTA.siglas[i], LD->dimensoes[i].sigla);
        puts(NOVA_LISTA.siglas[i]);

        criarDimensao(NOVA_LISTA.siglas[i], NOVA_LISTA.dimensoes, i, 0);

    }
    NOVA_LISTA.totalElementos = LD->tamanho;
    NOVA_LISTA.tamanho = LD->tamanho;

    //SINALIZADOR DE DIM/ATRIBUTO JÁ ISOLADO
    int *flag_isolados;
    flag_isolados = (int*) calloc (LD->tamanho, sizeof(int));

    //VETOR DE ISOLADOS
    int it;
    printf("%d\n", NOVA_LISTA.totalElementos);
    for(it = 0; it < NOVA_LISTA.totalElementos; it++){
        flag_isolados[it] = 0;
    }

    //CONJUNTO VAZIO É QUANDO UMA SIGLA É ISOLADA DE TODAS AS OUTRAS.
    //PRECISA SER PASSADO COMO REF PARA SER OPERADO POR FUNCOES EXTERNAS
    int flag_continuidade = 1;
    v vert = cria_vertice(0, "", NOVA_LISTA.dimensoes);
    vert.i = 0;
    gerarSigladoVertice(&vert, NOVA_LISTA.tamanho);



    //VARIÁVEIS QUE GERAM O GRAFO
    v *aux_v = &vert;
    v *aux_final;
    V nova_lista;
    nova_lista.inicio = &vert;
    int cnt;

    while(flag_continuidade){
        printf("ok1\n");



        //ENCONTRA FINAL "ATUAL" DA LISTA
        aux_final = &vert;
        while(aux_final->prox != NULL){
            aux_final = aux_final->prox;
        }
        v* aux_v7 = &vert;

        //gera "filhos" do vértice atual no final da lista
        printf("gerando filhos do vert %s\n", aux_v->sigla);

        permuta_dim(&nova_lista, aux_v, NOVA_LISTA.tamanho, NOVA_LISTA.siglas, flag_isolados, NOVA_LISTA.totalElementos);
        printf("gerou.\n");

        //passa para o próximo vertice
        aux_v = aux_v->prox;

        //TESTA CONDIÇÃO DE PARADA
        cnt = 0;
        for(it = 0; it < NOVA_LISTA.totalElementos; it++){
            printf("%d ", flag_isolados[it]);
            if(flag_isolados[it] == 1)
                cnt++;
        }
        printf("\n");

        if(cnt == NOVA_LISTA.totalElementos)
            flag_continuidade = 0;
    }
        //CRIA AS ARESTAS ENTRE ISOLADOS E ALL
        cria_arestas_das_isoladas(&nova_lista, NOVA_LISTA.tamanho, &(NOVA_LISTA.siglas), NOVA_LISTA.totalElementos, NOVA_LISTA.dimensoes);

        //IMPRIME VERTICES DO GRAFO
        v* aux_v7 = &vert;
        while(aux_v7 != NULL){
            puts(aux_v7->sigla);
            aux_v7=aux_v7->prox;
        }

       /* aux_v7 = &vert;
        a aux_A;
        while(aux_v7 != NULL){

            aux_v7=aux_v7->prox;
        }

        */
        generateDot(&vert);
}
