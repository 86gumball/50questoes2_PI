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

void merge (LInt *r, LInt l1, LInt l2){
	*r = newLInt(86, NULL); // Cria-se um nodo "falso" que é removido no fim
	LInt current = *r; // Apontador que percorre a lista

	while (l1 != NULL || l2 != NULL){
		/* Caso l1 ou l2 estejam vazios, basta ligar current a l1 ou l2 (dependendo de qual está vazio)
		   e quebrar o loop que a lista está ordenada */
		if (l1 == NULL){
			current->prox = l2;
			break;
		} else if (l2 == NULL){
			current->prox = l1;
			break;
		} 

		/* Caso nenhuma das listas seja vazia, é preciso fazer algum "rewiring" dependendo de qual dos valores
		   na cabeça da lista é menor. */
		else {
			if (l1->valor < l2->valor){
				current->prox = l1;      // current passa a apontar para l1
				l1 = l1->prox;           // l1 anda um nodo para a frente
				current = current->prox; // current anda um nodo para a frente
			} else {
				current->prox = l2;
				l2 = l2->prox;
				current = current->prox;
			} 
		} 
	}

	current = *r;    // Current guarda o nodo a ser removido (rip 86 :c )
	*r = (*r)->prox; // *r passa a apontar para o verdadeiro início da lista merged
	free(current);   // O nodo com o 86 é libertado da memória
}