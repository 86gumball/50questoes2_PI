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

LInt reverseL (LInt head){
	LInt prev = NULL;
	LInt tmp;
	while (head != NULL){
		tmp = head->prox;
		head->prox = prev;
		prev = head;
		head = tmp;
	} 
    return prev;
}