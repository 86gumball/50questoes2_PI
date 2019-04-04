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

void appendL (LInt *head, int x){
	LInt current = *head;

	/* Nodo novo a ser inserido */
	LInt new = newLInt(x, NULL);

	/* Caso *head esteja um apontador nulo ele passa a apontar para o mesmo local que new */
	if (*head == NULL){
		*head = new;
		return;
	}

	/* Procura-se o último nodo */
	while (current->prox != NULL){
		current = current->prox;
	} 

	/* Liga-se o último nodo ao novo nodo */
	current->prox = new;
}