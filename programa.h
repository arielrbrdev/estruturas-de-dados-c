#ifndef PROGRAMA_H
#define PROGRAMA_H

int* cria_vetor(int tam);
void ler_vet(int*vet, int tam);
int busca_sequencial(int*vet, int tam,int chave);
int busca_binaria(int*vet, int tam, int chave);
void calcula_estatistica(double tempo[],int tam,char*algoritmo);
int* cria_vetor_ordenado(int tam);
void questao_1(int* vetor_de_1milhao);

#endif
