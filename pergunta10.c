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

/* Nota_1: Esta implementação não limpa a memória dos nodos removidos
   Nota_2: O primeiro while loop:

    while (*head != NULL){
        if ((*head)->valor == x){
            *head = (*head)->prox;
            contaRM++;
        } else {
            break;
        } 
    } 
    
   não pode ser escrito da seguinte maneira:

    while ((*head)->valor == x && *head != NULL){
        *head = (*head)->prox;
        contaRM++;
    } 
   
   Porque embora pareção iguais, a segunda implementação avalia ambas as condições:
    (*head)->valor == x        e        *head != NULL
   e em listas do tipo y = {i, i, i, i, i}, tentar avaliar a primeira condição quando
   *head == NULL resulta num segmentation fault 

   Nota_3: O LInt prev não precisa de ser atribuido um valor fora do loop porque da primeira 
   vez que o loop é executado a condição current->valor == x é sempre falsa, pois o primeiro 
   loop só acaba quando a condição (*head)->valor == x é falsa */

int removeAll (LInt *head, int x){
    int contaRM = 0; // Contador de número removidos

    /* Loop que atualizada o apontador *head enquanto o primeiro elemento da lista ligada
       é igual ao número a ser removido */
    while (*head != NULL){
        if ((*head)->valor == x){
            *head = (*head)->prox;
            contaRM++;
        } else {
            break;
        } 
    } 

    /* Se no final do loop *head for um apontador nulo (ex: todos os elementos foram removidos)
       a função acaba prematuramente */
    if (*head == NULL){
        return contaRM;
    }

    LInt current = *head; // Apontador que percorre a lista
    LInt prev; // Apontador sempre 1 indice atrás de current

    /* Loop que percorre o resto da lista e:
          - Se o valor guardado em current é x, então current avança 1 nodo para a frente, 
          e prev->prox passa a apontar para esse nodo. contaRM aumenta 1
          - Caso contrário prev e current andam ambos um nodo para a frente */
    while (current != NULL){
        if (current->valor == x){
            current = current->prox;
            prev->prox = current;
            contaRM++;
        } else {
            prev = current;
            current = current->prox;
        } 
    } 
    return contaRM;
}