#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a new node at the beginning of the double linked list
void insertAtBeginning(struct Node** head, int data)
{
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    // If the list is empty, make the new node as the head
    if (*head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        *head = newNode;
    }
    else
    {
        // Insert the new node at the beginning
        newNode->next = *head;
        newNode->prev = NULL;
        (*head)->prev = newNode;
        *head = newNode;
    }
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

    // Store a default linked list with 5 nodes
    for (int i = 1; i <= 5; i++)
    {
        insertAtBeginning(&head, i);
    }

    display(head);

    do
    {
        printf("\n1. Insert at the beginning\n");
        printf("2. Display the double linked list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
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