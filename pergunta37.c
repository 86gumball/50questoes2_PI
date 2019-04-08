#include "abin.h"

/* Nota: Uma expressão de vários operadores AND pode ser representada pela multiplicação
   dos bools correspondentes, por exemplo:     V ^ V ^ V ^ F ^ V ^ V == F
                                           <=> 1 ^ 1 ^ 1 ^ 0 ^ 1 ^ 1 == 0
                                           <=> 1 * 1 * 1 * 0 * 1 * 1 == 0
   O valor de retorno desta função é a multiplicação de todas as condições, ou seja, basta
   apenas uma condição ser falsa para retornar falso, ou seja, as árvores não são iguais.
*/

int iguaisAB (ABin a, ABin b) {
	/* Casos de paragem */
	if (a == NULL && b == NULL){
		return 1;
	} else if (a == NULL && b != NULL){
		return 0;
	} else if (a != NULL && b == NULL){
		return 0;

	} else {
		/* Compara-se o valor dos dois nodos, se forem iguais chama-se a função recursivamente
		   aos ramos usando o princípio enunciado na Nota a cima, caso contrário é retornado
		   o valor 0. */
		if (a->valor == b->valor){
			return (iguaisAB(a->esq, b->esq) * iguaisAB(a->dir, b->dir));
		} else {
			return 0;
		} 
	} 
}