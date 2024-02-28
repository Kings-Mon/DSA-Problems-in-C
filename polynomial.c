#include <stdio.h>
#define max 10

void main()
{
    int arr1[max],arr2[max],deg;
	int i;
    printf("\nEnter the Highest Degree for the Polynomials (max. 10): \n");
    scanf("%d", &deg);
    //first polynomial
    printf("\nWrite down the Elemnts for the First Polynomial: \n");
    for (i=deg; i>=0; i--)
    {
        printf("Enter the Coefficient of x^%d:\t", i);
        scanf("%d", &arr1[i]);
    }
    //second polynomial
    printf("\nWrite down the Elemnts for the Second Polynomial:\n");
    for (i = deg; i >= 0; i--)
    {
        printf("Enter the Coefficient of x^%d:\t", i);
        scanf("%d", &arr2[i]);
    }

    printf("The Final Polynomial: ");
//displaying the final polynomial
    for(i=deg;i>=0;i--)
	{
        if(i!=0)
		{
			printf("%dx^%d + ",arr1[i] + arr2[i],i);
		}
        else
		{
			continue;
		}
        
    }
    printf("0");

}
