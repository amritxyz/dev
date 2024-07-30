#include"stdio.h"
void fibonacci();
void main(){
	fibonacci();
}
void fibonacci(){
	int a=1, b=1, n, i, fibonacci;
	printf("Enter the number of terms: ");
	scanf("%d", &n);
	for (i=1; i<=n; i++){
		fibonacci=a+b;
		printf("%d\t", a);
		a=b;
		b=fibonacci;
	}
	printf("\n");
}

