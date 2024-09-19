#include<stdio.h>
int main(void){
	int a = 9;
	int *pA = &a;
	printf("a: %d\n", a);
	printf("&a: %d\n", &a);
	printf("pA: %d\n", pA);
	printf("&pA: %d\n", &pA);
	printf("*pA: %d\n", *pA);
}

