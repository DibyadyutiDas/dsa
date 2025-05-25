#include <stdio.h>

// Function to delete element at a specific position
void deleteElement(int arr[], int *n, int pos)
{
    // shift elements to the left
    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    (*n)--;
}

// Function to delete element at the beginning of the array
void deleteAtBeginning(int arr[], int *n)
{
    deleteElement(arr, n, 0);
}

// Function to delete element at the end of the array
void deleteAtEnd(int arr[], int *n)
{
    deleteElement(arr, n, *n - 1);
}

int main()
{
    int arr[15] = { 2, 4, 1, 8, 5 };
    int n = 5;

    printf("Elements of array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\n");

    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    pos--;
    
    if (pos == 0)
        deleteAtBeginning(arr, &n);
    else if (pos == n-1)
        deleteAtEnd(arr, &n);
    else
        deleteElement(arr, &n, pos);

    printf("\nAfter deletion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
