#include <stdio.h>
#include <stdlib.h>

void Permutazioni(char*, int);

void main(){
	char t[] = "abcd";

	int n = sizeof(t)/sizeof(char)-1;
	Permutazioni( t, n );
}

void Scambia(char *a, int i, int j){
	char c = a[i];
	a[i] = a[j];
	a[j] = c;
}

/*
 * Genera tutte le permutazioni dei primi k elementi
 * di t.
 * 
 * */
void Permutazioni(char *t, int k){
/*
 * Determino il valore di  t[k-1] invoco
 * Permutazioni(t, k-1)
 * */
	int i;
	if (k == 0)
		printf("%s\n", t);
	else {
		for(i = 0; i < k; i++){
			Scambia(t, i, k-1);
			Permutazioni(t, k-1);
			Scambia(t, i, k-1);
		}
	}
	
	
}
