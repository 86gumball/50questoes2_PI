#include "abin.h"

/* Algoritmo inorder
    	(Condição) Enquanto a raiz não é vazia:
    		1. Chama-se a função inorder ao ramo esquerdo.
    		2. Chama-se a função auxiliar à raiz.
    		3. Chama-se a função inorder ao ramo direito.
*/

int dumpAbin (ABin root, int v[], int n) {
	/* Se não existe nodo na posição então retorna-se 0 */
    if (root == NULL){
    	return 0;
    } 

    /* n (número de slots disponiveis no array) vai diminuindo, quando chega a 0 não é inserido
       mais nenhum número */
    if (n == 0){
    	return 0;
    } else {
        int pos = dumpAbin(root->esq, v, n);
    	if(pos < n){
    	    v[pos] = root->valor;
    	    return pos + 1 + dumpAbin(root->dir, v + pos + 1, n - (pos + 1));
    	}
    	return n;
    } 
}

/* Explicação:
    1. Chama-se a função ao ramo da esquerda e guarda-se em pos o número de posições preenchidas.
    2. v[pos] = root->valor põe na posição de indice 'pos' o novo elemento.
   		Nota: Se por exemplo pos == 3, significa que foram preenchidas 3 posições e como os
   		arrays começam em 0, o último elemento é v[2], consequentemente v[3] (v[pos]) está vazio.
	3. Chama-se a função ao ramo da direita retornando o número de posições preenchidas.
		Nota_1:
	      pos -> posições preenchidas pelo ramo da esquerda
	    + 1   -> posição preenchida pelo novo elemento da iteração a ocorrer
	    + dumpAbin(root->dir, v + pos + 1, n - (pos + 1)); -> posições preenchidas pelo ramo da direita
	    Nota_2:
	    dumpAbin(root->dir,     -> ramo da direita
	    		 v + pos + 1,   -> v é atualizado de maneira a que v[0] é movido (pos + 1) posições
	    		 			       para a frente, que corresponde ao número de posições preenchidas
	    		 n - (pos + 1)) -> ao número de slots disponíveis no array é retirado (pos + 1),
	    		 				   que corresponde ao número de posições preenchidas
*/
