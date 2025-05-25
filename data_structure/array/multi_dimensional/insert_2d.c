#include <stdio.h>

int main()
{
    // declaring and initializing 2d array
    int arr[2][3];

    printf("Enter the elements of the 2D array:\n");

    // taking input from the user
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf("Enter element at index [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("2D Array:\n");
    // printing 2d array
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