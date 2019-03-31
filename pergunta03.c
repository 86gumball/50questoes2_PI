void imprimeL (LInt head) {
	LInt tmp;
	while (&tmp->valor != NULL){
		printf("%d\n", &tmp->valor);
		tmp = tmp->prox;
	} 
}