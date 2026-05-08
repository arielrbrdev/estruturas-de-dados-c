#ifndef TADLISTA_H
#define TADLISTA_H

typedef struct tipoNo{
    int dados;
    struct tipoNo* prox;
} tipoNo;

typedef struct tipoLista{
    tipoNo* prim;
    tipoNo* ult;
} tipoLista;

void criarLista(tipoLista*lista); 
void insereNaLista(tipoLista* lista, int vetor[], int tam);
int buscaSequencial(tipoLista* lista, int valor);
void questao_2(int*vetor_de_1milhao);

#endif
