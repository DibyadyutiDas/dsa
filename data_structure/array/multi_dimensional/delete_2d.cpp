#include <stdio.h>

int main()
{
    // declaring and initializing 2D array
    int arr[2][3] = { {10, 20, 30}, {40, 50, 60} };

    printf("2D Array:\n");
    // printing 2D array
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // option for user to delete elements
    int row, col;
    printf("Enter the row and column index of the element to delete: ");
    scanf("%d %d", &row, &col);

    // check if the entered indices are valid
    if (row >= 0 && row < 2 && col >= 0 && col < 3) 
    {
        // delete the element by setting it to 0
        arr[row-1][col-1] = 0;

        printf("Element at row %d and column %d deleted successfully.\n", row, col);

        // printing the updated 2D array
        printf("Updated 2D Array:\n");
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    } 
    else 
    {
        printf("Invalid indices entered.\n");
    }

    return 0;
}