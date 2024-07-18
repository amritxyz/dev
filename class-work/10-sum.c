//WAP inter a number display the table of the number

#include"stdio.h"
int main(){
	int n, i=1, sum;
	printf("Enter a number :");
	scanf("%d", &a);
	while (n>0){
		n=n/10;

		printf("%d * %d = %d\n", a, i, a*i);
		i++;
	}
	return 0;
}

