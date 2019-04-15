#include "abin.h"

/* Função dada pela codeboard para criar um nodo duma lista ligada */
LInt mynewLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

/* pergunta14 */
void appendL (LInt *head, int x){
	LInt current = *head;
	LInt new = mynewLInt(x, NULL);
	if (*head == NULL){
		*head = new;
		return;
	}
	while (current->prox != NULL){
		current = current->prox;
	} 
	current->prox = new;
}

/* Nota: A eficiência desta função pode ser aumentada se em vez de colocar o novo
   nodo no fim (que é uma operação relativamente cara de se fazer), colocar-se o
   novo nodo no inicio da lista e no final da função inverter a lista ligada. */

/* Algoritmo inorder
    	(Condição) Enquanto a raiz não é vazia:
    		1. Chama-se a função inorder ao ramo esquerdo.
    		2. Chama-se a função auxiliar à raiz.
    		3. Chama-se a função inorder ao ramo direito.
*/

void inorder (ABin root, LInt *head) {
	if (root != NULL){ // Condição
		inorder (root->esq, head);   // Step 1
		appendL (head, root->valor); // Step 2
		inorder (root->dir, head);   // Step 3
	}
}