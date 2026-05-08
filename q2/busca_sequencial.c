#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TADlista.h"
#include <time.h>

void insereNaLista(tipoLista* lista, int vetor[], int tam){
    int i = 0;
    tipoNo* aux;
    
    aux = (tipoNo*)malloc(sizeof(tipoNo));
    aux->prox = NULL;

    if (lista->prim == NULL){
        lista->prim = aux;
        lista->ult = aux;
        aux->dados = vetor[i];
    }

    for (i = 1; i < tam; i++){
    aux = (tipoNo*)malloc(sizeof(tipoNo));
    aux-> dados = vetor[i];
    lista->ult->prox = aux;
    lista->ult = aux;;
    }
}

int buscaSequencial(tipoLista* lista, int chave){
    tipoNo* aux = lista->prim;
    while (aux != NULL){
        if (aux->dados == chave){
        return chave;
       }
       else{aux = aux->prox;}
    }
    return 0;
}

void criarLista(tipoLista*lista){
    lista->prim=NULL;
    lista->ult=NULL;
}
