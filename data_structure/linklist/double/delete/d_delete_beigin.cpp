#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to delete the node at the beginning of the double linked list
void deleteAtBeginning(struct Node** head)
{
    // If the list is empty, print a message
    if (*head == NULL)
    {
        printf("Double linked list is empty.\n");
        return;
    }

    // If there is only one node in the list, delete it and set head to NULL
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    // Delete the node at the beginning
    struct Node* temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}

// Function to display the double linked list
void display(struct Node* head)
{
    // If the list is empty, print a message
    if (head == NULL)
    {
        printf("Double linked list is empty.\n");
        return;
    }

    // Print the double linked list
    struct Node* current = head;    
    printf("Data are - ");

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = NULL;
    int choice, data;

    // Insert 5 nodes at the beginning of the double linked list
    for (int i = 5; i >= 1; i--)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
    }
    
    display(head);

    do
    {
        printf("\n1. Delete at the beginning\n");
        printf("2. Display the double linked list\n");
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