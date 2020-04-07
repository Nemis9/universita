#include <stdio.h>

int MaxFloat(float[], int);

void main(){
	int a[10]; /* 10 interi valore indefinito */
	float b[] = {3.14, 15, 2.72, 0, 9.18}; /*5 float, valore dato*/
	int c[10] = {0, 1, 2}; /*10 int, i primi 3 definiti i restanti 0*/
	
	/* una stringa e' un array di char */
	
	
	/*
	 * conversione implicita
	 * 
	 * */
	c[4] = c[4] + b[2] - c[1];
	
	
	/*
	 * casting o conversione esplicita
	 * 
	 * (nuovo tipo)valore
	 * 
	 * */
	
	c[5] = (int)(c[5] + b[2] - c[1]);
	
	printf("%d, %d\n", c[4], c[5]);
	
	printf("%d\n", MaxFloat(b, 5));
}


int MaxFloat(float a[], int n){
	int i, pm = 0;
	float 
	m = a[0];
	
	for(i = 1; i < n; i = i+1){
		if(  a[i] > m ){
			pm = i;
			m = a[i];
		}
	}

	return pm;
}
