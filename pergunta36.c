#include "abin.h"

int pruneAB (ABin *root, int depth) {
	/* Casso *root for uma ABin nula não se removem elementos nenhuns */
	if (*root == NULL){
		return 0;
	} 

	/* Caso se tenha chegado à profundidade pretendida:
	        1. Guarda-se em res o número de elementos removidos chamando a função aos ramos.
	        2. Liberta-se a memória onde *root era guardado.
	        3. Fecha-se esse ramo da árvore.
	        4. Dá-se return ao resultado. */
	if (depth == 0){
		int res = 1 + pruneAB( &((*root)->esq), 0)  // Step 1
		            + pruneAB( &((*root)->dir), 0); // Step 1
		free(*root);                                // Step 2
		*root = NULL;                               // Step 3
		return res;                                 // Step 4
	} 
	/* Caso contrário, retorna-se o resultado de chamar a função ao dois ramos. */
	else {
		return ( pruneAB( &((*root)->esq), depth - 1 ) +
				 pruneAB( &((*root)->dir), depth - 1 ) );
	} 
}