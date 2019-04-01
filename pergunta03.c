void imprimeL (LInt head) {
	while (head != NULL){
		printf("%d\n", (*head).valor);
		head = head->prox;
	} 
}