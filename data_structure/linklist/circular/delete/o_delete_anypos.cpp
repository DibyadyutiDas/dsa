#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to delete the node at a given position in the circular linked list
void deleteAtPosition(struct Node** head, int position)
{
    // If the list is empty, print a message
    if (*head == NULL)
    {
        printf("Circular linked list is empty.\n");
        return;
    }

    // If the position is 1, delete the node at the beginning
    if (position == 1)
    {
        struct Node* last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        struct Node* temp = *head;
        *head = (*head)->next;
        last->next = *head;
        free(temp);
        return;
    }

    // Find the node at the given position
    struct Node* current = *head;
    struct Node* prev = NULL;
    int count = 1;
    while (count < position && current->next != *head)
    {
        prev = current;
        current = current->next;
        count++;
    }

    // If the position is greater than the number of nodes, print a message
    if (count < position)
    {
        printf("Invalid position.\n");
        return;
    }

    // Delete the node at the given position
    prev->next = current->next;
    free(current);
}

// Function to display the circular linked list
void display(struct Node* head)
{
    // If the list is empty, print a message
    if (head == NULL)
    {
        printf("Circular linked list is empty.\n");
        return;
    }

    // Print the circular linked list
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
    int choice, position;

    // Insert 5 nodes at the beginning of the circular linked list
    for (int i = 5; i >= 1; i--)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            struct Node* last = head;
            while (last->next != head)
            {
                last = last->next;
            }
            newNode->next = head;
            last->next = newNode;
            head = newNode;
        }
    }
    
    display(head);

    do
    {
        printf("\n1. Delete at a given position\n");
        printf("2. Display the circular linked list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
            case 1:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
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