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

LInt arrayToList (int v[], int N){
	/* Se v for um array vazio, a função retorna um apontador nulo */
    if (N == 0){
        return NULL;
    }
    LInt head = newLInt(v[0], NULL); // Cria-se o primeiro nodo com o primeiro elemento de v
    LInt current = head; // Apontador que percorre a lista

    /* Loop que insere na posição a seguir ao nodo current um novo nodo com valor v[i], depois
       current passa a apontar para o nodo seguinte. Nota: o loop começa em i = 1 porque ao
       inicializar head é lhe atribuido logo uma componente valor correspondente a v[0] */
    int i;
    for (i = 1; i < N; i++){
        current->prox = newLInt(v[i], NULL);
        current = current->prox;
    } 
    return head; // É retornado o apontador para o primeiro nodo da lista
}