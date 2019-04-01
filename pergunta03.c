void imprimeL (LInt head) {
	while ((*head).valor != NULL){
		printf("%d\n", (*head).valor);
		head = head->prox;
	} 
}