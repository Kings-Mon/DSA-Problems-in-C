#include <stdio.h>
#define MAX_SIZE 100
int temp, i, j;
void swap(int *xp, int *yp)
{
	temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void sort(int arr[], int n) 
{
	for (i=0; i<n-1; i++) 
	{
		for (j=0; j<n-i-1; j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
void main() 
{
int n, l, k; 
int arr1[MAX_SIZE], arr2[MAX_SIZE], outarr[MAX_SIZE];
printf("Enter the size of the 1st array: ");
scanf("%d", &n);
printf("Enter the Elements of the First Array: \n");
for(i=0; i<n; i++)
{
	scanf("%d",&arr1[i]);
}
printf("Enter the size of the 2nd array: ");
scanf("%d", &l);
printf("Enter the Elements of the Second Array: \n");
for(k = 0;k<l;k++)
{
	scanf("%d",&arr2[k]);
}
for(i=0;i<n+l;i++)
{
	if(i<n)
	{
		outarr[i]=arr1[i];
	}
	else
	{	
		outarr[i]=arr2[i-n];
	}
}
printf("The Merged Array: { ");
for(i=0;i<n+l;i++)
{
	printf("%d ",outarr[i]);
}
printf("}\n");
sort(outarr,n+l);
printf("Sorted array in Ascending Order: { ");
for (i = 0; i < n+l; i++) 
{
	printf("%d ", outarr[i]);
}
printf("}\n");
}
