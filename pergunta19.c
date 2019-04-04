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

void freeL (LInt head){
	LInt tmp;
	while (head != NULL){
		tmp = head;
		head = head->prox;
		free(tmp);
	} 
}

int take (int n, LInt *head){
	LInt current = *head;
	int i;
    for (i = 0; i < (n-1) && current != NULL; i++){
    	current = current->prox;
    } 
    if (current == NULL){
    	return i;
    }
    LInt freeMe = current->prox;
    current->prox = NULL;
    freeL(freeMe);
    return ++i;
}