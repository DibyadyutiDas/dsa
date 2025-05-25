#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void deleteAtEnd(struct Node** head)
{
    if (*head == NULL)
    {
        printf("Double linked list is empty.\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    struct Node* secondLast = last->prev;
    secondLast->next = NULL;

    free(last);
}

void display(struct Node* head)
{
    if (head == NULL)
    {
        printf("Double linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Data are - ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertAtEnd(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->prev = NULL;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

int main()
{
    struct Node* head = NULL;
    int choice;

    for (int i = 1; i <= 5; i++)
    {
        insertAtEnd(&head, i);
    }

    display(head);

    do
    {
        printf("\n1. Delete at the end\n");
        printf("2. Display the double linked list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
            case 1:
                deleteAtEnd(&head);
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