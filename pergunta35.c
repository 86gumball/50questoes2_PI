#include "abin.h"

int freeAB (ABin root) {
	/* Quando root == NULL, a função acaba. */
	if (root == NULL){
		return 0;
	} else {
		/* Os apontadores root->esq e root->dir são guardados em variáveis temporárias,
		   para se poder libertar o nodo root sem perder os apontadores dos ramos após. */
		ABin tmpEsq = root->esq; 
		ABin tmpDir = root->dir;
		free(root);
		/* A função é chamada recursivamente, acrescentado 1 por cada nodo não nulo */
		return (1 + freeAB(tmpEsq) + freeAB(tmpDir));
	} 
}