#include"stdio.h"
int main(){
	int num1, num2, num3;
	printf("Enter any three numbers: ");
	scanf("%d%d%d", &num1, &num2, &num3);
	if (num1<num2 && num1<num3){
		printf("The smallest number is %d", num1);
	}
	else if (num2<num1 && num2<num3){
		printf("The smallest number is %d", num2);
	}
	else if (num3<num1 && num3<num2){
		printf("The smallest number is %d", num3);
	}
	else if (num1>num2 && num1>num3){
		printf("The largest number is %d", num1);
	}
	else if (num2>num1 && num2>num3){
		printf("The largest number is %d", num2);
	}
	else {
		printf("The largest number is %d", num3);
	}
	return 0;
}

