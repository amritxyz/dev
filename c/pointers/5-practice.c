#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ptr, i, sum = 0, num_elements;
	printf("Enter the number of elements: ");
	fflush(stdout);
	scanf("%d", &num_elements);
	ptr = (int *)malloc(num_elements * sizeof(int));
	if (ptr == NULL) {
		fprintf(stderr, "Memory allocation failed!\n"); return 1;
	}
	printf("Enter %d Integers\n", num_elements);
	for (i = 0; i < num_elements; i++) {
		printf("Element %d: ", i + 1); fflush(stdout);
		scanf("%d",&ptr[i]);
	}
	for (i = 0; i < num_elements; i++)
		sum += ptr[i];
	printf("Sum of elements: %d\n", sum);
	free(ptr);
	return 0;
}
