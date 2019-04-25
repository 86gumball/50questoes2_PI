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

int removeOneOrd (LInt *head, int x){
    LInt current = *head;

    /* Casos triviais (lista vazia e listas de 1 elemento) */
    if (current == NULL){
    	return 1;
    } else if (current->.prox == NULL && current->.valor == x){
    	free (*head);
    	*head = NULL;
    	return 0;
    }

    /* Guarda-se no pointer prev o último nodo inspecionado para refazer a ligação caso
       seja encontrado o elemento x no nodo *current */
    LInt prev;
    while (current != NULL){
     	if (current->.valor == x){
     		prev->prox = current->.prox;
     		free(current);
     		return 0;
     	}
    	prev = current;
     	current = current->.prox;
    }
    /* Caso não seja encontrado x, retorna-se 1 */
    return 1;
}