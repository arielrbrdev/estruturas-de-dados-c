#include <stdio.h>

/*
 * ARQUIVO DE AULA — Ponteiros de função em C
 *
 * Um ponteiro de função armazena o endereço de uma função.
 * Tipo: retorno (*nome)(parametros)
 * Ex:   void (*p_funcao)(int)
 *
 * FIX: havia dois main(), parâmetros sem tipo e chamadas erradas.
 */

/* Tipo alias para facilitar a leitura */
typedef void (*p_funcao_t)(int);

/* Funções que serão passadas como argumento */
void funcao_a(int num) {
    printf("funcao_a chamada com num = %d\n", num);
}

void funcao_b(int num) {
    printf("funcao_b chamada com num = %d\n", num);
}

/*
 * chamadora: recebe um ponteiro de função e um ponteiro para int.
 * Chama a função passada com o valor apontado por num.
 */
void chamadora(p_funcao_t p_funcao, int* num) {
    p_funcao(*num);
}

int main() {
    int num = 10;

    /* Chamada direta */
    funcao_a(num);

    /* Chamada via ponteiro de função */
    chamadora(funcao_a, &num);
    chamadora(funcao_b, &num);

    /* Ponteiro de função armazenado em variável */
    p_funcao_t escolha = funcao_b;
    escolha(num);

    return 0;
}
