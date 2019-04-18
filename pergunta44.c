#include "abin.h"

int addOrd (ABin *root, int x) {

	/* Caso *root seja vazio, cria-se uma nova árvore binária com o valor x e ramos nulos, e atualiza-se
	   o apontador *root */
	if (*root == NULL){
		ABin new = (ABin) malloc(sizeof(ABin));
		new->valor = x;
		new->esq = NULL;
		new->dir = NULL;
		*root = new;
		return 0;
	}

	ABin current = *root; // Apontador que percorre a ABin
	ABin prev; // Apontador sempre 1 nodo atrás de current

	/* Loop que guarda em prev o nodo no qual se vai criar um novo ramo */
	while (current != NULL){
		/* Se se encontrar o valor x na árvore binária, é dado logo return de 1 e não se
		   adiciona um novo nodo. */
		if (current->valor == x){
			return 1;
		}
		
		prev = current; // prev toma o valor de current

		/* Avança-se current 1 nodo para a esquerda ou direita, dependendo se x é maior ou
		   menor que o que está guardado em current. */
		if (x < current->valor){
			current = current->esq;
		} else {
			current = current->dir;
		} 
	}

	/* Novo nodo com o valor de x e ramos nulos. */
	ABin new = (ABin) malloc(sizeof(ABin));
	new->valor = x;
	new->esq = NULL;
	new->dir = NULL;

	/* Se x for menor que o valor de prev, liga-se o ramo à esquerda, caso contrário, liga-se o
	   ramo à direita. */
	if (x < prev->valor){
		prev->esq = new;
	} else {
		prev->dir = new;
	} 
    return 0; // return 0 pois o ramo foi inserido com sucesso.
}