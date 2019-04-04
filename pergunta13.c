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
    if ((*head)->prox == NULL){
    	free(*head);
    	*head = NULL;
    return;
    }
    
	LInt prev;
    while (current->prox != NULL){
    	prev = current;
    	current = current->prox;
    }
    prev->prox = NULL;
    free(current);
}