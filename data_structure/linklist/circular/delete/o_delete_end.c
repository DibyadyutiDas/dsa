#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteAtEnd(struct Node** head)
{
    if (*head == NULL)
    {
        printf("Circular linked list is empty.\n");
        return;
    }

    if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* secondLast = *head;
    while (secondLast->next->next != *head)
    {
        secondLast = secondLast->next;
    }

    struct Node* last = secondLast->next;
    secondLast->next = *head;
    free(last);
}

void display(struct Node* head)
{
    if (head == NULL)
    {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Data are - ");
    do
    {
        printf("%d", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void insertAtEnd(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    struct Node* last = *head;
    while (last->next != *head)
    {
        last = last->next;
    }

    last->next = newNode;
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
        printf("2. Display the circular linked list\n");
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