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
        printf("Circular doubly linked list is empty.\n");
        return;
    }

    if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* last = (*head)->prev;
    struct Node* secondLast = last->prev;

    secondLast->next = *head;
    (*head)->prev = secondLast;

    free(last);
}

void display(struct Node* head)
{
    if (head == NULL)
    {
        printf("Circular doubly linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Data are - ");
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void insertAtEnd(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

    struct Node* last = (*head)->prev;

    last->next = newNode;
    newNode->prev = last;

    newNode->next = *head;
    (*head)->prev = newNode;
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
        printf("2. Display the circular doubly linked list\n");
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