#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev; // New pointer for double linked list
};

// Function to insert a node at the beginning of a double linked list
void insert(struct Node** head, int data) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    // If the list is empty, make the new node as the head
    if (*head == NULL) {
        *head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else {
        // Make the new node as the head
        newNode->next = *head;
        newNode->prev = NULL;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to reverse a double linked list
void reverse(struct Node** head) {
    if (*head == NULL)
        return;

    // Initialize three pointers
    struct Node* current = *head;
    struct Node* next = NULL;
    struct Node* prev = NULL;

    // Reverse the links between nodes
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }

    // Update the head pointer
    *head = prev;
}

// Function to print a double linked list
void display(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
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

    printf("Original Double Linked List: ");
    display(head);

    // Reverse the double linked list
    reverse(&head);

    printf("\nReversed Double Linked List: ");
    display(head);

    return 0;
}