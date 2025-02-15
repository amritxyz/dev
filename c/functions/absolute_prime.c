#include <stdio.h>
#include <stdlib.h>

static int isPrime(int);

static int
isPrime(int num)
{
	for (int i = 0; i < num; i++) {
		if (num % 2 == 0) {
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);

	if (num < 2) {
		fprintf(stderr, "The number is not a prime number.\n");
		return EXIT_FAILURE;
	}

	if (!(isPrime(num))) {
		printf("The number is a prime number.\n");
	} else {
		printf("The number is not a prime number.\n");
	}

	return 0;
}
