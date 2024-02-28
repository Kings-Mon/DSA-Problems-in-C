#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data) 
{
    if ((rear + 1) % MAX_SIZE == front)
    {
        printf("Overflow\n");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front=rear = 0;
        queue[rear] = data; 
    }
    else 
    {
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = data; 
    }
}

void dequeue() 
{
    if(front == -1 && rear == -1)
        printf("Underflow!\n");
    else if (front == rear)
    {
    	front = rear = -1;
    }
    else
    {
     	printf("Deleted Element is: %d\n", queue[front]);
     	front = (front + 1) % MAX_SIZE;
    }
}


void display() 
{
    printf("Elements in the queue: ");
    int i = front;
    do 
	{
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } 
	while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() 
{
    int choice, data;
    while (1) 
	{
        printf("\nCircular Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter element to Enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
