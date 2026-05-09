#include <stdio.h>
#include <stdlib.h>

/* ================================================================
 *  sort.c — Algoritmos de Ordenação em C
 *
 *  Implementações:
 *    - Bubble Sort    O(n²)      estável
 *    - Insertion Sort O(n²)      estável
 *    - Selection Sort O(n²)      instável
 *    - Quick Sort     O(n log n) instável  (pior caso O(n²))
 *    - Merge Sort     O(n log n) estável
 * ================================================================ */


/* ── Utilitário ─────────────────────────────────────────────────── */

static void trocar(int* a, int* b) {
    int t = *a;
    *a    = *b;
    *b    = t;
}


/* ── Bubble Sort ────────────────────────────────────────────────── */
/*
 * Percorre o vetor repetidamente, trocando elementos adjacentes
 * fora de ordem. A cada passagem, o maior elemento "borbulha"
 * para o final.
 */
void bubbleSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1])
                trocar(&v[j], &v[j + 1]);
        }
    }
}


/* ── Insertion Sort ─────────────────────────────────────────────── */
/*
 * Constrói o vetor ordenado um elemento por vez, inserindo cada
 * novo elemento na posição correta dentro da parte já ordenada.
 */
void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j     = i - 1;

        /* Desloca elementos maiores que chave uma posição à frente */
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}


/* ── Selection Sort ─────────────────────────────────────────────── */
/*
 * Divide o vetor em parte ordenada (esquerda) e não ordenada (direita).
 * A cada iteração, encontra o mínimo da parte não ordenada e o move
 * para o final da parte ordenada.
 */
void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idx_min = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[idx_min])
                idx_min = j;
        }

        if (idx_min != i)
            trocar(&v[idx_min], &v[i]);
    }
}


/* ── Quick Sort ─────────────────────────────────────────────────── */
/*
 * Divide o vetor em torno de um pivô: elementos menores ficam à
 * esquerda, maiores à direita. Aplica recursão nos dois lados.
 * Pivô escolhido: último elemento do intervalo.
 */
static int particao(int v[], int ini, int fim) {
    int pivo = v[fim];
    int i    = ini - 1;

    for (int j = ini; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            trocar(&v[i], &v[j]);
        }
    }

    trocar(&v[i + 1], &v[fim]);
    return i + 1;
}

void quickSort(int v[], int ini, int fim) {
    if (ini >= fim) return;

    int pivo_idx = particao(v, ini, fim);
    quickSort(v, ini, pivo_idx - 1);
    quickSort(v, pivo_idx + 1, fim);
}


/* ── Merge Sort ─────────────────────────────────────────────────── */
/*
 * Divide o vetor ao meio recursivamente até sobrar subarrays de 1
 * elemento, depois intercala (merge) os pares em ordem crescente.
 */
static void merge(int v[], int esq, int meio, int dir) {
    int tam_esq = meio - esq + 1;
    int tam_dir = dir  - meio;

    int* L = malloc(tam_esq * sizeof(int));
    int* R = malloc(tam_dir * sizeof(int));

    for (int i = 0; i < tam_esq; i++) L[i] = v[esq  + i];
    for (int j = 0; j < tam_dir; j++) R[j] = v[meio + 1 + j];

    int i = 0, j = 0, k = esq;

    /* Intercala L e R em ordem crescente */
    while (i < tam_esq && j < tam_dir) {
        if (L[i] <= R[j])
            v[k++] = L[i++];
        else
            v[k++] = R[j++];
    }

    /* Copia restos (apenas um dos dois terá elementos restantes) */
    while (i < tam_esq) v[k++] = L[i++];
    while (j < tam_dir) v[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int v[], int esq, int dir) {
    if (esq >= dir) return;

    int meio = esq + (dir - esq) / 2;   /* evita overflow vs (esq+dir)/2 */
    mergeSort(v, esq, meio);
    mergeSort(v, meio + 1, dir);
    merge(v, esq, meio, dir);
}
