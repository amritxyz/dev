#include"stdio.h"
int factorial(int);
int factorial(int a){
	if (a==0 || a==1){
		return 1;
	}
	else {
		return (a-1)*a;
	}
}
int main(){
	int a=4;
	printf("The factorial of %d is %d\n", a, factorial(a));
	return 0;
}

