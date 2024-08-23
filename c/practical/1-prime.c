#include"stdio.h"
int main(){
	int i, n, j=0;
	printf("Enter a number: ");
	scanf("%d", &n);
	for (i=2; i<=n/2; i++){
		if (n%i==0){
			j=1;
			break;
		}
	}
	if (j==0){
		printf("%d is a prime number\n", n);
	} else {
		printf("%d is not a prime number\n", n);
	}
	return 0;
}

