#include "abin.h"

int maiorAB (ABin root) {
	/* Se o nodo não tiver nenhum ramo à direita, significa que contem o maior valor
	   da árvore binária de procura */
	if (root->dir == NULL){
		return root->valor;
		
	/* Caso contrário, vai-se chamando a função recursivamente ao ramo direito até
	   chegar ao valor mais alto */
	} else {
		maiorAB(root->dir);
	} 
}