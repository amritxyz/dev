#include"stdio.h"
int sum();
int main(){
	sum();
	sum();
	sum();
}
int sum(){
	int a, b, sum;
	printf("Enter a number: ");
	scanf("%d%d", &a, &b);
	sum=a+b;
	printf("The sum of %d and %d is %d\n", a, b, sum);
	return 0;
}

