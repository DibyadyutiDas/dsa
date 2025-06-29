// C Program to demonstrate the use of array
#include <stdio.h>

void displayArray(int arr[], int size);

int main()
{
  // array declaration and initialization
  int arr[5] = { 10, 20, 30, 40, 50 };
  displayArray(arr, 5);
  
  // modifying element at index
  int index, value;
  printf("\nEnter the index of the element to modify: ");
  scanf("%d", &index);
  index--;
  printf("Enter the new value: ");
  scanf("%d", &value);
  arr[index] = value;

  // display array
  printf("\n");
  displayArray(arr, 5);

  return 0;
}

void displayArray(int arr[], int size)
{
  printf("Elements in Array: ");
  for (int i = 0; i < size; i++) 
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}