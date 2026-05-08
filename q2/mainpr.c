#include "TADlista.h"
#include "../q1/programa.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 1000000

void questao_2(int*vetor_de_1milhao){
    int quantidades_de_repeticoes=60;
    int chave;
    int n=quantidades_de_repeticoes/2;
    double tempo_da_busca_vetor[n], tempo_da_busca_lista[n];
    //int*vetor_de_1milhao=cria_vetor(tam);
    tipoLista lista_de_1milhao;

    criarLista(&lista_de_1milhao);
    insereNaLista(&lista_de_1milhao,vetor_de_1milhao,tam);

    //TESTE BUSCA SEQUENCIAL VETOR DESORDENADO//
    int x=0;
    for(int repeticoes_acumuladas=0;repeticoes_acumuladas<quantidades_de_repeticoes;repeticoes_acumuladas++){
        if(repeticoes_acumuladas<30){
            chave=rand()%tam;
            clock_t tempo_inicial=clock(); //incia o timer//
            busca_sequencial(vetor_de_1milhao,tam,chave);
            clock_t tempo_final=clock(); //finaliza o timer//

            tempo_da_busca_vetor[repeticoes_acumuladas]=(double)(tempo_final-tempo_inicial)/CLOCKS_PER_SEC;//calcula os segundos//

        }else{
            chave=rand()%tam;
            clock_t tempo_inicial=clock(); //incia o timer//
            buscaSequencial(&lista_de_1milhao,chave);
            clock_t tempo_final=clock(); //finaliza o timer//

            tempo_da_busca_lista[x]=(double)(tempo_final-tempo_inicial)/CLOCKS_PER_SEC;//calcula os segundos//
            x++;
        }
    }

    printf("-------------------------------\n");
    printf("-------------------------------\n");
    
    calcula_estatistica(tempo_da_busca_vetor, n,"Busca Sequencial no vetor");
    calcula_estatistica(tempo_da_busca_lista, n,"Busca Sequencial na lista");

}
