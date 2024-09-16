#include"stdio.h"
int sum();
int main(){
	sum();
	return 0;
}
int sum(){
	int a, b, sum;
	printf("Enter any Two numbers:\n");
	scanf("%d%d", &a, &b);
	sum=a+b;
	printf("The sum of %d and %d is %d\n", a, b, sum);
	return 0;
}

