#include <stdio.h>
#include <math.h>
#include <time.h>
#include <float.h>
#include <stdlib.h>

/*AVVERTENZA!
 * SE USATE NUMERI GRANDI, COMMENTATE LA PARTE DI FIBONACCI2*/

long long int arrotondamento(long double x);
long double fibonacci1(int n);
long long int fibonacci2(long long int n);
long long int fibonacci3(int n);
long long int fibonacci4(int n);

int main(){
	clock_t start, end;
	int input;
	long long int out;
	long double outFibonacci1;
	printf("inserisci numero: ");
	scanf("%d",&input);
	start = clock();
	outFibonacci1 = fibonacci1(input);
	end=clock();
	printf("risultato fibonacci1: %Llf con arrotondamento %Lli: tempo %lli \n", outFibonacci1, arrotondamento(outFibonacci1), end - start);
	/*
	start = clock();
	out = fibonacci2(input);
	end=clock();
	printf("risultato fibonacci2: %Lli tempo %lli \n", out, end - start);
	*/
	start = clock();
	out = fibonacci3(input);
	end=clock();
	printf("risultato fibonacci3: %Lli tempo %lli \n", out, end - start);
	start = clock();
	out = fibonacci4(input);
	end=clock();
	printf("risultato fibonacci4: %Lli tempo %lli \n", out, end - start);
	return 0;
}

long long int arrotondamento(long double x){
	long long int parteIntera = (int) x;
	if(x - parteIntera >= 0.501){
		return parteIntera + 1;
	}
	return parteIntera;
}

/*dovrebbe ritornare un intero, ma per dimostrazione faccio ritornare il valore non arrotondato*/
long double fibonacci1( int n){
	long double temp= (1/sqrt(5));
	long double roP = pow(1.618,n);
	long double roN = pow(-0.618,n);
	return temp*(roP - roN);
}

long long int fibonacci2(long long int n){
	if(n <= 2){
		return 1;
	}
	return fibonacci2(n - 1) + fibonacci2(n-2);
}


long long int fibonacci3(int n){
	long int fib[n];
	fib[0]=1;
	fib[1]=1;
	for (long long int var = 2; var < n; var++) {
		fib[var] = fib[var - 1] + fib[var - 2];
	}
	return fib[n - 1];
}
long long int fibonacci4(int n){
	long int a = 1;
	long int b = 1;
	for (int var = 2; var < n; var++){
		long int c = a + b;
		b = a;
		a = c;
	}
	return a;
}

