#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int size;
} Heap;

// Create a new heap with given capacity
Heap* createHeap(int capacity) {
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->arr = (int*)malloc(sizeof(int) * capacity);
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up for insert
void heapifyUp(Heap *heap, int index) {
    if (index && heap->arr[(index - 1) / 2] < heap->arr[index]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        heapifyUp(heap, (index - 1) / 2);
    }
}

// Insert a value into the heap (max-heap)
void insertHeap(Heap *heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap is full\n");
        return;
    }
    heap->arr[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Heapify down for extract
void heapifyDown(Heap *heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;
    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;

    if (largest != index) {
        swap(&heap->arr[index], &heap->arr[largest]);
        heapifyDown(heap, largest);
    }
}

// Extract the maximum value from the heap
int extractMax(Heap *heap) {
    if (heap->size <= 0)
        return -1;
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

// Free the heap
void freeHeap(Heap *heap) {
    free(heap->arr);
    free(heap);
}

// Print the heap
void printHeap(Heap *heap) {
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);
    printf("\n");
}

// Example usage
int main() {
    Heap *heap = createHeap(10);
    insertHeap(heap, 20);
    insertHeap(heap, 15);
    insertHeap(heap, 30);
    insertHeap(heap, 40);

    printf("Heap: ");
    printHeap(heap);

    printf("Extracted max: %d\n", extractMax(heap));
    printf("Heap after extraction: ");
    printHeap(heap);

    freeHeap(heap);
    return 0;
}