#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listase.h"

/* ── Struct da música ────────────────────────────────────────────── */

typedef struct {
    char nome[100];
    int  duracao;   /* duração em segundos */
} t_musica;

/* ── Funções de música ───────────────────────────────────────────── */

t_musica* criar_musica(const char* nome, int duracao) {
    t_musica* m = malloc(sizeof(t_musica));
    strncpy(m->nome, nome, sizeof(m->nome) - 1);
    m->nome[sizeof(m->nome) - 1] = '\0';
    m->duracao = duracao;
    return m;
}

void imprimir_musica(void* carga) {
    t_musica* m = (t_musica*) carga;
    printf("  [%s - %d:%02d]\n", m->nome, m->duracao / 60, m->duracao % 60);
}

void liberar_musica(void* carga) {
    free(carga);
}

/* ── Playlist (wrapper sobre t_lse) ─────────────────────────────── */

typedef struct {
    t_lse* fila;
    char   nome[100];
} t_playlist;

t_playlist* criar_playlist(const char* nome) {
    t_playlist* pl = malloc(sizeof(t_playlist));
    strncpy(pl->nome, nome, sizeof(pl->nome) - 1);
    pl->nome[sizeof(pl->nome) - 1] = '\0';
    pl->fila = criar_lse();
    return pl;
}

void adicionar_musica(t_playlist* pl, const char* nome, int duracao) {
    inserir_final_lse(pl->fila, criar_musica(nome, duracao));
}

void imprimir_playlist(t_playlist* pl) {
    printf("=== Playlist: %s ===\n", pl->nome);
    imprimir_lse(pl->fila, imprimir_musica);
}

void destruir_playlist(t_playlist* pl) {
    destruir_lse(pl->fila, liberar_musica);
    free(pl);
}
