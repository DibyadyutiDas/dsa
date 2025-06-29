#include <stdio.h>

#define SIZE 5

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5};

    // Accessing array elements
    for (int i = 0; i < SIZE; i++) {
        printf("Element at index %d: %d\n", i, arr[i]);
    }

    return 0;
}