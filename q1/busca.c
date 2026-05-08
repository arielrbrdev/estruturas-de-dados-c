#include <stdio.h>
#include <stdlib.h>
#include "programa.h"

int busca_sequencial(int*vet, int tam,int chave){
    for(int x=0;x<tam;x++){
        if(vet[x]==chave){
            return 1;
        }
    }
    return 0;
}

int busca_binaria(int*vet, int tam, int chave){
    int inicio=0, fim=tam-1, meio;
    while(inicio<=fim){
        meio=(inicio+fim)/2;
        if(vet[meio]==chave){
            return 1;
        }
        if(vet[meio]<chave){
            inicio=meio+1;
        }else{
            fim=meio-1;
        }
    }
    return 0;
}
