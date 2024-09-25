#include <stdio.h>

#define MAX 100

void readMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &matrix[i][j]);
}

void displayMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < col1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int row1, col1, row2, col2;

    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }

    printf("Enter elements of the first matrix:\n");
    readMatrix(A, row1, col1);
    printf("Enter elements of the second matrix:\n");
    readMatrix(B, row2, col2);

    multiplyMatrices(A, B, C, row1, col1, col2);

    printf("Resultant matrix after multiplication:\n");
    displayMatrix(C, row1, col2);

    return 0;
}


