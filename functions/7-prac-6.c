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
	printf("Enter a number which you want to multiply and devide\n");
	scanf("%d%d", &x, &y);
	int i=mul(x, y);
	int j=div(x, y);
	printf("Multiplicantion = %d\n", i);
	printf("division = %d\n", j);
	return 0;
}
int div(int a, int b){
	int c=b/a;
	return c;
}

