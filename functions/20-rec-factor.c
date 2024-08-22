#include"stdio.h"

int factor(int a);

int main(){
	int a, n = 1, i;

	printf("Enter a number to get factor of that number: ");
	scanf("%d", &a);

	if (a <= 0) {
		printf("Please enter a positive integer.\n");
    	} else {
		printf("Factor of %d are: %d", a, factor(a));

	}

	return 0;
}

int factor(int a){
	for (int i=1; i<=a; i++)
		return i;
	}

