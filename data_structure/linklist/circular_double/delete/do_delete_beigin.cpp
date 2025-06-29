#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to delete the node at the beginning of the double circular linked list
void deleteAtBeginning(struct Node** head)
{
    // If the list is empty, print a message
    if (*head == NULL)
    {
        printf("Double circular linked list is empty.\n");
        return;
    }

    // If there is only one node in the list, delete it and set head to NULL
    if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    // Find the last node in the double circular linked list
    struct Node* last = (*head)->prev;

    // Delete the node at the beginning
    struct Node* temp = *head;
    *head = (*head)->next;
    (*head)->prev = last;
    last->next = *head;
    free(temp);
}

// Function to display the double circular linked list
void display(struct Node* head)
{
    // If the list is empty, print a message
    if (head == NULL)
    {
        printf("Double circular linked list is empty.\n");
        return;
    }

    // Print the double circular linked list
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
    int choice, data;

    // Insert 5 nodes at the beginning of the double circular linked list
    for (int i = 5; i >= 1; i--)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        }
        else
        {
            struct Node* last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            last->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    display(head);

    do
    {
        printf("\n1. Delete at the beginning\n");
        printf("2. Display the double circular linked list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
            case 1:
                deleteAtBeginning(&head);
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