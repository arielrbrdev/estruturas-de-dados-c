#ifndef ABP_C
#define ABP_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abp.h"

Abp* criaAbp(tipoItem val){
    Abp *Arv = (Abp*) malloc(sizeof(Abp));
    Arv->esq = NULL;
    Arv->dir = NULL;
    Arv->item = val;  
    return Arv;
}

int buscaAbp(Abp* arv, tipoItem chave) {
    Abp* atual = arv;
    while (atual != NULL) {
        if (chave.cpf == atual->item.cpf) {
            printf("Registro encontrado: CPF = %lld\n", chave.cpf);
            return 1;
        }
        else if (chave.cpf < atual->item.cpf) {
            atual = atual->esq;
        }
        else {
            atual = atual->dir;
        }
    }
    printf("Registro com CPF = %lld nao encontrado.\n", chave.cpf);
    return 0;
}

void buscaInterAbp(Abp* raiz, int idadeBase, int flag){
    if (raiz == NULL) return ;

    buscaInterAbp(raiz->esq, idadeBase, flag);

    int condicao = 0;
    switch (flag){
        case 1: condicao = (raiz->item.idade < idadeBase); break;
        case 2: condicao = (raiz->item.idade > idadeBase); break;
        case 3: condicao = (raiz->item.idade <= idadeBase); break;
        case 4: condicao = (raiz->item.idade >= idadeBase); break;
        default:
            printf("Flag invalida! Use 1 (<), 2 (>), 3 (<=), 4 (>=)\n");
            return;
    }

    buscaInterAbp(raiz->dir, idadeBase, flag);
}

void insereValAbpIdade(Abp* Arv, tipoItem val) {
    Abp* aux = Arv;
    while (aux != NULL) {
        if (val.idade < aux->item.idade) {
            if (aux->esq == NULL) {
                aux->esq = criaAbp(val);
                return;
            }
            aux = aux->esq;
        } else {
            if (aux->dir == NULL) {
                aux->dir = criaAbp(val);
                return;
            }
            aux = aux->dir;
        }
    }
    printf("Erro: Árvore raiz == NULL\n");
}

void insereValAbpCpf(Abp* Arv, tipoItem val) {
    Abp* aux = Arv;
    while (aux != NULL) {
        if (val.cpf < aux->item.cpf) {
            if (aux->esq == NULL) {
                aux->esq = criaAbp(val);
                return;
            }
            aux = aux->esq;
        } else {
            if (aux->dir == NULL) {
                aux->dir = criaAbp(val);
                return;
            }
            aux = aux->dir;
        }
    }
    printf("Erro: Arvore raiz == NULL\n");
}

void liberarArvoreABP(Abp* raiz) {
    if (raiz != NULL) {
        liberarArvoreABP(raiz->esq);
        liberarArvoreABP(raiz->dir);
        free(raiz);
    }
}

#endif