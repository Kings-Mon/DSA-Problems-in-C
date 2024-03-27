/*  A Basic Queue Data Structure Using an Array in C. */
/* ######################################################################################################## */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void enqueue();
void dequeue();
void show();
int inp_arr[SIZE];
int Rear = -1;
int Front = -1;
int i;

int main() 
{
    int ch;
    while (1) 
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter Your Choice of Operations : ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
            default:
                printf("Incorrect Choice.\n");
        }
    }
    return 0;
}

void enqueue() 
{
    int insert_item;
    printf("Element to be Inserted in the Queue: ");
    scanf("%d", &insert_item);

    if (Rear == SIZE - 1)
        printf("Overflow\n");
    else if (Front == -1 && Rear == -1) 
    {
        Front = Rear = 0;
        inp_arr[Rear] = insert_item;
        printf("Element Inserted.\n");
    } 
    else 
    {
        Rear++;
        inp_arr[Rear] = insert_item;
        printf("Element Inserted.\n");
    }
}

void dequeue() 
{
    if (Front == -1 || Front > Rear) 
    {
        printf("Underflow\n");
        return;
    } 
    else if (Front == Rear)
        Front = Rear = -1;
    else
    {
        printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
        Front++;
    }
}

void show() 
{
    if (Front == -1)
        printf("Empty Queue!\n");
    else 
    {
        printf("Queue:- ");
        for (i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}
