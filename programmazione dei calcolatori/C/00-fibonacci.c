#include <stdio.h>


int menouno(int F){
	int r;
	r = F-1;
	return r;
}

void main(){
	int n;
	int i = 2;
	int Fp = 1;
	int Fpp = 0;
	int F;

	scanf("%d", &n);
	
	n = menouno(n);

	if ( n >= 2 ){
			while ( i <= n ){
				F = Fp + Fpp;
				Fpp = Fp;
				Fp = F;
				i = i+1;
			}
		}
	else {
		F = n;
	}
    
	printf("%d\n", F);

}
