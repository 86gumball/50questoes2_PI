void freeL (LInt head){
	LInt tmp;
	while (&head->valor != NULL){
		tmp = head;
		head = head->prox;
		free(tmp);
	} 
}