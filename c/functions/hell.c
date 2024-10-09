#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sum(int x, int y);
void sub(int x, int y);
void nothing(char *prog);

void
sum(int x, int y)
{
	printf("%d\n", x+y);
}

void
sub(int x, int y)
{
	printf("%d\n", x-y);
}

void
mul(int x, int y)
{
	printf("%d\n", x*y);
}

void
divi(int x, int y)
{
	if (y == 0)
		fprintf(stderr, "Error: Division by zero\n");
	else
		printf("%d\n", x / y);
}

void
nothing(char *prog)
{
	fprintf(stderr, "Usage: %s <operation> <first_number> <second_number>\n", prog);
}

int
main(int argc, char **argv)
{
	int a, b;

	if (argc == 1)
		nothing(argv[0]);
	else if (argc < 4)
		nothing(argv[0]);
	else {
		a = atoi(argv[2]);
		b = atoi(argv[3]);

		if (strcmp(argv[1], "sum") == 0)
			sum(a, b);
		else if (strcmp(argv[1], "sub") == 0)
			sub(a, b);
		else if (strcmp(argv[1], "mul") == 0)
			mul(a, b);
		else if (strcmp(argv[1], "div") == 0)
			divi(a, b);
		else
			nothing(argv[0]);
	}
	return 0;
}

