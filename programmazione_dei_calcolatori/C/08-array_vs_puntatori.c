#include <stdio.h>
#include <stdlib.h>

float *SommaArray(float[], float[], int);
float *ClonaArray(float[], int);

void main(){
	float a[] = {1, 0, 7, 3, 9, -10};
	float b[] = {-1, 4, 7, 1, 5, 6};
	float *c, *d;
	int i,n = sizeof(a)/sizeof(float);
	
	d = SommaArray(a, b, n);
	c = ClonaArray(d, n);
	
	if( c != NULL){
		for(i = 0; i < n; i	 = i+1){
			printf("%.2f\t", c[i]); 
		}
		printf("\n");
	}
}

/*
 * 
 * a e b hanno dimensione n
 * 
 * Restituisce NULL oppure un array di n float
 * c t.c. c[i] = a[i] + b[i] per ogni
 * i=0,...,n-1
 * 
 * */
float *SommaArray(float a[], float b[], int n){
	float *c = malloc(n*sizeof(float));
	int i;
	
	if (c == NULL)
		return NULL;
		
	for(i = 0; i < n; i = i+1){
		c[i] = a[i] + b[i];
	}
	
	return c;
}

/*
 * a ha dimensione n
 * 
 * restituisce NULL oppure una copia dell'array a
 * 
 * */
float *ClonaArray(float a[], int n){
	float b[n];
	int i;
	for(i = 0; i < n; i = i+1)
		b[i] = 0;
	return SommaArray(a, b, n);
}
