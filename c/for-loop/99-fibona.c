#include"stdio.h"
int main(){
	int a=1, b=1, c, n;
	printf("Enter a number of terms: ");
	fflush(stdout);
	scanf("%d", &n);
	printf("Fibonacci series: ");
	for (int i=1; i<=n; i++){
		printf("%d\t", a);
		c=a+b;
		a=b;
		b=c;
	}
	printf("\n");
	return 0;
}

