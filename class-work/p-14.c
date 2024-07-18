#include"stdio.h"
int main(){
	int num, first, last, a;
	printf("Enter a number :");
	scanf("%d", &num);
	last = num % 10;
	a = num;
	while (a>=10){
		a = a/10;
	}
	first = a;
	int sum = first + last;
	printf("The sum of first and last number is %d\n", sum);
	return 0;
}

