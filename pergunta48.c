#include "abin.h"

/* Nota: Dado o enunciado, as linhas: ABin temp = *root;
                                      free(tmp);
   tem caráter facultativo, visto que não é explicitamente pedido no enunciado para
   libertar da memória o nodo removido.
*/

void removeMaiorA (ABin *root) {
	/* Quando é encontrado o maior elemento da árvore binária de procura, o apontador
	   *root representa o ramo direito do ramo anterior, assim atualizando *root para
	   o apontador do seu ramo esquerdo a árvore binária ignora o maior nodo e o ramo
	   fica ligado ao valor à esquerda do maior valor. */
	if ((*root)->dir == NULL){
		ABin temp = *root;
		*root = (*root)->esq;
		free(temp);
	/* Chama-se a função recursivamente até encontrar o último valor. */
	} else {
		removeMaiorA(&((*root)->dir));
	} 
}