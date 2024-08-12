#include"stdio.h"
int sum(int, int);
int sum(int a, int b){
	printf("The sum = %d\n", a+b);
	return a+b;
}
int main(){
	int a=1, b=3;
	sum(a,b);

	int d=10, c=11;
	sum(d,c);
}

