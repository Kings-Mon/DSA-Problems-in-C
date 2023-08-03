#include<stdio.h>
int main()
{
	int a[100];
	int i, n, p;
	printf("Enter the numbers of element: ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
		{ 
		  printf("Enter the elements: ");
		  scanf("%d",&a[i]);
		}
	printf("The List - ");
	for(i=0; i<n; i++)
		{ 
		  printf("%d ",a[i]);
		}
	
printf("\nEnter the position you want to delete: ");
scanf("%d", &p);
	for(i=p; i<n-1; i++)
		{
		  a[i] = a[i+1];
		}
	printf("\nNew List - ");
	for(i=0; i<n-1; i++)
		{ 
		  printf("%d ",a[i]);
		}
	printf("\n");
	
return 0;
}
