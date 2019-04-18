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

int length (LInt head){
    int i;
    for (i = 0; head != NULL; i++){
    	head = head->prox;
    }
    return i;
}

/* Ver pergunta25 */
void removeInt (LInt head, int x){
	LInt prev = head; 
	head = head->prox; 
	while (head != NULL){
		if (head->valor == x){
			prev->prox = head->prox;
			free(head);
			head = prev->prox;
		} 
		else {
			prev = prev->prox;
			head = head->prox;
		} 
	} 
}

int removeDups (LInt *head){
	int start = length(*head); // tamanho inicial
	if (start == 0){
		return 0;
	}
	LInt cur = *head;

	/* remove-se os repetidos */
	while (cur != NULL){
    	removeInt (cur, cur->valor);
    	cur = cur->prox;
    } 
    int end = length(*head); // tamanho final
    return (end - start); // removidos = tamanho final - inicial
}