#include<stdio.h>
int main(){
	int a[3][3], i, j, sum=0;
	printf("Enter the numbers for matrix\n");

	for (i=0; i<3; i++){
		for (j=0; j<3; j++)
			scanf("%d", &a[i][j]);
	}

	printf("The matrix is:\n");
	for (i=0; i<3; i++){
		for (j=0; j<3; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			if (i<j)
				sum+=a[i][j];
		}
	}

	printf("The sum of upper diagonal of above matrix is: %d\n", sum);
	return 0;
}

