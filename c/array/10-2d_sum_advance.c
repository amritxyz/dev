// WAP a 2 matrices and disply their sum
#include<stdio.h>
int main(){

	/* First matrix */

	int i, j, first[3][3];
	printf("Enter the elements of first matrix\n");
	for (i=0; i<3; i++){
		for (j=0; j<3; j++)
			scanf("%d", &first[i][j]);
	}


	/* Second matrix */

	int second[3][3];
	printf("Enter the elements of second matrix\n");

	for (i=0; i<3; i++){
		for (j=0; j<3; j++)
			scanf("%d", &second[i][j]);
	}

	/* Display two Matrices */
	printf("\nThe first matrix is:\n");
	for (i=0; i<3; i++){
		for (j=0; j<3; j++)
			printf("%d\t", first[i][j]);
		printf("\n");
	}

	printf("\nThe second matrix is:\n");

	for (i=0; i<3; i++){
		for (j=0; j<3; j++)
			printf("%d\t", second[i][j]);
		printf("\n");
	}

	/* Sum of the matrix */
	int sum[3][3];

	for (i=0; i<3; i++)
		for (j=0; j<3; j++)
			sum[i][j]=first[i][j]+second[i][j];

//	printf("\nThe sum of two matrix is: \n");
//
//	/* First Matrix */
//	for (i=0; i<3; i++){
//		for (j=0; j<3; j++)
//			printf("%d\t", first[i][j]);
//		printf("\n");
//	}
//
//	printf("  +  ");
//
//	/* Second matrix */
//	for (i=0; i<3; i++){
//		for (j=0; j<3; j++)
//			printf("%d\t", second[i][j]);
//		printf("\n");
//	}

	printf("\nAdding two matrices:\n");
	/* Sum */
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			printf("%d + ", first[i][j]);
			printf("%d = ", second[i][j]);
			printf("%d\t", sum[i][j]);
		}
		printf("\n");
	}

	printf("\nThe sum of two matrices:\n");
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			printf("%d\t", sum[i][j]);
		}
		printf("\n");
	}

	return 0;
}

