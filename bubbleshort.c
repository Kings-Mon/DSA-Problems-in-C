#include <stdio.h>

int main() 
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n], i;
    
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    for (i = 0; i < n-1; i++)
    {
        int flag = 0;
        for ( int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            } 
        }
        if (flag == 0)
            break;
    }

    printf("Sorted array in Ascending order: ");
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]);
        
    printf("\n");
    return 0;
}

/*#include <stdio.h>

int main() 
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n], i;
    
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    bubbleSort(arr, n);
    
    printf("Sorted array in ascending order: ");
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) 
{
    for ( int i = 0; i < n - 1; i++) 
    {
        for ( int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
                swap(&arr[j], &arr[j + 1]);
        }
    }
}*/
