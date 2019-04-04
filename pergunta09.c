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

LInt parteAmeio (LInt *head){
	LInt start = *head; // Aponta para a primeira posição sempre
	LInt current = *head; // Apontador que percorre a lista
    int len = length (current);

    /* Se o comprimento da lista for igual a 1 significa que a lista x = {8} parte-se em
       y = {8} e x = {}, logo x (o return) passa a ser um apontador nulo */
    if (len == 1){
    	return NULL;
    }

    /* Percorre a lista até ao ultimo elemento que fica em y */
    int meio = len/2;
    int i;
    for (i = 0; i + 1 < meio; i++){
    	current = current->prox;
    }

    *head = current->prox; // Apontador inicial *head passa a apontar para o começo da segunda lista
    current->prox = NULL; // O ultimo elemento de y corta a ligacão à lista x
    return start;
}