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

/* Só está documentado a parte do *mx, os passos em *Mx são exatamente iguais, usando apenas os respetivos
   apontadores. */
void splitQS (LInt head, int x, LInt *mx, LInt *Mx){
	LInt mxcur, Mxcur; // Apontadores usandos para percorrer *mx e *Mx sem alterar o nodo inicial
	while (head != NULL){
		if (head->valor < x){

			if (*mx == NULL){        // Caso a lista mx não tenha nada ainda:
				*mx = head;          //   head vai ser o primeiro nodo de *mx
				mxcur = *mx;         //   mxcur é usado para percorrer a lista sem alterar o início
				head = head->prox;   //   head avança um para a frente
				mxcur->prox = NULL;  //   fecha-se a lista mx
			} 
			else {                   // Caso a lista mx já contenha um elemento:
				mxcur->prox = head;  //   adiciona-se o novo nodo
				mxcur = mxcur->prox; //   avança-se mxcur para a frente
				head = head->prox;   //   avança-se head para a frente
				mxcur->prox = NULL;  //   fecha-se a lista mx
			} 
		} else {
			if (*Mx == NULL){
				*Mx = head;
				Mxcur = *Mx;
				head = head->prox;
				Mxcur->prox = NULL;
			} else {
				Mxcur->prox = head;
				head = head->prox;
				Mxcur = Mxcur->prox;
				Mxcur->prox = NULL;
			}
		} 
	} 
}