#include"stdio.h"
int natural(int);
int natural(int a){
	if (a==1){
		return 1;
	}
	else {
		return natural(a-1)+a;
	}
}
int main(){
	int a;
	printf("Sum of natural numbers up to: ");
	scanf("%d", &a);
	printf("The sum of natural numbers up to %d = %d\n", a, natural(a));
	return a;
}

