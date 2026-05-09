#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listase.h"
#include "playlist.c"   /* inclui as funções de música/playlist */

static void imprimir_int(void* carga) {
    printf("%d ", *(int*)carga);
}

static void liberar_int(void* carga) {
    free(carga);
}

static int* criar_num(int num) {
    int* novo = malloc(sizeof(int));
    *novo = num;
    return novo;
}

int main() {
    char nome[100];
    int  duracao;

    /* Lista de números (exemplo de uso genérico) */
    t_lse* deNumeros = criar_lse();
    inserir_final_lse(deNumeros, criar_num(10));
    inserir_final_lse(deNumeros, criar_num(20));
    inserir_final_lse(deNumeros, criar_num(30));
    printf("Lista de numeros: ");
    imprimir_lse(deNumeros, imprimir_int);
    destruir_lse(deNumeros, liberar_int);

    /* Playlist lida do terminal */
    t_playlist* pl = criar_playlist("Minha Playlist");

    /* FIX: scanf("%s", nome) — sem & para array de char */
    printf("Digite nome da musica (ou FIM para encerrar):\n");
    scanf("%99s", nome);
    while (strcmp(nome, "FIM") != 0) {
        scanf("%d", &duracao);
        adicionar_musica(pl, nome, duracao);
        scanf("%99s", nome);
    }

    imprimir_playlist(pl);
    destruir_playlist(pl);

    return 0;
}
