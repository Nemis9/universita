#include <stdio.h>
#include <string.h>

void BubbleSort(char**, int);

void main(){
	char *a[] =  {"python", "C++", "programma", "booh", "anvedi"};
	int i, n = sizeof(a)/sizeof(char*);

	BubbleSort(a, n);
	
	for(i = 0; i < n; i = i+1){
		printf("%s\n", a[i]); 
	}
}

/*
 * alternativamente  BubbleSort(char **a, int n)
 * 
 */
void BubbleSort(char *b[], int n){
	int i,j; 
	char *c;
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
			if( strcmp(b[j], b[j+1]) > 0 ){ 
				c = b[j];
				b[j] = b[j+1];
				b[j+1] = c;
				ordinato = 0;
			}
		}
		i = i+1;
	}
}
