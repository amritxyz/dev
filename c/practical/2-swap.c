#include"stdio.h"
int main(){
	int num1, num2, a;
	printf("Enter two numbers");
	scanf("%d%d", &num1, &num2);
	printf("num1=%d\n", num1);
	printf("num2=%d\n", num2);
	a=num1;
	num1=num2;
	num2=a;
	printf("swapped value of num1 and num2 is %d and %d respectively\n", num1, num2);
	return 0;
}

