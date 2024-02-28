#include<stdio.h>
int main()
{
	int a[100];
	int i, n, p, v;
	int operation;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
		{ 
		  printf("Enter the elements: ");
		  scanf("%d",&a[i]);
		}
	
	printf("\nEnter An Operation - \n Press 1 to Insert. \n Press 2 to Delete. \n Press 3 to Display.\n");
	scanf("%d", &operation);
	
switch(operation)
{
	case 1:
	
	printf("\nEnter the position you want to insert: ");
	scanf("%d", &p);
	printf("\nEnter the value you want to insert: ");
	scanf("%d", &v);
	
	for(i=n-1; i>=p; i--)
		{
		  a[i+1] = a[i];
		}
		a[p] = v;
	printf("\nNew Array - ");
	for(i=0; i<n+1; i++)
		{ 
		  printf("%d ",a[i]);
		}
	printf("\n");
	break;

	case 2:
	
	printf("\nEnter the position you want to delete: ");
	scanf("%d", &p);
	for(i=p; i<n-1; i++)
		{
		  a[i] = a[i+1];
		}
	printf("\nNew Array - ");
	for(i=0; i<n-1; i++)
		{ 
		  printf("%d ",a[i]);
		}
	printf("\n");
	break;
	
	case 3:

	printf("Displaying The Inserted Array - ");
	for(i=0; i<n; i++)
		{ 
		  printf("%d ",a[i]);
		}
	break;
	
	default:
	printf("Invalid Input.\n");
	
	}
printf("\n");

return 0;
}
