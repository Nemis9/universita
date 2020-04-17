#include<stdio.h>

union floatint {
	float unfloat;
	int unint;
};
typedef union floatint floatint;

void main(){
	floatint u;
	u.unint = 10;
	printf("%d\n", u.unint);
	u.unfloat = 3.1415;
	printf("%f\n", u.unfloat);
	printf("%d\n", u.unint);
}
