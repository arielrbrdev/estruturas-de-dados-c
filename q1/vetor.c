#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "programa.h"

int* cria_vetor(int tam) {
    int *vet;
    srand(time(NULL));
    vet = (int*)malloc(tam * sizeof(int));
    for(int x = 0; x < tam; x++) {
        vet[x] = rand();
    }
    return(vet);
}

int* cria_vetor_ordenado(int tam) {
    int atual = 0;
    int *vet = (int*)malloc(tam * sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < tam; i++) {
        atual += (rand() % 10) + 1;
        vet[i] = atual;
    }
    return(vet);
}

void ler_vet(int* vet, int tam) {
    for(int n = 0; n < tam; n++) {
        printf("%d ", vet[n]);
    }
    printf("------------------");
}
