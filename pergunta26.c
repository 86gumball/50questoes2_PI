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

LInt rotateL (LInt head){
	/* Casos de listas vazias ou listas de 1 único elemento, em que não acontece nada
	   e é returned o própio apontador */
    if (head == NULL || head->prox == NULL){
    	return head;
    }
    LInt current = head; // Apontador que percorrer a lista
    LInt newStart = head->prox; // Apontador que marca o começo da nova lista
    LInt firstNode = head; // Apontador que marca o nodo a ser colocado no fim da lista

    /* Loop que percorre a lista até encontrar o último nodo */
    while (current->prox != NULL){
    	current = current->prox;
    } 

    current->prox = firstNode; // O último nodo passa a apontar para o primeiro
    firstNode->prox = NULL; // O (antigo) primeiro nodo passa a apontar para NULL (fim de lista)

    return newStart; // Retorna-se a posição do primeiro nodo da nova lista
}