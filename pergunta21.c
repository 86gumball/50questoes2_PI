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

LInt NForward (LInt head, int N){
    LInt current = head; // Apontador que percorre a lista

    /* Loop que percorre a lista, a cada iteração N diminui, ou seja, faltam percorrer
       menos 1 elementos que antes, quando N == 0 o loop para e retorna-se o endereço
       guardado em current */
    int i;
    while (N--){
    	current = current->prox;
    } 
    return current;
}