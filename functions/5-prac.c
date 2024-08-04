#include"stdio.h"
int sum(int a, int b);
int main(){
	int a, b, Sum;
	printf("Enter 2 numbers which you want to sum: ");
	scanf("%d%d", &a, &b);
	Sum = sum(a, b);
	printf("The sum is %d\n", Sum);
	return 0;
}
int sum(int a, int b){
	return a+b;
}

