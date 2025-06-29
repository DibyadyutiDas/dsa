#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head = NULL,*new_node,*temp;
    int no,i = 0;

    printf("How many node you want - ");
    scanf("%d",&no);

    for (int i = 0; i < no; i++)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data - ");
        scanf("%d",&new_node->data);
        new_node->link = NULL;
        
        if (head == NULL)
        {
            head = temp = new_node;
        }
        else
        {
            temp->link = new_node;
            temp = new_node;
        }
    }

    //display
    temp = head;
    while (temp != NULL)
    {
        printf("\n%d",temp->data);
        temp = temp->link;
    }

    return 0;
}