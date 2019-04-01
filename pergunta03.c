void imprimeL (LInt head) {
	LInt current = head;
	while (current != NULL){
		printf("%d\n", (*current).valor);
		current = current->prox;
	} 
}

/* Teste usado
int main(){
    LInt new1 = newLInt(5, NULL);
    LInt new2 = newLInt(9, new1);
    LInt new3 = newLInt(2, new2);
    LInt new4 = newLInt(0, new3);
    LInt new5 = newLInt(3, new4);
    LInt new6 = newLInt(1, new5);
    imprimeL(new6);
    return 0;
}
*/