#include <stdio.h>

int main()
{

    // declaring and initializing 2d array
    int arr[2][3] = { 10, 20, 30, 40, 50, 60 };

    printf("Original 2D Array:\n");
    // printing original 2d array

    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    int row, col, value;
    printf("\nEnter the row index: ");
    scanf("%d", &row);
    printf("Enter the column index: ");
    scanf("%d", &col);
    printf("Enter the value: ");
    scanf("%d", &value);

    arr[row-1][col-1] = value;

    printf("\nUpdated 2D Array:\n");
    // printing updated 2d array
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}