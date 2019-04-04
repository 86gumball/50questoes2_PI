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

int maximo (LInt head){
    LInt current = head; // Apontador usado para percorrer a lista
    int max = current->valor; // int onde é armazenado o maior valor

    while (current != NULL){

    	/* Compara o valor no nodo com max, se o valor for maior que max, max é atualizado */
    	if (current->valor > max){
    		max = current->valor;
    	}

    	/* current passa a apontar para o nodo seguinte */
    	current = current->prox;
    } 
    return max;
}