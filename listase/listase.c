#include <stdio.h>
#include <stdlib.h>
#include "listase.h"

/* ── Estruturas internas ─────────────────────────────────────────── */

typedef struct elem_lse t_elemento_lse;

struct elem_lse {
    void*           carga_util;
    t_elemento_lse* prox;
};

struct lse {
    t_elemento_lse* primeiro;
    t_elemento_lse* ultimo;
    int             tamanho;
};

/* ── Helper interno ──────────────────────────────────────────────── */

static t_elemento_lse* criar_elem(void* carga) {
    t_elemento_lse* novo = malloc(sizeof(t_elemento_lse));
    novo->carga_util = carga;
    novo->prox       = NULL;
    return novo;
}

/* ── Ciclo de vida ───────────────────────────────────────────────── */

t_lse* criar_lse() {
    t_lse* nova    = malloc(sizeof(t_lse));
    nova->primeiro = NULL;
    nova->ultimo   = NULL;
    nova->tamanho  = 0;
    return nova;
}

/* Libera todos os nós e a lista; liberar_carga pode ser NULL */
void destruir_lse(t_lse* lse, void (*liberar_carga)(void*)) {
    t_elemento_lse* cam = lse->primeiro;
    while (cam != NULL) {
        t_elemento_lse* prox = cam->prox;
        if (liberar_carga) liberar_carga(cam->carga_util);
        free(cam);
        cam = prox;
    }
    free(lse);
}

/* ── Inserção ────────────────────────────────────────────────────── */

/* FIX: a verificação de ultimo==NULL deve ser feita ANTES do incremento */
void inserir_lse(t_lse* lse, void* carga) {
    t_elemento_lse* novo = criar_elem(carga);
    novo->prox    = lse->primeiro;
    lse->primeiro = novo;
    if (lse->ultimo == NULL)   /* lista estava vazia */
        lse->ultimo = novo;
    lse->tamanho++;
}

void inserir_final_lse(t_lse* lse, void* carga) {
    t_elemento_lse* novo = criar_elem(carga);
    if (lse->primeiro == NULL) {
        lse->primeiro = novo;
        lse->ultimo   = novo;
    } else {
        lse->ultimo->prox = novo;
        lse->ultimo       = novo;
    }
    lse->tamanho++;
}

/* ── Remoção ─────────────────────────────────────────────────────── */

/* FIX: adicionadas condições nos if/else; retorna void* em vez de void */
void* remover_lse(t_lse* lse) {
    if (lse->primeiro == NULL) return NULL;   /* lista vazia */

    t_elemento_lse* deletado = lse->primeiro;
    void*           carga    = deletado->carga_util;

    lse->primeiro = deletado->prox;
    if (lse->primeiro == NULL)   /* lista ficou vazia */
        lse->ultimo = NULL;

    free(deletado);
    lse->tamanho--;
    return carga;
}

/* FIX: implementação que estava em branco */
void* remover_final_lse(t_lse* lse) {
    if (lse->primeiro == NULL) return NULL;

    void* carga;

    /* Um único elemento */
    if (lse->primeiro == lse->ultimo) {
        carga         = lse->primeiro->carga_util;
        free(lse->primeiro);
        lse->primeiro = NULL;
        lse->ultimo   = NULL;
        lse->tamanho--;
        return carga;
    }

    /* Percorre até o penúltimo */
    t_elemento_lse* penultimo = lse->primeiro;
    while (penultimo->prox != lse->ultimo)
        penultimo = penultimo->prox;

    carga = lse->ultimo->carga_util;
    free(lse->ultimo);
    penultimo->prox = NULL;
    lse->ultimo     = penultimo;
    lse->tamanho--;
    return carga;
}

/* ── Acesso e exibição ───────────────────────────────────────────── */

/* FIX: retorna void* em vez de void */
void* acessar_lse(t_lse* lse, int pos) {
    if (pos < 1 || pos > lse->tamanho) return NULL;

    t_elemento_lse* atual = lse->primeiro;
    for (int i = 1; i < pos; i++)
        atual = atual->prox;

    return atual->carga_util;
}

/* FIX: recebe callback para imprimir qualquer tipo de carga */
void imprimir_lse(t_lse* lse, void (*imprimir_carga)(void*)) {
    t_elemento_lse* cam = lse->primeiro;
    while (cam != NULL) {
        imprimir_carga(cam->carga_util);
        cam = cam->prox;
    }
    printf("\n");
}
