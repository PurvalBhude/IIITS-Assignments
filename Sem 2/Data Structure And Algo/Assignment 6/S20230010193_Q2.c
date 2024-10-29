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

void palindrome_stack(char *str)
{
    char stack[50];
    int top = -1;
    for (int i = 0; i < (strlen(str) / 2); i++)
    {
        push(stack, &top, str[i]);
    }

    int j;
    if (strlen(str) % 2 == 0)
    {
        j = strlen(str) / 2;
    }
    else
    {
        j = (strlen(str) / 2) + 1;
    }

    while (j < strlen(str))
    {
        if (str[j] != stack[top])
        {
            printf("it is not a palindrome\n");
            return;
        }
        pop(&top);
        j++;
    }
    if (top == -1)
    {
        printf("it is palindrome\n");
    }
    else
    {
        printf("it is not a palindrome\n");
    }
}

int main()
{
    printf("enter the string for which you have to check palindrome: ");
    char a[50];
    scanf("%s",a);
    palindrome_stack(a);
    return 0;
}
