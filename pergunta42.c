#include "abin.h"

int contaFolhas (ABin a) {
	/* Se a for um ABin vazia, não tem folhas */
	if (a == NULL){
		return 0;
	} else {
		/* Testa se a é uma folha, caso seja, retorna 1 */
		if (a->esq == NULL && a->dir == NULL){
			return 1;
		/* Chama a função recursivamente aos ramos, somando o número de folhas
		   do lado esquerdo com o número de folhas no lado direito. */
		} else {
			return (contaFolhas(a->esq) + contaFolhas(a->dir));
		} 
	} 
}