#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols, i, j;

    // Get the dimensions of the matrices
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for the matrices
    // int **matrix1 = (int **)malloc(rows * sizeof(int *));
    // int **matrix2 = (int **)malloc(rows * sizeof(int *));
    // int **result = (int **)malloc(rows * sizeof(int *));
    // for (i = 0; i < rows; i++)
    // {
    //     matrix1[i] = (int *)malloc(cols * sizeof(int));
    //     matrix2[i] = (int *)malloc(cols * sizeof(int));
    //     result[i] = (int *)malloc(cols * sizeof(int));
    // }

    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];
    
    // Input the elements of the matrices
    printf("Enter the elements of matrix 1:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of matrix 2:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Perform matrix addition
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print the result
    printf("The sum of the matrices is:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    // for (i = 0; i < rows; i++)
    // {
    //     free(matrix1[i]);
    //     free(matrix2[i]);
    //     free(result[i]);
    // }
    // free(matrix1);
    // free(matrix2);
    // free(result);

    return 0;
}