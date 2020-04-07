#include <stdio.h>
#include <string.h>

void BubbleSort(char[]);

void main(){
	
	char a[] = "programmazione";

	BubbleSort(a);
	
	printf("%s\n", a);
}

void BubbleSort(char b[]){
	int n = strlen(b);
	int i,j;
	char c;
	
	for (i = 0;  i < n-1; i = i+1 ){
		for(j = 0; j < n-1; j = j+1){
			if( b[j] > b[j+1]){
				c = b[j];
				b[j] = b[j+1];
				b[j+1] = c;
			}
		}
	}
}
