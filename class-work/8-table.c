//WAP inter a number display the table of the number

#include"stdio.h"
int main(){
	int a, i=1, c;
	printf("Enter a number :");
	scanf("%d", &a);
	while (i<=10){
		printf("%d * %d = %d\n", a, i, a*i);
		i++;
	}
	return 0;
}

