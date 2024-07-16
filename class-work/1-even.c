//WAP print even number 1 to 15

#include"stdio.h"
int main() {
	int i=1;
	do {
		if (i%2==0)
		printf("%d\n", i);
		i++;
	} while (i<15);
	return 0;
}

