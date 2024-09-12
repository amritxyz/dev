#include<stdio.h>

int negative_int(void);

int main(void){
	int n=negative_int();
	printf("%d\n", n);
}

int negative_int(void){
	int n;
	do {
		printf("Negative Int: ");
		scanf("%d", &n);
	} while (n>0);
}

