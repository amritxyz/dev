#include <stdio.h>
int main(){
	int a, b=1, c=1;
	a = sizeof(c = ++b + 5);
	printf("a=%d\tb=%d\tc=%d\n", a, b, c);
	return 0;
}

