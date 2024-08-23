#include"stdio.h"
int updated(int *a, int *b){
	*a=*a+10;
	*b=*b+20;
}
int main(){
	int a, b;
	int originalA, originalB;
	printf("Enter any Two Numbers\n");
	scanf("%d%d", &a, &b);
	originalA=a;
	originalB=b;
	updated(&a, &b);
	printf("Original Value a = %d, b = %d\n", originalA, originalB);
	printf("Updated Value a = %d, b = %d\n", a, b);
	return 0;
}

