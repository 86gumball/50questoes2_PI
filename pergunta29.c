#include "abin.h"

/* Copia-se o valor do nodo para a nova arvore e chama-se a função recursivamente
   aos ramos, o caso de paragem é quando a função recebe um ramo nulo*/
ABin cloneAB (ABin root) {
	ABin new = NULL;
	if (root != NULL){
    	new = (ABin) malloc (sizeof (struct nodo));
    	new->valor = root->valor;
    	new->esq = cloneAB (root->esq);
    	new->dir = cloneAB (root->dir);
	}
    return new;
}