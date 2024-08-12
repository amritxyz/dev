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
	int a=5;
	printf("the num of natural numbers up to %d = %d\n", a, natural(a));
	return a;
}

