#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
} *head;

void create_cll();
void display_cll();

void main()
{
    int choice = 0;  
    while(choice != 3)   
    {   
        printf("\nChoose your option : \
            1. Create A Circular Linked List \
            2. Display \
            3. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create_cll();
                break;

            case 2:
                display_cll();
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
}

void create_cll()
{
    struct node *newnode, *temp;
    head = NULL;
    bool choice = true;
    while (choice)
    {
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter Data to Insert - ");
        scanf("%d", &newnode -> data);

        if (head == NULL)
            head = temp = newnode;
        else
        {
            temp -> next = newnode;
            temp = newnode;
        }
        temp -> next = head;

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);
    }
}

void display_cll()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
        printf("Nothing to Print!\n");
    else
    {
        printf("\nPrinting the Elements :- \n");
        do
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
        printf("\n");
    }
}
