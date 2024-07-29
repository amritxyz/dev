#include"stdio.h"
int main(){
	int num, first, last, sum;
	printf("Enter any four numbers:\n");
	scanf("%d", &num);
	if(num<1000 || num>9999){
		printf("Invalid operation: Please input 4 digit numbers.\n");
	}
	first=num/1000;
	last=num%4;
	sum=first+last;
	printf("Sum of first and last digit is %d", sum);
	return 0;
}

