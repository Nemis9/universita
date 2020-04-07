#include <stdio.h>
#include <stdlib.h>

void f( float x[][3]);
float maxmat(float x[][3], int, int);
float minmat(float x[], int, int);


void main(){
	float a[2][3] ={ {0, 1, 2}, {3, 4, 5} };
	float b[2][3] ={ 0, 1, 2, 3, 4, 5 };
	float c[][3] ={ 0, 1, 2, 3, 4, 5 };
	float d[][2] ={ 0, 1, 2, 3, 4, 5 };
	float e[] = { 0, 1, 2, 3, 4, 5, -7, 4 };
	int R = 4, C  = 2;
	float *f[2];
	/*
	 * 
	 *  float d[][] ={ 0, 1, 2, 3, 4, 5 };   ILLEGALE
	 *  float e[2][] ={ 0, 1, 2, 3, 4, 5 };	 ILLEGALE
	*/
	
	printf("%.1f\n", maxmat(c,2,3));
	/*printf("%.1f\n", maxmat(d,3,2));  ILLEGALE...o quasi*/
	
	printf("%.1f\n", e[1*C+2]);
	printf("%.1f\n", minmat(e, C, R));

	/*
	 * array di array
	 *
	 * */
	f[0] = malloc(3*sizeof(float));
	f[1] = malloc(9*sizeof(float));
	f[0][1] = 4;
	
}

void f( float x[][3]){
	printf("%.1f\n", x[0][1]);
}

/*
 * necessario indicare seconda dimensione della matrice
 *
 * */
float maxmat(float x[][3], int r, int c){
	int i, j;
	float m = x[0][0];
	
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			if (x[i][j] > m)
				m = x[i][j];
	return m;
}

/*
 * l'array lineare x visto come matrici rxc
 *
 * */
float minmat(float x[], int r, int c){
	int i, j;
	float m = x[0];
	
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			if (x[i*c+j] < m)
				m = x[i*c+j];
	return m;
}
