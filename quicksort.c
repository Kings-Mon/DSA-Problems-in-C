#include <stdio.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[low];
    int start = low;
    int end = high;
    
    while(start < end)
    {	
    	while(arr[start] <= pivot)
    	    start++;
    	while(arr[end] > pivot)
    	    end--;
    	if(start <= end)
    	    swap(&arr[start], &arr[end]);
    }
    swap(&arr[low], &arr[end]);
    return end;
}

void quicksort(int arr[], int low, int high) 
{   
    int pivotIndex;
    if (low < high) 
    {
        pivotIndex = partition(arr, low, high);

        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() 
{
    int n, i;
    int arr[n];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) 
    	scanf("%d", &arr[i]);

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    	printf("%d ", arr[i]);
    
    printf("\n");
    return 0;
}
