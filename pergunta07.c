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
	LInt l1c = l1; // Apontador que percorre l1
	LInt l2c = l2; // Apontador que percorre l2
	LInt current = *r;
	if (l1 == NULL && l2 == NULL){
		*r = NULL;
		return;
	}
	if (l1c == NULL){
		(*r)->valor = l2c->valor;
		(*r)->prox = NULL;
		current = *r;
		l2c = l2c->prox;
		while (l2c != NULL){
            current->prox = newLInt(l2c->valor, NULL);
            l2c = l2c->prox;
            current = current->prox;
        } 
        return;
	} else if (l2c == NULL){
		(*r)->valor = l1c->valor;
		(*r)->prox = NULL;
		current = *r;
		l1c = l1c->prox;
		while (l1c != NULL){
			current->prox = newLInt(l1c->valor, NULL);
			l1c = l1c->prox;
			current = current->prox;
		}
	}
	if (l1c->valor < l2c->valor){
		(*r)->valor = l1c->valor;
		current = *r;
		l1c = l1c->prox;
	} else {
		(*r)->valor = l2c->valor;
		current = *r;
		l2c = l2c->prox;
	} 
	while (l1c != NULL && l2c != NULL){
		if (l1c->valor < l2c->valor){
			current->prox = newLInt(l1c->valor, NULL);
			l1c = l1c->prox;
			current = current->prox;
		} else {
			current->prox = newLInt(l2c->valor, NULL);
			l2c = l2c->prox;
			current = current->prox;
		} 
	} 
	if (l1c == NULL){
		while (l2c != NULL){
			current->prox = newLInt(l2c->valor, NULL);
			l2c = l2c->prox;
			current = current->prox;
		} 
	} else {
		while (l1c != NULL){
			current->prox = newLInt(l1c->valor, NULL);
			l1c = l1c->prox;
			current = current->prox;
		} 
	} 
}