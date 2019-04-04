LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

LInt cloneL (LInt head){

	/* Caso head seja um apontador nulo a função devolve um apontador nulo */
    if (head == NULL){
        return NULL;
    }
    LInt new = newLInt(head->valor, NULL); // Nodo inicial / apontador a ser returned
    LInt current = head;				   // Apontador que percorre a lista inicial
    LInt currentNew = new; 				   // Apontador que percorre a lista clonada

    while (current != NULL){
        current = current->prox;

        /* Após current sera atualizado, testa se current é um nodo válido, caso seja
           é simultaneamente criado um nodo com o valor do nodo current e ligado ao
           nodo currentNew. Depois atualiza-se currentNew para o novo nodo criado */
        if (current != NULL){
            currentNew->prox = newLInt(current->valor, NULL);;
            currentNew = currentNew->prox;
        } 
    } 
    return new;
}

/*
Teste utilizado:

int main(){
	LInt new1 = newLInt(22, NULL);
    LInt new2 = newLInt(10, new1);
    LInt new3 = newLInt(5, new2);
    LInt new4 = newLInt(1, new3);
    imprimeL(new4);
    LInt novo = cloneL(new4);
    printf("\n\n");
    imprimeL(novo);
    return 0;
} 

*/