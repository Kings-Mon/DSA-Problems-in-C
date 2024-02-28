#include<stdio.h>  
#include<stdlib.h>  

struct node   
{  
    int data;  
    struct node *next;
    struct node *prev;  
};  
struct node *head, *tail;  

void insert_begin();   
void insert_end();  
void insert_anywhere();  
void delete_begin();  
void delete_end();  
void delete_random();  
void display();
void reverse(); 

void main()  
{  
    int choice = 0;  
    while(choice != 10)   
    {   
        printf("\nChoose from the menu : \n1.Insert in Begining\n2.Insert at Last\n3.Insert at any Random Location\n4.Delete from Beginning\n5.Delete from Last\n6.Delete Node from Specified Location\n7.Show\n8.Reverse\n9.Exit\n");  
        printf("\nEnter your Choice -> ");         
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insert_begin();      
            break;  
            case 2:  
            insert_end();         
            break;  
            case 3:  
            insert_anywhere();       
            break;  
            case 4:  
            delete_begin();       
            break;  
            case 5:  
            delete_end();        
            break;  
            case 6:  
            delete_random();          
            break;    
            case 7:  
            display();        
            break;  
            case 8: 
			reverse();
			break;
			case 9:
            printf("\nProgram Ended.\n");  
            exit(0);  
            break;  
            default:  
            printf("Please Enter A Valid Choice!\n");  
        }  
    }  
}  

void insert_begin()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed. Overflow!\n");
        return;
    }
    printf("Enter Data - ");
    scanf("%d", &newnode -> data);

    newnode -> prev = 0;
    newnode -> next = 0;

    if (head == 0)
    {
        head = tail = newnode;
        printf("Node Inserted.\n");
    }
    else
    {
        head -> prev = newnode;
        newnode -> next = head;
        head = newnode;
        printf("\nNode Inserted at the Beginning.\n");
    }
}

void insert_end()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        printf("Memory allocation failed. Overflow!\n");

    printf("Enter Data - ");
    scanf("%d", &newnode -> data);

    newnode -> prev = 0;
    newnode -> next = 0;

    if (head == 0)
    {
        newnode -> next = NULL;  
        head = newnode;  
        printf("\nNode Inserted at the End.\n");  
    }
    else
    {
        tail -> next = newnode;
        newnode -> prev = tail;
        tail = newnode;
        printf("\nNode Inserted at the End.\n");
    }
}

void insert_anywhere()
{
    int pos;
    struct node *newnode, *temp;  
    newnode = (struct node *) malloc (sizeof(struct node));  
    if (newnode == NULL)
        printf("Memory allocation failed. Overflow!\n");
    else  
    {  
        printf("\nEnter the location at which you want to insert - ");  
        scanf("\n%d", &pos);  
        
        temp = head;  
        int length = 0;
        // Calculate the length of the linked list
        while(temp != NULL) 
        {
            length++;
            temp = temp->next;
        }

        if (pos < 1 || pos > length)
            printf("Invalid Location.\n");
        else if (pos == 1)
            insert_begin();
        else
        {
            printf("\nEnter Element Value - ");  
            scanf("%d", &newnode->data);
            temp = head;
            int i = 1;  // Reset i to 1 before traversing the list again
            while(i < pos - 1)  
            {  
                temp = temp->next;
                i++; 
            }  
            newnode -> prev = temp;
            newnode -> next = temp -> next;  
            temp -> next = newnode;
            newnode -> next -> prev = newnode;
            printf("\nNode Inserted at the provided postion.\n");
        }
    }
}

void delete_begin()
{
    struct node *temp;
    if (head == NULL)
        printf("List is Empty!\n");
    else
    {
        temp = head;

        if (head -> next != NULL)
        {
            head = head -> next;
            head -> prev = NULL;  // Update prev only if there's a new head
        }
        else
            head = NULL;  // Set head to NULL if deleting the last node
        free(temp);
        printf("Node Deleted from the Beginning!\n");
    }
}

void delete_end()
{
    struct node *temp;
    if (tail == NULL)
        printf("List is Empty!\n");
    else
    {
        temp = tail;

        if (tail -> prev != NULL)
        {
            tail -> prev -> next = NULL;  // Update next only if there's a new tail
            tail = tail -> prev;
        }
        else
            tail = NULL;  // Set tail to NULL if deleting the last node
        free(temp);
        printf("Node Deleted from the End!\n");
    }
}

void delete_random()
{
    int pos, i = 1;
    struct node *temp;
    printf("\nEnter the position where you want to delete - ");
    scanf("%d", &pos);
    temp = head;  
    int length = 0;
    
    // Calculate the length of the doubly linked list
    while (temp != NULL) 
    {
        length++;
        temp = temp->next;
    }

    if (pos < 1 || pos > length)
    {
        printf("Invalid Location.\n");
    }
    else if (pos == 1)
    {
        delete_begin();
    }
    else
    {
        temp = head;  // Reset temp to head for traversal
        while (temp != NULL && i < pos)
        {
            temp = temp->next;
            i++;
        }

        if (temp == NULL)
        {
            printf("Invalid position. Can't delete!\n");
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        printf("\nNode deleted from the given position.\n");
    }
}

void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)
        printf("Nothing to Print!\n");  
    else  
    {  
        printf("\nPrinting the Values :- \n");   
        while (ptr != NULL)  
        {  
            printf("\n%d", ptr->data);  
            ptr = ptr->next;  
        }  
    }  
}

void reverse()
{
    struct node *next_node, *current_node;
    current_node = head;

    while (current_node != NULL)
    {
        next_node = current_node -> next;
        current_node -> next = current_node -> prev;
        current_node -> prev = next_node;
        current_node = next_node;
    }

    current_node = head;
    head = tail;
    tail = current_node;
    printf("Node Reversed.\n");
}
