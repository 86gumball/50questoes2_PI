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

void init (LInt *head){
	LInt current = *head;

	/* Caso lista única */
    if ((*head)->prox == NULL){
    	free(*head);
    	*head = NULL;
    return;
    }
    
	LInt prev;
	/* prev é um apontador que está sempre 1 nodo atrás de current */
    while (current->prox != NULL){
    	prev = current;
    	current = current->prox;
    }

    /* Quando current é o último nodo, o apontador para o prox de prev é atualizado para NULL,
       e o nodo current, correspondente ao último nodo é libertado da memória */
    prev->prox = NULL;
    free(current);
}