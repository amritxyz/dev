#include"stdio.h"
int sum(int,int); //declaration
int main(){
	int a, b;
	printf("Enter 2 numbers");
	scanf("%d%d", &a, &b);
	sum(a,b);
	return 0;
}
int sum(int,int){
	int c;
	c=a+b;
	printf("The sum is %d", c);
}

