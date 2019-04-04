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

LInt somasAcL (LInt head) {
	/* Se head for um apontador nulo a função retorna um apontador nulo */
	if (head == NULL){
		return NULL;
	}
	LInt current = head; // Apontador que percorre a lista

	int soma = current->valor; // Inteiro onde é guardado a somaAc
	LInt listaSomas = newLInt(soma, NULL); // Primeiro nodo da lista
	LInt currentSomas = listaSomas; // Apontador que vai percorrer a nova lista

	/* Loop em que current está sempre 1 indice à frente de currentSomas (em listas diferentes).
	   É acrescentado a soma o valor guardado no nodo current e a currentSomas é ligado um novo
	   nodo com o valor de soma. A cada iteração current e currentSomas passam a apontar para o
	   nodo seguinte */
	while (current != NULL){
		current = current->prox;
		if (current != NULL){
			soma += current->valor;
			currentSomas->prox = newLInt(soma, NULL);
			currentSomas = currentSomas->prox;
		}
	} 
    return listaSomas; // Apontador para o primeiro nodo da nova lista
}