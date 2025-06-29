#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a new node at any position in the circular doubly linked list
void insertAtPosition(struct Node** head, int data, int position)
{
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    // If the list is empty, make the new node as the head and point to itself
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    {
        // Find the node at the given position
        struct Node* current = *head;
        int count = 1;
        while (count < position && current->next != *head)
        {
            current = current->next;
            count++;
        }

        // Insert the new node at the given position
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

// Function to display the circular doubly linked list
void display(struct Node* head)
{
    // If the list is empty, print a message
    if (head == NULL)
    {
        printf("Circular doubly linked list is empty.\n");
        return;
    }

    // Print the circular doubly linked list
    struct Node* current = head;
    printf("Data are - ");
    
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main()
{
    struct Node* head = NULL;
    int choice, data, position;

    // Store a default linked list with 5 nodes
    for (int i = 1; i <= 5; i++)
    {
        insertAtPosition(&head, i, i);
    }

    display(head);

    do
    {
        printf("\n1. Insert at any position\n");
        printf("2. Display the circular doubly linked list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}