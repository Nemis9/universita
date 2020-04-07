#include <stdio.h>

int lunghezza(char[]);

void main(){
	char a[] = "programmazione C";
	
	printf("%s\n", a);
	
	printf("a[4] = %d\n", a[4]);
	
	a[4] = 115;

	a[5] = a[5] + 1;
	
	a[1] = '*';
	
	a[0] = 'A'-'a'+a[0];

	a[6] = '\0';
	
	printf("%s\n", a);
	
	printf("%d\n", lunghezza(a));

}

int lunghezza(char b[]){
	int i = 0;
	
	while ( b[i] != '\0' ){
		i = i+1;
	}
	
	return i;
}
