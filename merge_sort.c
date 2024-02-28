#include<stdio.h>

void merge(int arr[], int left, int mid, int right) 
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int LeftArr[n1], RightArr[n2];

    for (i = 0; i < n1; i++)
        LeftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        RightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) 
    {
        if (LeftArr[i] <= RightArr[j]) 
        {
            arr[k] = LeftArr[i];
            i++;
        } 
        else 
        {
            arr[k] = RightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = LeftArr[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = RightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void displayArray(int arr[], int size) 
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
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
    	scanf("%d", &arr[i]);
    
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Provided Array:\n");
    displayArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted Array:\n");
    displayArray(arr, arr_size);

    return 0;
}

