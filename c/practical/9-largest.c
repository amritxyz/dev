#include"stdio.h"
int main(){
	int num1, num2, num3, largest, smallest, even, odd;
	printf("Enter any three numbers: ");
	scanf("%d%d%d", &num1, &num2, &num3);
	if (num1>num2 && num1>num3){
		largest = num1;
	} else if (num2>num1 && num2>num3){
		largest = num2;
	} else {
		largest = num3;
	}
	if (num1<num2 && num1<num3){
		smallest = num1;
	} else if (num2<num1 && num2<num3){
		smallest = num2;
	} else {
		smallest = num3;
	}
	printf("\nLargest number is %d\n", largest);
	if (largest%2==0){
		printf("The largest number is even\n\n");
	} else {
		printf("The largest number is odd\n\n");
	}
	printf("The smallest number is %d\n", smallest);
	if (smallest%2==0){
		printf("The smallest number is even\n\n");
	} else {
		printf("The smallest number is odd\n\n");
	}
	return 0;
}

