#include "abin.h"

/* A função funciona aumentado recursivamente o enderenço de v em incrementos de 1 ou 0, em que
   v[0] representa a posição a ser escrita na respetiva iteração. */

int nivelV (ABin root, int n, int v[]) {

	/* Se o nodo não existir para-se a função */
    if (root == NULL){
    	return 0;
    }

    /* Se chegarmos à profundidade pretendida atualiza-se o array e dá-se return 1 para a atualizar
       a posição a ser atualizada */
    if (n == 1){
    	v[0] = root->valor;
    	return 1;
    } 
    /* Caso não chegamos à profundidade chama-se a função ao ramo esquerdo e guarda-se o output em pos,
       pos representa agora o desvio em relação a v[0], ou seja, v[pos] é a posição onde o próximo int
       será guardado, como v[pos] == (v + pos)[0], chama-se a função recursivamente à direita com v
       correspondente a (v + pos) para se poder introduzir o número na posição (v + pos)[0] */
    else {
    	int pos = nivelV(root->esq, n-1, v);
    	return pos + nivelV(root->dir, n-1, v + pos);
    } 
}