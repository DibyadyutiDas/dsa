#include <stdio.h>

// Function to insert element at a specific position
void insertElement(int arr[], int *n, int x, int pos)
{
    // shift elements to the right
    for (int i = *n - 1; i >= pos; i--)
        arr[i + 1] = arr[i];

    arr[pos] = x;
    (*n)++;
}

// Function to insert element at the beginning of the array
void insertAtBeginning(int arr[], int *n, int x)
{
    insertElement(arr, n, x, 0);
}

// Function to insert element at the end of the array
void insertAtEnd(int arr[], int *n, int x)
{
    insertElement(arr, n, x, *n);
}

int main()
{
    int arr[15] = { 2, 4, 1, 8, 5 };
    int n = 5;

    printf("Elements of array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\n");

    int x, pos;
    printf("Enter the element to insert: ");
    scanf("%d", &x);
    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    if (pos == 0)
        insertAtBeginning(arr, &n, x);
    else if (pos == n)
        insertAtEnd(arr, &n, x);
    else
        insertElement(arr, &n, x, pos);

    printf("\nAfter insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}