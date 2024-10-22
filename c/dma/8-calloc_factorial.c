/* WAP to print fatorial of number n using calloc */

#include <stdio.h>
#include <stdlib.h>

unsigned long long
factorial(int n)
{
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

int main()
{
	int number;
	printf("Enter a positive integer: ");
	scanf("%d", &number);

	// Allocate memory for storing factorial (just for demonstration)
	unsigned long long *result = (unsigned long long *)calloc(1, sizeof(unsigned long long));
	if (result == NULL) {
		printf("Memory allocation failed.\n");
		return 1;
	}

	*result = factorial(number);
	printf("Factorial of %d = %llu\n", number, *result);

	// Free allocated memory
	free(result);
	return 0;
}

