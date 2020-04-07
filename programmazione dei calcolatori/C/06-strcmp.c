#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int StrCat(char[], char[]);
int StrCat1(char[], char[]);

void main(){
	char a[1024];
	char b[1024];
	int c;   

	printf("Inserisci la stringa a: ");
	scanf("%s", a);
	printf("Inserisci la stringa b: ");
	scanf("%s", b);
	
	c =  StrCat1(a, b);
	
	printf("%d\n", c);
}

/*
 * restituisce
 *
 * 		0 se a è uguale a b
 * 		-1 se a precede b
 * 		1 se b precede a
 *
 * */
int StrCat(char a[], char b[]){
	int i = 0;
	
	while( a[i] == b[i] && a[i] != '\0' ){
		i = i+1;
	}
	
	if (a[i] == '\0'){
		if ( a[i] == b[i] )
			return 0;
		else
			return -1; /*a prefisso di b*/
	} else{
		if (b[i] == '\0')
			return 1; /* b prefisso di a*/
		else {
			if (a[i] < b[i])
				return -1;
			else
				return 1;
		}
	}
}



int StrCat1(char a[], char b[]){
	int i = 0;
	
	while( a[i] == b[i] ){
		if(a[i] == '\0' )
			return 0;
		i = i+1;
	}
	
	if (a[i] == '\0' || a[i] < b[i] )
		return -1;
		
	return 1;
}
