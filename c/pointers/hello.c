#include <stdio.h>

int
isPrime(int *num)
{
	if (*num <= 1) return 0;
	for (int i = 2; i * i <= *num; i++) {
		if (*num % i == 0) return 0;
	}
	return 1;
}

int main(void) {
	int num;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%d", &num);

	if (isPrime(&num)) {
		printf("%d is a prime number.\n", num);
	} else {
		printf("%d is not a prime number.\n", num);
	}
}

