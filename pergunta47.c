#include "abin.h"

int maiorAB (ABin root) {
	/* Procura o ultimo nodo à direita e devolve o seu valor no final*/	
	while(root->dir != NULL){
		root = root->dir;
	}
	return root->valor;
}
