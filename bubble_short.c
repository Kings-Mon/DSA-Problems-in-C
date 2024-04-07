/*           BUBBLE    SHORT           */
/*##################################################################################################3*/

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
    
    printf("Unsorted Array : ");
    for (i=0; i<n; i++)
        printf("%d ", arr[i]);

    for (i = 0; i < n-1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n-1-i; j++)
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

    printf("\nSorted array in Ascending order: ");
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

/*##################################################################################################3*/

/* Another Way, */

#include <stdio.h>

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
}

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
    
    printf("Sorted array in Ascending order: ");
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

/*##################################################################################################3*/


/*
The time complexity of Bubble Sort is O(n^2) in the worst-case scenario.
*/
