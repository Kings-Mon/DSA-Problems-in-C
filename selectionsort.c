/*#include <stdio.h>

void swap(int *a, int *b) 
{
    int constant = *a;
    *a = *b;
    *b = constant;
}

void selectionSort(int arr[], int n) 
{
    int i, j, minIndex;

    for (i = 0; i < n-1; i++) 
    {
        minIndex = i;
        for (j = i+1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        if (i != minIndex)
        {
        	swap(&arr[i], &arr[minIndex]);
        }
    }
}

void printArray(int arr[], int size) 
{
    int i;
    for (i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int n;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n], i;

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Provided array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}*/

#include<stdio.h>

int main() 
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n], i;

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) 
        scanf("%d", &arr[i]);

    printf("Provided array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    
    printf("Sorted array: ");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}