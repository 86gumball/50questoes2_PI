#include "abin.h"

int lookupAB (ABin root, int x) {
	/* Se encontra x dá return a 1, caso contrário vai procurando à esquerda ou direita dependendo
	   se é maior ou menor, se o loop acabar significa que não se encontrou o nodo e dá-se return 0 */
	while(root != NULL){
		if(x == root->valor){
			return 1;
		} else if (x < root->valor){
			root = root->esq;
		} else {
			root = root->dir;
		}
	}	
	return 0; 
}
