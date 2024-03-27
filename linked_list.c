#include<stdio.h>  
#include<stdlib.h>  

struct node   
{  
    int data;  
    struct node *next;   
};  

struct node *head;  

void begin_insert();   
void last_insert();  
void random_insert();  
void begin_delete();  
void last_delete();  
void random_delete();  
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
            begin_insert();      
            break;  
            case 2:  
            last_insert();         
            break;  
            case 3:  
            random_insert();       
            break;  
            case 4:  
            begin_delete();       
            break;  
            case 5:  
            last_delete();        
            break;  
            case 6:  
            random_delete();          
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
            printf("Please Enter Valid Choice...\n");  
        }  
    }  
}

void begin_insert()  
{  
    struct node *ptr;    
    ptr = (struct node *) malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW!");  
    }  
    else  
    {  
        printf("\nEnter Value - ");    
        scanf("%d",&ptr->data);      
        ptr->next = head;  
        head = ptr;  
        printf("\nNode Inserted.\n");  
    }
      
}  

void last_insert()  
{  
    struct node *ptr,*temp;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW!");     
    }  
    else  
    {  
        printf("\nEnter Value - ");  
        scanf("%d",&ptr->data);   
        if(head == NULL)  
        {  
            ptr -> next = NULL;  
            head = ptr;  
            printf("\nNode Inserted.\n");  
        }  
        else  
        {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
            printf("\nNode Inserted.\n");  
          
        }  
    }  
}  

void random_insert()  
{  
    int loc;
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW!");  
    }  
    else  
    {  
        printf("\nEnter the location at which you want to insert - ");  
        scanf("\n%d", &loc);  
        
        temp = head;  
        int length = 0;
        // Calculate the length of the linked list
        while(temp != NULL) 
        {
            length++;
            temp = temp->next;
        }

        if(loc < 1 || loc > length)
            printf("Invalid Location.\n");
        else if (loc == 1)
        {
            begin_insert();
        }
        else
        {
            printf("\nEnter Element Value - ");  
            scanf("%d", &ptr->data);
            temp = head;
            int i = 1;  // Reset i to 1 before traversing the list again
            while(i < loc - 1)  
            {  
                temp = temp->next;
                i++; 
            }  
            ptr->next = temp->next;   
            temp->next = ptr;   
            printf("\nNode Inserted.\n");
        } 
    }  
}  

void begin_delete()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nList is Empty.\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr -> next;  
        free(ptr);  
        printf("\nNode Deleted from the Begining.\n");  
    }  
}  

void last_delete()  
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("\nList is Empty.\n");  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly Node of the List is Deleted!\n");  
    }     
    else  
    {  
        ptr = head;   
        while(ptr -> next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1 -> next = NULL;  
        free(ptr);  
        printf("\nDeleted Node from the Last.\n");  
    }     
}  

void random_delete()  
{  
    struct node *ptr, *ptr2;  
    int loc, i = 1;    
    printf("\nEnter the location of the node which you want to delete - ");  
    scanf("%d", &loc);  
    ptr = head;
    int length = 0;
    // Calculate the length of the singly linked list
    while (ptr != NULL) 
    {
        length++;
        ptr = ptr->next;
    }
    if (loc < 1 || loc > length)
    {
        printf("Invalid Location.\n");
    }
    else if (loc == 1)
    {
        begin_delete();
    }
    else 
    {
        ptr = head;

        while (i < loc - 1)
        {     
            ptr = ptr->next;  
            i++;
            
            if (ptr == NULL)  
            {   
                printf("\nCan't Delete!\n");  
                return;  
            }  
        }  
        ptr2 = ptr->next;
        ptr->next = ptr2->next;
        free(ptr2);  
        printf("\nNode deleted from the position."); 
    }
} 

void reverse()
{
	struct node *prevnode, *nextnode, *currentnode;
	prevnode = 0;
	currentnode = nextnode = head;
	while(nextnode != NULL)
	{
	    nextnode = nextnode -> next;
		currentnode -> next = prevnode;
		prevnode = currentnode;
		currentnode = nextnode;
	}
	head = prevnode;
	printf("\nList Reversed.\n");
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
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
} 
