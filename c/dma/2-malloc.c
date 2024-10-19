#include <stdio.h>
#include <stdlib.h>

int main() {
	int num, i, count = 0;
	printf("Enter a number: ");
	scanf("%d", &num);
	int *factors = (int *)malloc(num * sizeof(int));
	for (i = 1; i <= num; i++) {
		if (num % i == 0) {
			factors[count] = i;
			count++;
		}
	}
	printf("Factors: ");
	for (i = 0; i < count; i++) {
		printf("%d ", factors[i]);
	}
	printf("\n");
	free(factors);
	return 0;
}

