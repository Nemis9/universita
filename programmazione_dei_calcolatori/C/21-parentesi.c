#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mp(char*, int, int);

void main(){
	char a[] = "()*(()())(())";
	int i, n = strlen(a)-1;
	int p;
	char *par = malloc((n+1)*sizeof(char));
	int m,j = 0;
	/*
	 * La posizione dei * in a identifica la posizione della parentesi
	 * da abbinare
	 *
	 * par e' ricavarto da a togliendo *
	 * 
	 */
	for(i = 0; i < n+1; i++){
		if(a[i] == '*')
			p = i;
		else {
			par[j] = a[i];
			j++;
		}		
	} 
	par[n] = '\0';
	
	m = mp(par, p, n);
	
	printf("%s\n", par);
	for( i = 0; i < n; i++){
		if( i == p || i == m)
			printf("^");
		else
			printf(" ");
	}
	printf("\n");
}


/*
 * a: stringa di parentesi ( ) di lunghezza n
 * 
 * restituisce la posizione della parentesi corrispondente
 * a quella in posizione k.
 * 
 * */
int mp(char x[], int k, int n){
	int i, naperte, nchiuse;
	
	if( x[k] == '(' ){
		i = k+1; naperte = 1;
		while( naperte > 0 && i < n){
			if( x[i] == '(' )
				naperte++;
			else
				naperte--;
			i++;
		}
		if( naperte == 0 )
			return i-1;
		return -1;
	} else {
		i = k-1; nchiuse = 1;
		while( nchiuse > 0 && i >= 0){
			if( x[i] == ')' )
				nchiuse++;
			else
				nchiuse--;
			i--;
		}
		if( nchiuse == 0 )
			return i+1;
		return -1;
		
	}
}
