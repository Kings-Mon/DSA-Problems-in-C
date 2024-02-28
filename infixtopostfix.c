#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int presedence(char a)
{
    if (a == '(')
        return 0;
    if (a == '+' || a == '-')
        return 1;
    if (a == '*' || a == '/')
        return 2;
    return 0;
}
int main()
{
    char express[100], x;
    printf("Enter an Expression: ");
    scanf("%s", express);
    printf("\n");
    int i = 0;
    
    while (express[i] != '\0')
    {
        if (isalnum(express[i]))
            printf("%c ", express[i]);
        else if (express[i] == '(')
            push(express[i]);
        else if (express[i] == ')')
        {
            while ((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while (presedence(stack[top]) >= presedence(express[i]))
                printf("%c ", pop());
            push(express[i]);
        }
        i++;
    }
    while (top != -1)
    {
        printf("%c ", pop());
    }
    printf("\n");
    return 0;
}

