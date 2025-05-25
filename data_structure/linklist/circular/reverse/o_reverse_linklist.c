#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of a circular linked list
void insert(struct Node** head, int data) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    // If the list is empty, make the new node as the head
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    }
    else {
        // Find the last node and make the new node as its next
        struct Node* last = *head;
        while (last->next != *head)
            last = last->next;
        last->next = newNode;

        // Make the new node's next as the head
        newNode->next = *head;

        // Make the new node as the head
        *head = newNode;
    }
}

// Function to reverse a circular linked list
void reverse(struct Node** head) {
    if (*head == NULL)
        return;

    // Initialize three pointers
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next;

    // Reverse the links between nodes
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);

    // Update the head pointer
    (*head)->next = prev;
    *head = prev;
}

// Function to print a circular linked list
void display(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    struct Node* head = NULL;
    int data, numNodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the data for each node:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: ", i + 1);
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("Original Circular Linked List: ");
    display(head);

    // Reverse the circular linked list
    reverse(&head);

    printf("\nReversed Circular Linked List: ");
    display(head);

    return 0;
}