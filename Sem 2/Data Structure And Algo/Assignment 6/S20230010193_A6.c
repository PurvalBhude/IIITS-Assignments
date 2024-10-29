#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Question 1
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *child;
} Node;

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->child = NULL;
    return node;
}

Node *one_pointer(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->child != NULL)
        {
            tail->next = curr->child;
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
            curr->child = NULL;
        }
        curr = curr->next;
    }

    return head;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int sizeoflist(Node * head){
    int i =0;
    while (head != NULL)
    {
        i++;
        head = head->next;
    }
    return i;
}

void sort(int *A, int length) {
    for (int j = 1; j < length; j++) {
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

//Question 2

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

//Question 3
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
    // //Question 1
    // Node *head = newNode(1);
    // head->next = newNode(6);
    // head->next->next = newNode(3);
    // head->next->next->next = newNode(5);
    // head->next->next->next->next = newNode(5);

    // head->child = newNode(2);
    // head->child->next = newNode(9);
    // head->child->next->next = newNode(0);

    // head->next->next->child = newNode(19);
    // head->next->next->child->next = newNode(3);

    // printf("Original List:\n");
    // printList(head);

    // //a) one pointer
    // head = one_pointer(head);

    // printf("one pointer List:\n");
    // printList(head);

    // //b) sort array
    // int n = sizeoflist(head);
    // int arr[n];
    // Node *curr = head;
    // for(int i=0;i<n;i++){
    //     arr[i] = curr->data;
    //     curr = curr->next;
    // }

    // sort(arr,n);
    // curr = head;
    // for(int i=0;i<n;i++){
    //     curr->data = arr[i];
    //     curr = curr->next;
    // }

    // printf("sorted list\n");
    // printList(head);

    // //Question 2
    // printf("enter the string for which you have to check palindrome: ");
    // char a[50];
    // scanf("%s",a);
    // palindrome_stack(a);

    // //Question 3
    // printf("enter the infix operation: ");
    // char a[30];
    // scanf("%s",a);
    // infix_to_postfix(a);
}
