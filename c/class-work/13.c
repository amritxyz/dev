#include"stdio.h"
int main(){
	int a, f, l, n;
	printf("Enter a number");
	scanf("%d", &n);
	l = n%10;
	a = n;
	while (a>=10){
		a = a/10;
	}
	f = a;
	int sum = f + l;
	printf("The sum of first and last number is %d", sum);
	return 0;
}

