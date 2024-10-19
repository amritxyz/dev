/* Function Pointer as Function Argument */
#include<stdio.h>

int
compute(int(*operation)(int, int), int x, int y)
{
	printf("Result: %d\n", operation(x, y));
}

int
multiply(int a, int b)
{
	return a*b;
}

int main(int a, int b)
{
	printf("Enter any two numbers:\n");
	scanf("%d%d", &a, &b);

	compute(multiply, a, b);

	return 0;
}

