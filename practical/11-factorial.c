#include"stdio.h"
int main(){
	int n, i, fac=1;
	printf("Enter a number: ");
	scanf("%d", &n);
	if (n<0){
		printf("Invalid operation");
	} else {
		for (i=1; i<=n; i++){
			fac*=i;
		}
		printf("Factorial of number %d is %d.\n", n, fac);
	}
	return 0;
}

