#include"stdio.h"
int main() {
	int a, first, last, b;
	printf("Enter a number :");
	scanf("%d", &a);
	last = a % 10;
	b = a;
	while (b > 10) {
		b = b / 10;
	}
	first = b;
	int sum = first + last;
	printf("The sum of first and last number is %d \n", sum);
	return 0;
}

