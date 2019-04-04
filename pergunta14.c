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
	LInt new = newLInt(x, NULL);
	LInt current = *head;
	if (*head == NULL){
		*head = new;
		return;
	}
	if ((*head)->prox == NULL){
		(*head)->prox = new;
		return;
	}
	while (current->prox != NULL){
		current = current->prox;
	} 
	current->prox = new;
}