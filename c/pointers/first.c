#include<stdio.h>

int main(void)
{
	char *ptr;
	int a = 10;
	ptr = &a;
	printf("%d", a);
	printf("%d", ptr);
	printf("%d", *ptr);
}

