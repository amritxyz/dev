// WAP a matrix and count how many odd or even it have and sum the right or left diagonal
#include<stdio.h>
int main(){
	int ar[5][5];
	int i, j, even=0, odd=0;
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			scanf("%d", &ar[i][j]);
		}
	}

	printf("\n\n");
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			printf("%d\t", ar[i][j]);
			if(ar[i][j] % 2 == 0)
				even += 1;
			else
				odd += 1;
		}
		printf("\n\n");
	}
	printf("Even numbers = %d\n", even);
	printf("odd numbers = %d\n", odd);
	return 0;
}

