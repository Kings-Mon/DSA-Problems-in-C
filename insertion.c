#include<stdio.h>
int main()
{
	int a[100];
	int i, n, p, v;
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
	
printf("\nEnter the position you want to insert: ");
scanf("%d", &p);
printf("\nEnter the value you want to insert: ");
scanf("%d", &v);
	
	for(i=n-1; i>=p; i--)
		{
		  a[i+1] = a[i];
		}
		a[p] = v;
	printf("\nNew List - ");
	for(i=0; i<n+1; i++)
		{ 
		  printf("%d ",a[i]);
		}
	printf("\n");
return 0;

}
