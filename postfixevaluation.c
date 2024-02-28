#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char express[100];
    char x;
    int n1,n2,n3,num;
    printf("Enter an Expression: ");
    scanf("%s",express);
    printf("\n");
    int i = 0;
    
    while(express[i] != '\0')
    {
        if(isdigit(express[i]))
        {
            num = express[i] - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(express[i])
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        i++;
    }
    printf("\nThe Result of the Expression %s  =  %d\n\n",express,pop());
    
    return 0;
}
