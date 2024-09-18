/* Function pointers with parameters and return value */
#include<stdio.h>
int add(int a, int b);
int main(){
	int (*funptr)(int, int);
	funptr=&add;
	int result=(*funptr)(5, 6);
	printf("Result: %d\n", result);
	return 0;
}
int add(int a, int b){
	return a+b;
}

