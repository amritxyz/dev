#include"stdio.h"
int mul(int a, int b){
	int c=a*b;
	return c;
}
int div(int a, int b){
	int c=a/b;
	return c;
}
int main(){
	int x, y;
	printf("Enter ant two numbers\n");
	scanf("%d%d", &x, &y);
	int z=mul(x, y);
	int k=div(x, y);
	printf("Multiplication if given number is %d\n", z);
	printf("Division of given number is %d\n", k);
	return 0;
}

