#include "programa.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 1000000

void questao_1(int* vetor_de_1milhao){
    int quantidades_de_repeticoes = 30;
    int chave;
    double tempo_da_busca_sequencial[quantidades_de_repeticoes], tempo_da_busca_binaria[quantidades_de_repeticoes];

    // TESTE BUSCA SEQUENCIAL VETOR DESORDENADO //
    for(int repeticoes_acumuladas = 0; repeticoes_acumuladas < quantidades_de_repeticoes; repeticoes_acumuladas++){
        if(repeticoes_acumuladas < 15){
            chave = rand() % tam;
            clock_t tempo_inicial = clock();
            busca_sequencial(vetor_de_1milhao, tam, chave);
            clock_t tempo_final = clock();

            tempo_da_busca_sequencial[repeticoes_acumuladas] = 
                (double)(tempo_final-tempo_inicial) / CLOCKS_PER_SEC;
        } else {
            chave = rand();
            clock_t tempo_inicial = clock();
            busca_sequencial(vetor_de_1milhao, tam, chave);
            clock_t tempo_final = clock();

            tempo_da_busca_sequencial[repeticoes_acumuladas] = 
                (double)(tempo_final-tempo_inicial) / CLOCKS_PER_SEC;
        }
    }

    // CRIA VETOR ORDENADO
    int* vetor_de_1milhao_ordenado = cria_vetor_ordenado(tam);

    for(int repeticoes_acumuladas = 0; repeticoes_acumuladas < quantidades_de_repeticoes; repeticoes_acumuladas++){
        if(repeticoes_acumuladas < 15){
            chave = rand() % tam;
            clock_t tempo_inicial = clock();
            busca_binaria(vetor_de_1milhao_ordenado, tam, chave);
            clock_t tempo_final = clock();

            tempo_da_busca_binaria[repeticoes_acumuladas] = 
                (double)(tempo_final-tempo_inicial) / CLOCKS_PER_SEC;
        } else {
            chave = rand();
            clock_t tempo_inicial = clock();
            busca_binaria(vetor_de_1milhao_ordenado, tam, chave);
            clock_t tempo_final = clock();

            tempo_da_busca_binaria[repeticoes_acumuladas] = 
                (double)(tempo_final-tempo_inicial) / CLOCKS_PER_SEC;
        }
    }

    // MOSTRA OS TEMPOS DE EXECUCAO E ESTATISTICAS //
    printf("RODADAS    BUSCA SEQUENCIAL    BUSCA BINARIA\n");
    for(int i = 0; i < quantidades_de_repeticoes; i++){
        printf("RODADA %i    ", i+1);
        printf("%.8f    ", tempo_da_busca_sequencial[i]);
        printf("%.8f\n", tempo_da_busca_binaria[i]);
    }
    calcula_estatistica(tempo_da_busca_sequencial, quantidades_de_repeticoes, "busca sequencial");
    calcula_estatistica(tempo_da_busca_binaria, quantidades_de_repeticoes, "busca binaria");

    free(vetor_de_1milhao_ordenado);
}
