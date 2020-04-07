#include <stdio.h>

struct punto {
	char nome;
	float x, y;
};
typedef struct punto punto;

void OrdinaPunti( punto*, int );

void main(){
	punto P[] = { {'A', 2, 4}, {'B', 2, 2}, {'C', 3,3},
		{'D', 5,4}, {'E', 3,1}, {'F', 4,1}};

	int n = sizeof(P)/sizeof(punto);
	int m = 10;
	int r,c,k = 0;
	
	OrdinaPunti(P, n);
	
	for(r = 0; r < n; r++){
		printf("%c: (%.1f,%.1f)\n", P[r].nome, P[r].x, P[r].y);
	}

	/*
	 * Rappresenta i punti di P sul terminale, l'origine del piano
	 * e' in alto a sinistra
	 *
	 * */
	
	for(r = 0; r < m; r++){
		for(c = 0; c < m; c++){
			if(P[k].y == r && P[k].x == c){
				printf("%c", P[k].nome);
				k++;
			} else {
				printf("*");
			}
		}
		printf("\n");
	}
}

/*
 * Restituisce -1 se p precede q
 * 0 se p == q
 * +1 se q precede p
 * 
 * p precede q se p.y < q.y
 * nel caso p.y == q.y allora
 * p precede q se p.x < q.x
 * se p.x == q.x
 * p precede q se p.nome < q.nome
 * 
 * */

int PntCmp(punto p, punto q){
	if (p.y < q.y)
		return -1;
	if (q.y < p.y)
		return 1;
	if (p.x < q.x)
		return -1;
	if (q.x < p.x)
		return 1;
	if (p.nome < q.nome)
		return -1;
	if (q.nome < p.nome)
		return 1;
	return 0;

}

void OrdinaPunti( punto* P, int n ){
	int k = 0, i;
	punto t;
	int ordinato  = 0; /* = 0 se array non e' ordinato, 1 altrimenti*/
	
	while( ordinato == 0){
		ordinato = 1;
		for( i = 0; i < n-1-k; i++){
			if( PntCmp(P[i], P[i+1]) == 1 ){
				t = P[i];
				P[i] = P[i+1];
				P[i+1] = t;
				ordinato = 0;
			}
		}
		k++;
	}
}

