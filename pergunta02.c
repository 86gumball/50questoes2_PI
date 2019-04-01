void freeL (LInt head){
	while (head != NULL){
		LInt tmp = (LInt) malloc (sizeof (struct linkedlist));
		tmp = head;
		head = head->prox;
		free(tmp);
	} 
}