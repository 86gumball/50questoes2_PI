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

int listToArray (LInt head, int v[], int N){
	LInt current = head; // Apontador que percorre a lista

	/* Loop que percorre a lista, inserindo na posição i o valor guardado no nodo
	   current, após ser inserido o apontador current é atualizado para a posição
	   seguinte. No final é returnado i, que corresponde ao número de elementos
	   inseridos no array v */
	int i;
	for (i = 0; i < N && current != NULL; i++){
		v[i] = current->valor;
		current = current->prox;
	} 
	
    return i;
}