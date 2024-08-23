//count the total number of odd and even

#include"stdio.h"
int main(){
	int i=0, a, b, even=0, odd=0;
	printf("How many number you want to enter :");
	scanf("%d", &a);
	while(a<=i){
		printf("Enter your number :");
		scanf("%d", &i);
		if(b%2==0){
			even++;
		} else{
			odd++;
		}
		i++;
	}
	printf("The even number is %d", even);
	printf("THe odd number is %d", odd);
	return 0;
}

