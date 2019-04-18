#include "abin.h"

int quantosMaiores (ABin root, int x) {
	/* Se não existir uma árvore */
	if (root == NULL){
		return 0;
	}
	/* Se x < root->valor, acrescentamos 1 e chama-mos a função aos dois ramos, pois tanto pode haver elementos menores
	   que root->valor que são menores ou maiores que x. */
	if (x < root->valor){
		return 1 + quantosMaiores(root->esq, x) + quantosMaiores(root->dir, x);
	} 
	/* Caso contrário, basta apenas chamar ao ramo direito (sem acrescentar 1), pois todos os valores no ramo esq de root
	   são menores que x */
	else {
		return quantosMaiores(root->dir, x);
	} 
}