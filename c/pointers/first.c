#include<stdio.h>
int main() {
	char *ptr;
	int a = 10;
	ptr = &a;
	printf("%d", a);
	printf("%d", ptr);
	printf("%d", *ptr);
	return 0;
}

