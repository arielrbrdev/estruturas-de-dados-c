#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define RODADAS    30
#define N_SORTS    5

/* Índices dos algoritmos no array de tempos */
#define IDX_BUBBLE    0
#define IDX_INSERTION 1
#define IDX_SELECTION 2
#define IDX_QUICK     3
#define IDX_MERGE     4

static const char* NOMES[N_SORTS] = {
    "BubbleSort",
    "InsertionSort",
    "SelectionSort",
    "QuickSort",
    "MergeSort"
};


/* ── Exibição de resultados ─────────────────────────────────────── */

void exibir_resultados(int rodadas, double tempos[N_SORTS][RODADAS], double somas[N_SORTS]) {
    printf("\n=== RESULTADOS POR TECNICA ===\n");

    for (int s = 0; s < N_SORTS; s++) {
        printf("\n%s\n", NOMES[s]);
        for (int r = 0; r < rodadas; r++) {
            printf("  rodada %2d : %.6f s\n", r + 1, tempos[s][r]);
        }
    }

    printf("\n=== MEDIAS FINAIS ===\n");
    for (int s = 0; s < N_SORTS; s++) {
        printf("  %-15s %.6f s\n", NOMES[s], somas[s] / rodadas);
    }
}


/* ── Desvio padrão ──────────────────────────────────────────────── */
/*
 * FIX: 'rodadas' não declarado → usa parâmetro n
 *      variável 'i' não declarada → usa 'r'
 *      pow(tempos[i]) com 1 argumento → pow(tempos[r] - media, 2)
 *      função não retornava valor → retorna double
 */
double calcular_desvio_padrao(double tempos[], int n, double media) {
    double soma_variancia = 0.0;

    for (int r = 0; r < n; r++) {
        soma_variancia += pow(tempos[r] - media, 2);
    }

    return sqrt(soma_variancia / n);
}


/* ── Geração e cópia de vetores ─────────────────────────────────── */
/*
 * FIX: as funções recebiam int* vetor e faziam malloc internamente,
 *      mas isso não atualiza o ponteiro no chamador.
 *      Solução: não receber o ponteiro — apenas alocar e retornar.
 */
int* gerar_vetor(int n) {
    int* vetor = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 1000000;
    }
    return vetor;
}

int* copiar_vetor(int* orig, int n) {
    int* copia = malloc(n * sizeof(int));
    memcpy(copia, orig, n * sizeof(int));
    return copia;
}


/* ── Medição de tempo ───────────────────────────────────────────── */

/* Para funções com assinatura: void sort(int[], int)
 * Ex: bubbleSort, insertionSort, selectionSort
 */
double medir_tempo(void (*sort_func)(int[], int), int vetor[], int n) {
    clock_t start = clock();
    sort_func(vetor, n);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

/* Para funções com assinatura: void sort(int[], int ini, int fim)
 * Ex: quickSort, mergeSort
 */
double medir_tempo_2(void (*sort_func)(int[], int, int), int vetor[], int ini, int fim) {
    clock_t start = clock();
    sort_func(vetor, ini, fim);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}
