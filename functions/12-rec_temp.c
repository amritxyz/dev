#include"stdio.h"
float c2f(float);
float c2f(float n){
	return ((9*n)/5)+32;
}
int main(){
	float n=37.6;
	printf("F = %f\n", c2f(n));
	return 0;
}

