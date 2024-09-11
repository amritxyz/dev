#include <stdio.h>

#define MAX 100 // Maximum size of the matrix

int main() {
    int matrix[MAX][MAX], transposed[MAX][MAX];
    int row, col;

    // Input the number of rows and columns
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &row, &col);

    // Input the matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Compute the transpose of the matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    // Display the transposed matrix
    printf("The transposed matrix is:\n");
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d\t", transposed[i][j]);
        }
        printf("\n");
    }

    return 0;
}

