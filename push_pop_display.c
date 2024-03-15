#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int top = -1, stack[SIZE];

void push();
void pop();
void show();
void peak();

int main() 
{
    int choice;

    while (1) 
    {
        printf("\nPerform Stack Operations :- ");
        printf("\n1. Push the element\n2. Pop the element\n3. Peek\n4. Display\n5. End");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peak();
                break;
            case 4:
                show();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid Choice!!");
        }
    }
}

void push() 
{
    int x;
    if (top == SIZE - 1)
        printf("\nOverflow!! Cannot push element onto full stack.");
    else 
    {
        printf("\nEnter the element to be pushed onto the stack: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("Element %d pushed onto the stack.", x);
    }
}

void pop() 
{
    if (top == -1)
        printf("\nUnderflow!! Stack is empty.");
    else 
    {
        printf("\nElement %d popped from the stack.", stack[top]);
        top--;
    }
}

void peak() 
{
    if (top == -1)
        printf("\nUnderflow!! Stack is empty.");
    else
        printf("\nTop element of the stack: %d", stack[top]);
}

void show() 
{
    if (top == -1)
        printf("\nUnderflow!! Stack is empty.");
    else 
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}
