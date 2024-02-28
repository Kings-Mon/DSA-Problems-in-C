#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *newnode;

void create();
void display();

int main()
{
    int choice = 0;  
    while(choice != 3)   
    {   
        printf("\nChoose from the menu : \
            1. Create \
            2. Display \
            3. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}

void create()
{
    head = 0; 
    struct node *temp = NULL;
    int choice = 1;
    while(choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newnode -> data);

        newnode->prev = 0;
        newnode->next = 0;
        
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);
    }
}

void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to Print!\n");  
    }  
    else  
    {  
        printf("\nPrinting the Values . . . . .\n");   
        while (ptr != NULL)  
        {  
            printf("\n%d", ptr->data);  
            ptr = ptr->next;  
        }  
    }  
}