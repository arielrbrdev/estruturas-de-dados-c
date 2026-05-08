#ifndef HASH_H
#define HASH_H

#include "abp.h"
#include <stdio.h>

#define TAM_HASH 10000

typedef struct hashItem {
    struct hashItem *prox;
    unsigned int index;
    long long int cpf;
} hashItem;

int hashFunc(long int cpf);
void criaHashItem(hashItem *itemHash, tipoItem item, unsigned int indexArq);
void inicializaHash(hashItem hash[]);
void inserirHash(hashItem hash[], tipoItem item,int indArq);
hashItem buscaHash(hashItem hash[], long int cpf);
void popularSistema(FILE *arq, Abp *arvCpf,Abp *arvIdade, hashItem hash[]);
int buscaArq(FILE *arquivo, int idadeBusca, int flag);
void buscaSeqArq(FILE *arquivo, long long int cpfBusca);
void liberarHash(hashItem hash[]);

#endif
