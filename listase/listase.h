#ifndef LISTASE_H
#define LISTASE_H

typedef struct lse t_lse;

/* Ciclo de vida */
t_lse*  criar_lse();
void    destruir_lse(t_lse* lse, void (*liberar_carga)(void*));

/* Inserção */
void    inserir_lse(t_lse* lse, void* carga);         /* insere no início */
void    inserir_final_lse(t_lse* lse, void* carga);   /* insere no fim    */

/* Remoção — retorna a carga (chamador libera a memória) */
void*   remover_lse(t_lse* lse);         /* remove do início */
void*   remover_final_lse(t_lse* lse);   /* remove do fim    */

/* Acesso e exibição */
void*   acessar_lse(t_lse* lse, int pos); /* base 1; NULL se fora do range */
void    imprimir_lse(t_lse* lse, void (*imprimir_carga)(void*));

#endif
