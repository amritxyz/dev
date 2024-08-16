#include"stdio.h"
void fibonacci(int a, int b);
void main(){
	int n, i, a, b;
	printf("Enter the number of terms: ");
	scanf("%d", &n);
	fibonacci(a, b);
}
void fibonacci(int a, int b){
	int n, fibonacci;
	for (int i=1; i<=n; i++){
		fibonacci=a+b;
		printf("%d\t", a);
		a=b;
		b=fibonacci;
	}
	printf("\n");
}

