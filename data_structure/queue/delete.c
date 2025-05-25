#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to create an empty queue
Queue* createQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue)
{
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(Queue* queue)
{
    return queue->rear == MAX_SIZE - 1;
}

// Function to add an element to the queue
void enqueue(Queue* queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = item;
    printf("Element enqueued successfully.\n");
}

// Function to delete an element from the queue by position
void deleteByPosition(Queue* queue, int position)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot delete element.\n");
        return;
    }
    if (position < 0 || position > queue->rear)
    {
        printf("Invalid position. Cannot delete element.\n");
        return;
    }
    int deletedItem = queue->items[position];
    for (int i = position; i < queue->rear; i++)
    {
        queue->items[i] = queue->items[i + 1];
    }
    queue->rear--;
    printf("Deleted item: %d\n", deletedItem);
}

int main()
{
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    deleteByPosition(queue, 1);
    deleteByPosition(queue, 0);
    deleteByPosition(queue, 0);

    return 0;
}