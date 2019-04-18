#include "abin.h"

int depthOrd2 (ABin root, int x, int depth){
	/* Se root é nulo, então x não existe na árvore binária */
	if (root == NULL){
		return -1;
	}
	if (x < root->valor){
		return depthOrd2(root->esq, x, depth + 1); // Se x é menor procura-se à esquerda
	} else if (x > root->valor){
		return depthOrd2(root->dir, x, depth + 1); // Se x é maior procura-se à direita
	} else {
		return depth; // Caso se encontre x, retorna-se a profundidade a que está
	} 
}

int depthOrd (ABin root, int x) {
	/* Chama-se a função auxiliar depthOrd2, que recebe os mesmos parametros que depthOrd,
	   mas tem um parametro extra (depth), onde é guardada a profundidade que está a ser
	   inspecionada a cada iteração. */
    return depthOrd2(root, x, 1);
}