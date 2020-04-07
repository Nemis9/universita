#include <stdio.h>
#include <stdlib.h>

void GeneraInsiemeDelleParti(char*, int);
void GSB(char*, char*, int);
void MostraSottoinsieme(char*, char*);


void main(){
	/*
	 * la stringa t contiene codifica un insieme di caratteri
	 * di cui vogliamo trovare tutte le sue parti.
	 * */
	char t[] = "abc";
	int n = sizeof(t)/sizeof(char)-1;
	GeneraInsiemeDelleParti( t, n );
}

void GeneraInsiemeDelleParti(char *t, int n){
	char *b = malloc((n+1)*sizeof(char));
	int i;
	for(i=0; i < n; i++){
		b[i] = ' ';
	}
	b[n] = '\0';
	
	GSB(t, b, 0);
}

/*
 * Genera in b tutte le sequenze binarie apartire
 * dalla posizione k
 * 
 * */
void GSB(char *t, char *b, int k){
	if( b[k] == '\0'){
			MostraSottoinsieme(t, b);
	} else {
		b[k] = '0'; GSB(t, b, k+1);
		b[k] = '1'; GSB(t, b, k+1);
	}
}

/*
 * Stampa il sottoinsieme dell'insieme codificato da t che corrispondente
 * alla sequenza binaria b.
 * */
void MostraSottoinsieme(char *t, char *b){
	int i = 0;
	while( b[i] != '\0'){
		if( b[i] == '1')
			printf("%c", t[i]);
		i++;
	}
	printf("\n");
}
