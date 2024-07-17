//input the number find the factor of the number

#include"stdio.h"
int main(){
	int a, i=1;
	printf("Enter a number");
	scanf("%d", &a);
	while(i<=a,i++)
		if(a%i==0){
		printf("%d\n", i);
		}
	return 0;
}

