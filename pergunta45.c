#include "abin.h"

int lookupAB (ABin root, int x) {
	/* Caso paragem, ou seja, x não existe na árvore binária. */
	if (root == NULL){
		return 0;

	} else {
		/* Se o valor do nodo for x, o valor foi encontrado e retorna-se 1. */
		if (root->valor == x){
			return 1;
		/* Se x for menor que o nodo, procura-se à esquerda */
		} else if (x < root->valor){
			lookupAB(root->esq, x);
		/* Se x for mairo que o nodo, procura-se à direita */
		} else {
			lookupAB(root->dir, x);
		} 
	} 
}