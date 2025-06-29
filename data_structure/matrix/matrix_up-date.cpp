#include<stdio.h>

void main()
{
    int row, column;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &column);

    int matrix[row][column];

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

    int updateRow, updateColumn, updateValue;
    printf("\nEnter the row number to update: ");
    scanf("%d", &updateRow);
    printf("Enter the column number to update: ");
    scanf("%d", &updateColumn);
    printf("Enter the new value: ");
    scanf("%d", &updateValue);

    if (updateRow >= 0 && updateRow < row && updateColumn >= 0 && updateColumn < column) {
        matrix[updateRow][updateColumn] = updateValue;
        printf("\nMatrix updated successfully!\n");
    } else {
        printf("\nInvalid row or column number. Update failed!\n");
    }
    
}