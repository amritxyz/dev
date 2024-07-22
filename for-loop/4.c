#include<stdio.h>
int main(){
	int a=6, b, i, j;
	for (i=5; i<=10; i++){
		a-=1;
		for (j=1; j<=a; j++){
			printf("%d", j);
		}
		printf("\n");
	}
	return 0;
}

