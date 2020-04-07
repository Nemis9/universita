#include <stdio.h>

int RicercaBinariaSX(int[], int, int);

void main(){
	int a[] = {0,0,1,1,1,1, 4, 6, 10, 11, 15, 17, 21, 23, 24, 24, 24, 24, 30, 36, 36};
	int n = sizeof(a)/sizeof(int);
	
	printf("%d\n", RicercaBinariaSX(a, n, 4));
}

/*
 * a e' ordinato e di dimensione n
 * 
 * restituisce i se i e' il minimo t.c. a[i] = k altrimenti -1
 * 
 * */
int RicercaBinariaSX(int a[], int n, int k){
	int sx = 0, dx = n-1;
	int cx;
	
	while(sx <= dx){
		cx = (dx+sx)/2;
		if( cx == 0 || (a[cx] == k && a[cx-1] != k) )
			return cx;
		if( k <= a[cx] ){
			dx = cx -1;
		} else {
			sx = cx+1;
		}
	}
	return -1;
}
