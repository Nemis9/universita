#include <stdio.h>

struct punto{
	int x, y;
};
typedef struct punto punto;

void DisegnaPunti0(punto p[], int);
void DisegnaPunti(punto p[], int);
void BubbleSort(punto p[], int);

void main(){
	punto p[] = {{3,1}, {8,0}, {1,2}, {0,1}, {3,0}};
	int n = sizeof(p)/sizeof(punto);

	DisegnaPunti(p, n);
}

void DisegnaPunti0(punto p[], int n){
	int numrows = 0, numcols = 0;
	int r,c, i, trovato;

	for(i = 0; i < n; i++){
		if( p[i].y > numrows )
			numrows = p[i].y;
		if( p[i].x > numcols )
			numcols = p[i].x;
	}
	/*
	 * numcols e numrows contengono le massime coordinate, il numero 
	 * di righe e colonne si ottiene aggiungendo 1 ovvero la riga e
	 * la colonna 0
	 * */
	numcols++; numrows++;

	for( r = 0; r < numrows; r++){
		for( c = 0; c < numcols; c++){
			/*
			 * Verifica se (c, r) e' in p
			 * */
			i = 0; trovato = 0;
			while( trovato == 0 && i < n ){
				if( p[i].x == c && p[i].y == r )
					trovato = 1;
				i++;
			}
			if( trovato == 1 )
				printf("X");
			else
				printf("_");
		}
		printf("\n");
	}
}

void DisegnaPunti(punto p[], int n){
	int numrows = 0, numcols = 0;
	int r,c, i, trovato;

	for(i = 0; i < n; i++){
		if( p[i].y > numrows )
			numrows = p[i].y;
		if( p[i].x > numcols )
			numcols = p[i].x;
	}
	
	/*
	 * numcols e numrows contengono le massime coordinate, il numero
	 * di righe e colonne si ottiene aggiungendo 1 ovvero la riga e
	 * la colonna 0
	 * */
	numcols++; numrows++;
	BubbleSort(p, n);
	i = 0; /* posizione in p del prossimo punto da rappresentare*/
	for( r = 0; r < numrows; r++){
		for( c = 0; c < numcols; c++){
			if( i < n && p[i].x == c && p[i].y == r ){
					printf("X");
					i++;
			} else {
				printf("_");
			}
		}
		printf("\n");
	}
}



void BubbleSort(punto p[], int n){
	int i,j; 
	punto c;
	int ordinato = 0;

	i = 0;
	while ( ordinato == 0 ){
		ordinato = 1;
		for(j = 0; j < n-1-i; j = j+1){
			if( (p[j].y > p[j+1].y) || (p[j].y == p[j+1].y && p[j].x > p[j+1].x) ){ 
				c = p[j];
				p[j] = p[j+1];
				p[j+1] = c;
				ordinato = 0;
			}
		}
		i = i+1;
	}
}
