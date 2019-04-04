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

LInt cloneRev (LInt head){
    LInt current = head; // Apontador que percorre a lista

    /* Se head for um apontador nulo a função retorna um apontador nulo */
    if (head == NULL){
    	return NULL;
    }
    LInt new = NULL; // Apontador da nova lista

    /* A função newLInt insere o novo nodo sempre antes da lista, assim percorremos a lista
    current e vamos inserindo os números em new do fim para o início atualizando sempre o
    apontador new, que no final do loop aponta para a posição inicial */
    while (current != NULL){
    	new = newLInt(current->valor, new);
    	current = current->prox;
    } 
    return new;
}