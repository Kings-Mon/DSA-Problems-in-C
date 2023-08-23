#include<stdio.h>
#include<stdlib.h>

int top = -1;
char stack[100];
void push(char a)
{
      top++;
      stack[top] = a;
}
void pop()
{
      if (top == -1)
      {
            printf("Expression is Empty.\n");
            exit(0);
      }
      else
      {
            top--;
      }
}
int main()
{
      int i;
      char a[100];
      printf("\nEnter an Expression : ");
      scanf("%s",a);
      for (i = 0; a[i] != '\0';i++)
      {
       if (a[i] == '(')
       	{
        		push(a[i]);
       	}
       else if (a[i] == '{')
       	{
          	push(a[i]);
       	}
       else if (a[i] == '[')
       	{
          	push(a[i]);
       	}
       else if (a[i] == ')')
       	{
          	pop();
       	}
       else if (a[i] == '}')
       	{
          	pop();
       	}
       else if (a[i] == ']')
       	{
          	pop();
       	}
      }
      if (top == -1)
      	printf("Expression is Valid.\n");
      else
      	printf("Expression is Invalid.\n");
      	
      return 0;
}
