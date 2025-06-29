#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the single linked list
void insertAtEnd(struct Node** head, int data)
{
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node as the head
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        // Find the last node in the single linked list
        struct Node* last = *head;
        while (last->next != NULL)
        {
            last = last->next;
        }

        // Insert the new node at the end
        last->next = newNode;
    }
}

// Function to display the single linked list
void display(struct Node* head)
{
    // If the list is empty, print a message
    if (head == NULL)
    {
        printf("Single linked list is empty.\n");
        return;
    }

    // Print the single linked list
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
        insertAtEnd(&head, i);
    }

    display(head);

    do
    {
        printf("\n1. Insert at the end\n");
        printf("2. Display the single linked list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
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