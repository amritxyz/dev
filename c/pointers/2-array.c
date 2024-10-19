#include<stdio.h>

int main(void)
{
	int *ptr, a[10], i, n;

	printf("Enter a number: ");
	fflush(stdout);
	scanf("%d", &n);
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
	ptr = &a[0];
	printf("You entered: ", *(ptr+i));
	for (i=0; i<n; i++)
		printf("%d ", *(ptr+i));
	printf("\n");
}

