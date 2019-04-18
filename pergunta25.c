#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

/* A função removeInt remove um int 'x' de uma lista ligada head, ignorando o primeiro elemento da lista,
   por exemplo, removeInt( [6, 3, 6, 4, 2, 6, 6], 6) == [6, 3, 4, 2]
              e removeInt( [3, 6, 6, 4, 2, 6, 6], 6) == [3, 4, 2]
   Nota: Esta função não funciona para listas vazias, mas não é necessário, pois só é chamada com listas
   de pelo menos 1 elemento */
void removeInt (LInt head, int x){
	LInt prev = head; // Apontador sempre 1 nodo atrás de head
	head = head->prox; // Apontador que percorre a lista até ao fim

	while (head != NULL){
		/* Caso encontremos o valor x, prev passa a apontar para o nodo depois de head, em vez de head,
		   o nodo para qual head aponta é libertado, e head passa a apontar para o nodo seguinte*/
		if (head->valor == x){
			prev->prox = head->prox;
			free(head);
			head = prev->prox;
		} 

		/* Caso contrário, avanção-se os dois nodos normalmente */
		else {
			prev = prev->prox;
			head = head->prox;
		} 
	} 
}

/* Para entender melhor como funciona, usa-se a representação de listas em Haskell, em que o final de uma
   lista é uma lista vazia '[]', que equivale a um apontador nulo em C.
   Seja '↑' o nodo para qual head aponta, os passos do algoritmo são os seguintes:
    	[5, 8, 2, 8, 3, 2, 5, [] ]
    	 ↑ 
    	[5, 8, 2, 8, 3, 2, [] ]
    	    ↑
    	[5, 8, 2, 3, 2, [] ]
    	       ↑
    	[5, 8, 2, 3, [] ]
    	          ↑
    	[5, 8, 2, 3, [] ]
    	             ↑
   O algoritmo acaba quando head == NULL, ou seja, chegou ao fim da lista
    	            */

void remreps (LInt head){
	/* Se head for vazia não se faz nada */
    if (head == NULL){
    	return;
    }
    while (head != NULL){
    	removeInt (head, head->valor);
    	head = head->prox;
    } 
}