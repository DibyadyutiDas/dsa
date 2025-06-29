#include<stdio.h>
#include<stdio.h>
#include<conio.h>

struct bin_tree
{
    int info;
    struct node *left,*right;
};

typedef struct bin_tree node;

node *insert (node*,int);
void display (node*);
int count = 1;

void main()
{
    struct node *root =NULL;
    int element, choice;

    clrscr();

    while (1)
    {
        // clrscr();
        printf("Select an option\n");
        printf("\n1 - Insert");
        printf("\n2 - Display");
        printf("\n3 - Exit");
    }
    
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
}