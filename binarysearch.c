#include <stdio.h>

int binarySearch(int arr[], int low, int high, int goal) 
{
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == goal) 
            return mid;
        else if (arr[mid] < goal) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}

int main() 
{
    int n, goal;

    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &n);

    int arr[n], i;

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) 
        scanf("%d", &arr[i]);

    printf("Enter the element you want to search: ");
    scanf("%d", &goal);
    
    int result = binarySearch(arr, 0, n - 1, goal);

    if (result != -1) 
        printf("Element found at index: %d\n", result);
    else 
        printf("Element not found in the array.\n");
    return 0;
}
