#include "abin.h"

void mirror (ABin *a) {
	/* Não se faz nada quando *a == NULL */
	
    if (*a != NULL){
    	/* Troca-se os ramos esq e dir */
    	ABin tmp = (*a)->esq;
    	(*a)->esq = (*a)->dir;
    	(*a)->dir = tmp;

    	/* Chama-se a função recursivamente aos ramos */
    	mirror(&((*a)->esq));
    	mirror(&((*a)->dir));
    }
}