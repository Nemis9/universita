#include <stdio.h>

int Max(int a[], int);

void main(){
	int a[] = {3,1,76,12,39,43,12,123,0,12,75,23};
	int n = sizeof(a)/sizeof(int);
	
	printf("%d\n", Max(a, n));
}

int Max(int x[], int n){
	int m;
	if (n == 1)
		return x[0];
	m = Max(x+1, n-1);
	
	if (m > x[0])
		return m;
	else
		return x[0];
}
