#include"stdio.h"
int main(){
	int i, a, b=1;
	printf("Enter a number :");
	scanf("%d", &a);
	while(i=1, i<=a){
		b=i*b;
		printf("Factorial of %d is %d\n", a, b);
		i++;
	}
	return 0;
}

