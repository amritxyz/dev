#include<stdio.h>
int main(){
	int a, b, i, j;
	for (i=1; i<=5; i++){
		for (j=1; j<=i; j++){
			printf("%d", j);
		}
		//a=j;
		printf("\n");
		//printf("%d", a);
	}
	return 0;
}

