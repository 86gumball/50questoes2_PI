#include "abin.h"

ABin somasAcA (ABin root) {
	/* Se root for null, então a sua somasAcA é uma ABin nula também */
    if (root == NULL){
    	return NULL;
    }

    ABin newEsq = somasAcA(root->esq); // somasAcA do ramo esquerdo
    ABin newDir = somasAcA(root->dir); // somasAcA do ramo direito

    ABin newRoot = (ABin) malloc(sizeof(ABin)); // Nova ABin que contem as somasAcA
	newRoot->esq = newEsq; // Ligar o ramo esquerdo à nova ABin
	newRoot->dir = newDir; // Ligar o ramo direito à nova ABin

	int somaEsq; // Int onde é guardado a somaAcA do ramo esquerdo
	int somaDir; // Int onde é guardado a somaAcA do ramo direito

	/* Caso haja um ramo do lado esquerdo, ele contém a soma de todos os elementos da árvore
	   a baixo de si */
	if (newEsq != NULL){
	    somaEsq = newEsq->valor;
	} 
	/* Caso contrário, é atribuida à soma o valor 0 */
	else {
		somaEsq = 0;
	} 

	if (newDir != NULL){
	    somaDir = newDir->valor;
	} else {
		somaDir = 0;
	} 

	/* Após se guardar o valor da somaAcA de cada ramo, junta-se esse valor ao valor já contido
	   no nodo principal e por fim dá-se return ao endereço desse nodo.s */
	newRoot->valor = somaEsq + somaDir + root->valor;
	return newRoot;
}