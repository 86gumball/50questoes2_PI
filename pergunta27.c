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

LInt parte (LInt current){
	int i;

	LInt evenStart = newLInt(86, NULL); // Cria-se um nodo "falso" que é removido no fim
	LInt oddStart = newLInt(86, NULL);  // Cria-se um nodo "falso" que é removido no fim

	LInt even = evenStart; // Apontador que percorre a lista de indices pares
	LInt odd = oddStart;   // Apontador que percorre a lista de indices ímpares

	for (i = 1; current != NULL; i++){
		if (i % 2 == 0){             // Se for par:
			even->prox = current;    //     - even aponta para current
			even = even->prox;       //     - even avança um nodo para a frente
			current = current->prox; //     - current avança um nodo para a frente
			even->prox = NULL;       //     - fecha-se a lista even
		} else { // O processo para a lista ímpar é exatamente igual
			odd->prox = current;
			odd = odd->prox;
			current = current->prox;
			odd->prox = NULL;
		} 
	} 

	LInt tmp = evenStart;        // tmp guarda o nodo a ser removido
	evenStart = evenStart->prox; // evenStart passa a apontar para o verdadeiro início da lista
	free(tmp);                   // O nodo com o 86 é libertado da memória

	tmp = oddStart;              // tmp guarda o nodo a ser removido
	oddStart = oddStart->prox;   // oddStart passa a apontar para o verdadeiro início da lista
	free(tmp);                   // O nodo com o 86 é libertado da memória

	return evenStart;            // Return para o apontador do começo da nova lista
}