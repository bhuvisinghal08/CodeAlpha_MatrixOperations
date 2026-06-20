#include <stdio.h>
#define MAX 10
void readMatrix(int a[MAX][MAX], int rows, int cols);
void printMatrix(int a[MAX][MAX], int rows, int cols);
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols);
void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int r1, int c1, int r2, int c2);
void transposeMatrix(int a[MAX][MAX], int rows, int cols);
int main()
{
    int choice;
    int a[MAX][MAX], b[MAX][MAX];
    int r1, c1, r2, c2;
    do
    {
        printf("\n========== MATRIX OPERATIONS ==========\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Transpose of Matrix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter number of rows and columns: ");
            scanf("%d %d", &r1, &c1);
            printf("\nEnter first matrix:\n");
            readMatrix(a, r1, c1);
            printf("\nEnter second matrix:\n");
            readMatrix(b, r1, c1);
            printf("\nFirst Matrix:\n");
            printMatrix(a, r1, c1);
            printf("\nSecond Matrix:\n");
            printMatrix(b, r1, c1);
            addMatrix(a, b, r1, c1);
            break;
        case 2:
            printf("\nEnter rows and columns of first matrix: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter rows and columns of second matrix: ");
            scanf("%d %d", &r2, &c2);
            if (c1 != r2)
            {
                printf("\nMultiplication is not possible.\n");
                printf("Columns of first matrix must be equal to rows of second matrix.\n");
            }
            else
            {
                printf("\nEnter first matrix:\n");
                readMatrix(a, r1, c1);
                printf("\nEnter second matrix:\n");
                readMatrix(b, r2, c2);
                printf("\nFirst Matrix:\n");
                printMatrix(a, r1, c1);
                printf("\nSecond Matrix:\n");
                printMatrix(b, r2, c2);
                multiplyMatrix(a, b, r1, c1, r2, c2);
            }
            break;
        case 3:
            printf("\nEnter number of rows and columns: ");
            scanf("%d %d", &r1, &c1);
            printf("\nEnter matrix elements:\n");
            readMatrix(a, r1, c1);
            printf("\nOriginal Matrix:\n");
            printMatrix(a, r1, c1);
            transposeMatrix(a, r1, c1);
            break;
        case 4:
            printf("\nProgram ended successfully.\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);
    return 0;
}
void readMatrix(int a[MAX][MAX], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}
void printMatrix(int a[MAX][MAX], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols)
{
    int sum[MAX][MAX];
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("\nResult after Addition:\n");
    printMatrix(sum, rows, cols);
}
void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int r1, int c1, int r2, int c2)
{
    int product[MAX][MAX];
    int i, j, k;

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            product[i][j] = 0;

            for (k = 0; k < c1; k++)
            {
                product[i][j] = product[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    printf("\nResult after Multiplication:\n");
    printMatrix(product, r1, c2);
}
void transposeMatrix(int a[MAX][MAX], int rows, int cols)
{
    int trans[MAX][MAX];
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            trans[j][i] = a[i][j];
        }
    }
    printf("\nTranspose of Matrix:\n");
    printMatrix(trans, cols, rows);
}