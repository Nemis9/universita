#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *StrCat(char[], char[]);

void main(){
	char a[1024];
	char b[1024];
	char *c;   /*puntatore a char */

	printf("Inserisci la stringa a :");
	scanf("%s", a);
	printf("Inserisci la stringa b :");
	scanf("%s", b);
	
	c =  StrCat(a, b);
	
	printf("%s\n", c);
}

char *StrCat(char a[], char b[]){
	int la = strlen(a);
	int lb = strlen(b);
	int i, j;

	char *c = malloc( (la+lb+1)*sizeof(char) );
	
	i = 0;
	j = 0;
	while ( a[j] != '\0'){
		c[i] = a[j];
		j = j+1;
		i = i+1;
	}
	j = 0;
	while ( b[j] != '\0'){
		c[i] = b[j];
		j = j+1;
		i = i+1;
	}
	c[i] = '\0';
	
	return c;
}
