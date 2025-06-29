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

    printf("Reversed 2D Array:\n");
    // printing reversed 2d array

    for (int i = 1; i >= 0; i--) 
    {
        for (int j = 2; j >= 0; j--) 
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}