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

// LInt (*head) ->   (head) é um apontador para um apontador para uma struct lligada
// LInt (*head) ->  (*head) é                   um apontador para uma struct lligada
// LInt (*head) -> (**head) é                                     uma struct lligada

void insertOrd (LInt *head, int x){

	/* O pointer (*head) deve apontar sempre pare o inicio da lista, logo só é modificado caso
	   seja inserido um elemento na primeira posição, por isso é criado o pointer current que
	   pode ser alterado sem efeitos laterais à função principal. */

	/* Nota: current = *head <=> *current = **head, ou seja *current é a lligada em questão.*/
	LInt current = *head;

	/* Se for introduzido um valor numa lligada inexistente, é criada uma nova lligada e o 
	   apontador (*head) toma o valor da primeira posição da nova lista (newLInt retorna um
	   apontador para uma lista ligada). */
	if (current == NULL){
		LInt new = newLInt (x, NULL);
		*head = new;
		return;
	}

	int i;
	LInt tmp;

	/* O loop percorre a lligada até encontrar um nodo com valor maior que x ou até detetar
	   que está no ultimo nodo, guardando a última posição pela qual passou no apontador tmp */
    for (i = 0; x > (*current).valor && (*current).prox != NULL; i++){
    	tmp = current;
    	current = (*current).prox;
    }

    /* Se x for maior que o valor guardado em *current significa que estamos no fim da lligada
       (Loop acaba porque (*current).prox == NULL)) e é criado um nodo com valor x a apontar para
       NULL que é inserido no final da lista. */
    if (x > (*current).valor){
    	LInt new = newLInt (x, NULL);
    	(*current).prox = new;

    /* Caso este else statement seja avaliado sabe-se que x <= (*current).valor */
    } else {
    	/* É criado um novo nodo com o valor x que é localizado ANTES do nodo current. */
    	LInt new = newLInt (x, current);

    	/* Se o nodo não passou pelo loop significa que x é o menor valor da nova lligada,
    	logo, o pointer *head é atualizado para o pointer do novo nodo criado. */
    	if (i == 0){
    		*head = new;

    	/* Caso contrário, o pointer que guarda a posição anterior ao novo nodo adicionado,
    	   é usado para aceder a componente prox e atualizar com o valor do novo nodo,
    	   ligando assim a lista ligada por completo. */
    	} else {
	    	(*tmp).prox = new;
    	} 
    }
}