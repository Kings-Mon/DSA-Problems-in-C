#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

// Function to insert a node at the beginning of the Doubly Circular linked list
void insertAtBeginning(int value) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) 
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } 
    else 
    {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node inserted at the Beginning.\n");
}

// Function to insert a node at a specific position in the Doubly Circular linked list
void insertAtPosition(int value, int position) 
{
    if (position < 1) 
    {
        printf("Invalid Position!\n");
        return;
    }
    if (position == 1) 
    {
        insertAtBeginning(value);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node *temp = head;
    int currentPosition = 1;

    while (currentPosition < position - 1 && temp->next != head) 
    {
        temp = temp->next;
        currentPosition++;
    }

    if (currentPosition != position - 1) 
    {
        printf("Invalid Position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    printf("Node inserted at the Position.\n");
}

// Function to insert a node at the end of the Doubly Circular linked list
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) 
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } 
    else 
    {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }

    printf("Node inserted at the End.\n");
}

// Function to delete a node from the beginning of the Doubly Circular linked list
void deleteFromBeginning() 
{
    if (head == NULL) 
    {
        printf("List is Empty. Nothing to Delete!\n");
        return;
    }

    struct Node *temp = head;

    if (head->next == head) 
    {
        head = NULL;
    } 
    else 
    {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
    }

    free(temp);
    printf("Node deleted from Beginning.\n");
}

// Function to delete a node from a specific position in the Doubly Circular linked list
void deleteFromPosition(int position) 
{
    if (head == NULL) 
    {
        printf("List is Empty. Nothing to Delete!\n");
        return;
    }
    if (position < 1) 
    {
        printf("Invalid Position!\n");
        return;
    }
    if (position == 1) 
    {
        deleteFromBeginning();
        return;
    }

    struct Node *temp = head;
    int currentPosition = 1;

    while (currentPosition < position && temp->next != head) 
    {
        temp = temp->next;
        currentPosition++;
    }

    if (currentPosition != position) 
    {
        printf("Invalid Position!\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    printf("Node deleted from the Position.\n");
}

// Function to delete a node from the end of the Doubly Circular linked list
void deleteFromEnd() 
{
    if (head == NULL) 
    {
        printf("List is Empty. Nothing to Delete!\n");
        return;
    }

    struct Node *temp = head->prev;

    if (temp == head) 
    {
        head = NULL;
    } 
    else 
    {
        temp->prev->next = head;
        head->prev = temp->prev;
    }

    free(temp);
    printf("Node deleted from the End.\n");
}

// Function to reverse the Doubly Circular linked list
void reverse() 
{
    if (head == NULL) 
    {
        printf("List is Empty!\n");
        return;
    }

    struct Node *current = head;
    struct Node *temp;

    do 
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != head);

    head = temp->prev; // Update the head to the new starting node

    printf("Doubly Circular Linked List reversed.\n");
}

// Function to display all the nodes in the Doubly Circular linked list
void display() 
{
    if (head == NULL) 
    {
        printf("List is Empty!\n");
        return;
    }

    struct Node *temp = head;

    do 
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() 
{
    int choice, value, position;
    while (1) 
    {
        printf("Doubly Circular Linked List Operations:-\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at a specific position\n");
        printf("3. Insert at the end\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from a specific position\n");
        printf("6. Delete from the end\n");
        printf("7. Reverse the Doubly Circular Linked List\n");
        printf("8. Display all nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                reverse();
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
