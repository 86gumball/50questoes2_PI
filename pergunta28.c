#include "abin.h"
#include <stdio.h>
#include <stdlib.h>

ABin newABin (int r, ABin e, ABin d){
	ABin new = (ABin) malloc (sizeof (struct nodo));

	if (new!=NULL){
		new->valor = r;
		new->esq   = e;
		new->dir   = d;
	}
	return new;
}

/* Ver algoritmo (recursivo) descrito em: https://bit.ly/2OTtv5O */
int altura (ABin root){
    if (root == NULL){
    	return 0;
    }
    int esq_altura = altura(root->esq);
    int dir_altura = altura(root->dir);
	if (esq_altura > dir_altura){
		return esq_altura + 1;
	} else {
		return dir_altura + 1;
	} 
}