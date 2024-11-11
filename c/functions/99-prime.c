#include <stdio.h>

int
prime(int num)
{
	if (num <= 1) return 0;
	for (int i = 2; i <= num/2; i++) {
		if (num % i == 0) return 0;
	}
	return 1;
}

int
main()
{
	printf("Prime numbers between 1 and 100 are:\n");

	for (int num = 1; num <=100; num++) {
		if (prime(num)) {
			printf("%d ", num);
		}
	}
	printf("\n");
	return 0;
}

