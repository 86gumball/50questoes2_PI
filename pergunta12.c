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

int removeMaiorL (LInt *head){
	LInt tmp; // Apontador onde são guardados os endereço de memória a ser libertados
	LInt prev; // Apontador sempre 1 nodo atrás de current
	LInt current = *head; // Apontador que percorre a lista
	int max = current->valor;

	/* Loop que procura o valor do maior elemento da lista ligada */
	while (current != NULL){
		if (current->valor > max){
			max = current-> valor;
		}
		current = current->prox;
	} 

	/* Se o maior elemento da lista encontrar-se na primeira posição, o apontador *head é atualizado,
	   é libertado da memória o primeiro nodo e a função acaba prematuramente */
	if ((*head)->valor == max){
		tmp = *head; // tmp guarda o valor do apontador head
		*head = (*head)->prox; // *head passa a apontar um nodo à frente
		free(tmp); // a antiga posição de *head é libertada da memória
		return max;
	}

	current = *head; // current passa a apontar para o início

	/* Loop que percorre a lista até encontra o maior elemento */
	while (current->valor != max){
		prev = current;
		current = current->prox;
	} 
	tmp = current; // tmp guarda o endereço da memória a ser libertada
	prev->prox = current->prox; // prev avança um nodo à frente na ligação, ignorando o que tem o maior elemento
	free(tmp); // o nodo com o maior número é libertado da memória
    return max;
}