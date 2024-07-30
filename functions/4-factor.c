#include"stdio.h"
void factor();
void main(){
	factor();
}
void factor(){
	int a, n=1, i;
	printf("Enter a number to get factor of that number: ");
	scanf("%d", &a);
	for (i=1; i<=a; i++){
		if(a%i==0){
			printf("%d ", i);
		}
	}
	printf("\n");
}

