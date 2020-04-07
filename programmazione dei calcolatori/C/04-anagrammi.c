#include <stdio.h>
#include <string.h>

void BubbleSort(char[]);



void main(){
	
	char a[] = "programmazione";
	char b[] = "erparomzmainog";
	char c[] = "erparxmzmainog";


	BubbleSort(a);
	BubbleSort(b);
	BubbleSort(c);
	
	if ( strcmp(a,b) == 0 )
		printf("a e' anagramma di b\n");
	else
		printf("a non e' anagramma di b\n");

	if ( strcmp(a,c) == 0 )
		printf("a e' anagramma di c\n");
	else
		printf("a non e' anagramma di c\n");

	
}

void BubbleSort(char b[]){
	int n = strlen(b); /* circa n operazioni */
	int i,j; 
	char c;
	int ordinato = 0;
	
	/*   circa n*n operazioni nel caso peggiore */
	i = 0;
	while ( ordinato == 0 ){
		ordinato = 1;
		for(j = 0; j < n-1-i; j = j+1){
			/* test if eseguito nel caso peggiore
			 * 
			 * (n-1) + (n-2) + ... + 2 + 1 = n(n-1)/2 
			 * */
			if( b[j] > b[j+1]){ 
				c = b[j];
				b[j] = b[j+1];
				b[j+1] = c;
				ordinato = 0;
			}
		}
		i = i+1;
	}
	
	/*
	 * Numero totale di operazioni nel caso peggiore:
	 * 
	 *n(n-1)/2 = n*n
	 * 
	 * algoritmo nel caso peggiore ha costo
	 * quadratico nella grandezza dell'input
	 * 
	 * */
}
