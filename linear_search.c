/*         LINEAR   SEARCH          */
/*##################################################################################################3*/

#include<stdio.h>

int main() 
{
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n], value;
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) 
        scanf("%d", &arr[i]);

    printf("Enter the value to search for: ");
    scanf("%d", &value);

    for (i=0; i<n; i++)
    {
        if (arr[i] == value)
        {
            printf("Element found at index - %d.\n", i);
            break;
        }
    }
    if (i == n)
        printf("Element not found!\n");
    return 0;
}

/*##################################################################################################3*/

/* Another Way, */

#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == key) 
            return i;
    }
    return -1;
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

    int key;
    printf("Enter the value to search for: ");
    scanf("%d", &key);

    int result = linearSearch(arr, n, key);
    
    if (result != -1) 
        printf("Element %d found at index %d\n", key, result);
    else 
        printf("Element %d not found in the array.\n", key);
    return 0;
}

/*##################################################################################################3*/
