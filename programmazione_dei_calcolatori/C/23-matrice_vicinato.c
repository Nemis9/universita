#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int *MatriceVicinato(int*, int, int);


void main(){
	int i,j, n = 3, m= 4, c, r;
	int M[3][4] = {
			{0, 1, 1, 0 },
			{0, 1, 1, 0 },
			{0, 1, 1, 1 }
	};
		
	int *b, *a = malloc(sizeof(int)*n*m);
	
	i = 0;
	
	for( r = 0; r < n; r++)
		for(c = 0; c < m; c++){
			a[i] = M[r][c];
			i++;
		}
		
	b = MatriceVicinato(a, n, m);
	

	for( r = 0; r < n; r++){
		for(c = 0; c < m; c++){
			printf("%d ", b[r*m+c]);
		}
		printf("\n");
	}
	
}

int *MatriceVicinato(int *a, int nr, int nc){
	int *b = malloc(sizeof(int)*nr*nc);
	int i, r, c, x, y, v;
	
	for(i = 0; i < nr*nc; i++)
		b[i] = 0;
		
	for(r = 0; r < nr; r++){
		for(c = 0; c < nc; c++){
			v = 0;
			for(x = r-1; x <= r+1; x++){
				for(y = c-1; y <= c+1; y++){
					if( x >= 0 && x < nr && y >= 0 && y < nc && a[x*nc+y] == 1)
						if( !(x == r && y == c))
							v++;
				}
			}
			b[r*nc+c] = v;
		}
	}
	
	return b;
}

