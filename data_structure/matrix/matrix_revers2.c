#include<stdio.h>

void main()
{
    int row, column;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &column);

    int matrix[row][column],revers_matrix[row][column];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("Enter the element at position %d,%d : ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nMatrix is: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            revers_matrix[i][column-j-1] = matrix[i][j];
        }
    }

    printf("\nRevers matrix : \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ", revers_matrix[i][j]);
        }
        printf("\n");
    }
}