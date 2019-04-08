#include "abin.h"

/* Esta pergunta é práticamente igual à pergunta29, apenas ao chamar a função recursivamente
   ao seus ramos, é enviado como argumento para criação do ramo esquerdo a informação do ramo
   direito e vice-versa. */

ABin cloneMirror (ABin root) {
	ABin new = NULL;
	if (root != NULL){
    	new = (ABin) malloc (sizeof (struct nodo));
    	new->valor = root->valor;
    	new->esq = cloneMirror(root->dir);
    	new->dir = cloneMirror(root->esq);
	}
    return abin;
}