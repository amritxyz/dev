//wap to input the number find the sum of even number
#include"stdio.h"
int main(){
	int n, a, even=0, odd=0;
	printf("Enter a number :");
	scanf("%d", &n);
	while(n>0){
		a=n%10;
		if(a%2==0){
			even+=a;
		}else{
			odd+=a;
		}
		n=n/10;
		}
		printf("The sum of even is %d\n", even);
		printf("The sum of odd is %d\n", odd);
	return 0;
}

