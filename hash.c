#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

int posicaoInsert = 0;
hashItem hashNULO = {NULL, 0, -1};

int hashFunc(long int cpf){
    return (cpf * 10007) % TAM_HASH;
}

void criaHashItem(hashItem *itemHash, tipoItem item, unsigned int indexArq) {
    itemHash->index = indexArq;
    itemHash->prox = NULL;
    itemHash->cpf = item.cpf;
}

void inicializaHash(hashItem hash[]) {
    for (int i = 0; i < TAM_HASH; i++) {
        hash[i].cpf = -1;
        hash[i].prox = NULL;
        hash[i].index = 0;
    }
}

void inserirHash(hashItem hash[], tipoItem item,int indArq) {
    int ind = hashFunc(item.cpf);

    if (hash[ind].cpf == -1) {
        // Posição vazia, insere direto
        hash[ind].cpf = item.cpf;
        hash[ind].index = indArq;
        hash[ind].prox = NULL;
    } else {
        // Colisão: cria novo nó dinamicamente e insere no início da lista
        hashItem* novo = malloc(sizeof(hashItem));
        if (!novo) {
            printf("Erro de alocação!\n");
            return;
        }
        novo->cpf = item.cpf;
        novo->index = indArq;
        novo->prox = hash[ind].prox;
        hash[ind].prox = novo;
    }
}

hashItem buscaHash(hashItem hash[], long int cpf) {
    int ind = hashFunc(cpf);
    hashItem* aux = &hash[ind];

    while (aux != NULL && aux->cpf != -1) {
        if (aux->cpf == cpf) {
            return *aux;
        }
        aux = aux->prox;
    }
    return hashNULO;
}

void popularSistema(FILE *arq, Abp *arvCpf, Abp *arvIdade, hashItem hash[]){
    tipoItem item;
    int posArq = 0;
    while(fread(&item, sizeof(tipoItem), 1, arq)){
        insereValAbpCpf(arvCpf, item);
        insereValAbpIdade(arvIdade, item);
        inserirHash(hash, item, posArq);
        posArq++;
    }
}

int buscaArq(FILE *arquivo, int idadeBusca, int flag) {
    tipoItem item;
    int encontrou = 0;

    if (flag < 1 || flag > 4) {
        printf("Flag invalida! Use 1 (<), 2 (>), 3 (<=), 4 (>=)\n");
        return 0;
    }

    fseek(arquivo, 0, SEEK_SET);

    while (fread(&item, sizeof(tipoItem), 1, arquivo) == 1) {
        int condicao = 0;

        switch (flag) {
            case 1: condicao = (item.idade < idadeBusca); break;
            case 2: condicao = (item.idade > idadeBusca); break;
            case 3: condicao = (item.idade <= idadeBusca); break;
            case 4: condicao = (item.idade >= idadeBusca); break;
        }
        if (condicao) {
            encontrou += 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum registro encontrado com os criterios especificados.\n");
    }
    return encontrou;
}

void buscaSeqArq(FILE *arquivo, long long int cpfBusca) {
    tipoItem item;
    fseek(arquivo, 0, SEEK_SET);

    while (fread(&item, sizeof(tipoItem), 1, arquivo) == 1){
        if (item.cpf == cpfBusca) {
            printf("Registro encontrado:\n");
            printf("CPF: %lld | Idade: %u | Agencia: %d | Nome: %s | Email: %s\n",
                   item.cpf, item.idade, item.agencia, item.nome, item.email);
            return;
        }
    }

    printf("CPF %lld nao encontrado.\n", cpfBusca);
}

void liberarHash(hashItem hash[]) {
    for (int i = 0; i < TAM_HASH; i++) {
        hashItem *curr = hash[i].prox;
        while (curr) {
            hashItem *tmp = curr;
            curr = curr->prox;
            free(tmp);
        }
    }
}

