#include "abin.h"

/* Devolve o valor mais à esquerda de todo. */
int minValue(ABin root){
	if (root->esq == NULL){
		return root->valor;
	} else {
		return minValue(root->esq);
	} 
}

/* Devolve o valor mais à direita de todo. */
int maxValue(ABin root){
	if (root->dir == NULL){
		return root->valor;
	} else {
		return maxValue(root->dir);
	} 
}

int deProcura (ABin root) {
	/* Se root for uma arvore binária vazia, então é de procura */  
	if (root == NULL){
		return 1;  
	}
	/* Se o maior valor à esquerda for maior que o valor guardado em root, então a árvore não é de procura. */
	if (root->esq != NULL && maxValue(root->esq) > root->valor){
		return 0;  
	} 
	/* Se o menor valor à direita for menor que o valor guardado em root, então a árvore não é de procura. */
	else if (root->dir != NULL && minValue(root->dir) < root->valor){
		return 0;  
	} 
	/* Se o ramo da esquerda ou da direita não fore de procura, então a árvore não é de procura. */
	else if (!deProcura(root->esq) || !deProcura(root->dir)){
		return 0;  
	}
	/* Caso passe todos os testes, a árvore é de procura. */
	return 1;
}  