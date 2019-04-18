#include "abin.h"

int depth (ABin root, int x) {
	if (root == NULL){ // Caso root seja nulo, não existe x, logo return -1
		return -1;
	} 
	if (root->valor == x){ // Caso se encontre x, return 1
		return 1;
	}

	int depthEsq = depth(root->esq, x); // Resultado de depth chamada ao ramo esq
	int depthDir = depth(root->dir, x); // Resultado de depth chamada ao ramo dir

	/* Caso x não exista em nenhum dos ramos, retorna-se -1 */
	if (depth(root->esq, x) < 0 && depth(root->dir, x) < 0){
		return -1;
	}

	/* Caso x não exista no ramo esquerdo, retorna-se o resultado da função depth chamada ao
	   ramo direito + 1. */
	else if (depth(root->esq, x) < 0){
		return depth(root->dir, x) + 1;
	} 

	/* Caso x não exista no ramo direito, retorna-se o resultado da função depth chamada ao
	   ramo esquerdo + 1. */
	else if (depth(root->dir, x) < 0){
		return depth(root->esq, x) + 1;
	}

	/* Caso x exista em ambos os ramos dá-se return ao menor dos ramos + 1 */
	else {
		if (depth(root->esq, x) < depth(root->dir, x)){
			return depth(root->esq, x) + 1;
		} else {
			return depth(root->dir, x) + 1;
		} 
	} 
}