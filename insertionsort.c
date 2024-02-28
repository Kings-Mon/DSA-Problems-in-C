#include <stdio.h>

int main() 
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], i;

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    
    printf("Unsorted array: ");
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]);

    for (int i = 1; i < n; i++) 
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    printf("\nSorted array: ");
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}

/*For the best case scenerio (if the list is in assending), the time complexity = O(n).
For the worst case scenerio (if the list is in dessending), the time complexity = O(n2).*/