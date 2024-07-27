#include"stdio.h"
int main(){
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	if (n>0){
		printf("The number %d is positive\n", n);
	} else if (n<0){
		printf("The number %d is negative\n", n);
	} else {
		printf("The number %d is zero\n", n);
	}
	return 0;
}

