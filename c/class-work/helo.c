#include<stdio.h>
int main(){
	int a, b;
	printf("Enter any two numbers: ");
	scanf("%d%d", &a, &b);
	sum(a, b);
	return 0;
}
int sum(int a, int b){
	int c = a + b;
	printf("%d");
}

