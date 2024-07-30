#include"stdio.h"
void main(){
	int a=1, i=1;
	printf("Enter a number: ");
	scanf("%d", &a);
	do{
		printf("%d", i);
		i++;
	}
	while(i<=a);
	printf("\n");
}

