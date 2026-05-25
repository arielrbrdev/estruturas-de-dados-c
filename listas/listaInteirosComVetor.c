#include <stdio.h>
#include <stdlib.h>


typedef struct listaDeInteiros {
  int *elementos;
  unsigned numElementos;
  unsigned capacidade;
}  listaDeInteiros;

void criar(listaDeInteiros *al, unsigned tamanho) {
  al->elementos = (int*)  malloc (sizeof(int)*tamanho);
  al->numElementos = 0;
  al->capacidade = tamanho;

}

char inserir(listaDeInteiros *al,int item) {
  if(al->numElementos < al->capacidade) {
    al->elementos[al->numElementos]= item;
    al->numElementos++;
    return 1;
  }
  return 0;
}

char removePosicao(listaDeInteiros *al, int *item, unsigned posicao) {
  unsigned i;
  if(posicao < al->numElementos) {
    *item = al->elementos[posicao];
    al->numElementos--;
    for(i = posicao; i < al->numElementos  ; i++) {
	al->elementos[i] = al->elementos[i+1];
    }
    return 1;
  }
  return 0;
}

void mostrar(listaDeInteiros *al) {
  unsigned i;

  printf("[ ") ;
  if(al->numElementos) {
    for(i = 0; i < al->numElementos-1; i++) {
      printf("%d, ",al->elementos[i]);
    }
    printf("%d ",al->elementos[i]);
  }
  printf("]") ;
}

int main() {
  listaDeInteiros l1, l2;

  criar(&l1, 10);

 
  criar(&l2, 50);

  for(int x = 5; x < 10; x++) {
    inserir(&l1,x);
  }

  inserir(&l1,4);
  inserir(&l2,5);
  printf("A lista l1 está assim : ");
  mostrar(&l1); printf("\n");

 printf("A lista l2 está assim : ");
  mostrar(&l2); printf("\n");
}
