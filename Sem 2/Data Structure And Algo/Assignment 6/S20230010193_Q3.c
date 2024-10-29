#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char *stack, int *top, char a)
{
    (*top)++;
    stack[*top] = a;
}

void pop(int *top)
{
    (*top)--;
}

void infix_to_postfix(char *str)
{
    char stack[50];
    int top = -1;
    char result[50];
    int ans = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result[ans] = str[i];
            ans++;
        }
        else if (str[i] == '(')
        {
            push(stack, &top, str[i]);
        }
        else if (str[i] == ')')
        {
            while (stack[top] != '(')
            {
                result[ans] = stack[top];
                ans++;
                pop(&top);
            }
            pop(&top);
        }
        else
        {
            while (top != -1 && stack[top] != '(' && ((str[i] == '*' || str[i] == '/') ? (stack[top] != '+' && stack[top] != '-') : 1))
            {
                result[ans] = stack[top];
                ans++;
                pop(&top);
            }
            push(stack, &top, str[i]);
        }
    }

    while (top != -1)
    {
        result[ans] = stack[top];
        ans++;
        pop(&top);
    }

    result[ans] = '\0';
    //printing the result
    printf("%s\n", result);
}


int main()
{
    printf("enter the infix operation: ");
    char a[30];
    scanf("%s",a);
    infix_to_postfix(a);
    return 0;
}
