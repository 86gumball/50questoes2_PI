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

void concatL (LInt *a, LInt b){
    LInt current = *a;

    /* Se *a for um apontador nulo, *a toma o valor de b */
    if (*a == NULL){
    	*a = b;
    	return;
    }

    /* Procura-se o último nodo de *a */
    while (current->prox != NULL){
    	current = current->prox;
    } 

    /* Liga-se o último nodo a b */
    current->prox = b;
}