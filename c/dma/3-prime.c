#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
	int i;
	for (i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int num, count = 0;
	printf("Enter a number: ");
	scanf("%d", &num);
	int *primes = (int *)malloc(num * sizeof(int));
	if (num == 0) {
		fprintf(stderr, "The number should be greater than 0.\n");
		return 1;
	}
	for (int i = 2; i <= num; i++) {
		if (isPrime(i)) {
			primes[count] = i;
			count++;
		}
	}
	printf("Prime numbers: ");
	for (int i = 0; i < count; i++) {
		printf("%d ", primes[i]);
	}
	printf("\n");
	free(primes);
	return 0;
}

