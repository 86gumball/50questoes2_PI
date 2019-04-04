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

int length (LInt head){
    int i;
    for (i = 0; head != NULL; i++){
    	head = head->prox;
    }
    return i;
}

int drop (int n, LInt *head){
    LInt current = *head; // Apontador usado para percorrer a lista
    int len = length(current); // length da lista

    /* Se houver mais elementos a eliminar que elementos na lista, é libertada toda a memória
       da lista e *head passa a ser um apontador nulo. Devolve-se a lenght da lista pois é o
       número de elementos eliminados */
    if (n >= len){
    	freeL(current);
    	*head = NULL;
    	return len;
    }

    int i;

    /* Atualiza-se current até chegar ao último elemento a ser eliminado */
    for (i = 0; i < (n-1); i++){
    	current = current->prox;
    } 
    LInt output = current->prox; // Guarda-se a posição do elemento seguinte
    current->prox = NULL; // Separa-se a lista em dois (eliminados/restantes)
    freeL(*head); // Liberta-se a lista do eliminados
    *head = output; // Atualiza-se o apontador
    return n;
}