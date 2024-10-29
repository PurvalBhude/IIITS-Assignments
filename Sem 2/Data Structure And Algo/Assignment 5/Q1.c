#include <stdio.h>
#include <stdlib.h>

// Q1
struct Node
{
    int data;
    struct Node *next;
};

// single linked list
// insertion at begining
void insert_begin(struct Node *head, int data)
{
    if (head == NULL)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = NULL;
        head = temp;
        return;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

// insertion at end
void insert_end(struct Node *head, int data)
{
    if (head == NULL)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = NULL;
        head = temp;
        return;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    struct Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
}

// insertion at any point (*Zero based indexing*)
void insert_position(struct Node *head, int location, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;

    struct Node *curr = head;
    for (int i = 0; (i < location - 1) && (curr->next != NULL); i++)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
}

// deletion
void delete(struct Node *head, int position)
{
    struct Node *curr = head;
    for (int i = 0; i < position - 1; i++)
    {
        curr = curr->next;
    }

    struct Node *delete = curr->next;
    curr->next = curr->next->next;
    free(delete);
}

// cycle detection
void cycle_detection(struct Node *head)
{
    struct Node *curr1 = head;
    struct Node *curr2 = head;

    while ((curr2->next != NULL) && (curr2 != NULL))
    {
        curr1 = curr1->next;
        curr2 = curr2->next->next;

        if (curr1 == curr2)
        {
            printf("\ncycle is detected, linked list contain cycle\n");
            return;
        }

        printf("\nlinked list does not contain any cycle\n");
        return;
    }
}

// reversal of linked list
// time complexity O(n)
// space complexity O(n)
void reversal(struct Node *head)
{
    // getting size of linked list
    int n = 0;
    struct Node *curr = head;
    while (curr != NULL)
    {
        n++;
    }

    // putting element in array
    int arr[n];
    curr = head;
    for (int i = 0; i < n; i++)
    {
        arr[i] = curr->data;
        curr = curr->next;
    }

    // reversing an array
    int c;
    for (int i = 0; i < n / 2; i++)
    {
        c = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = c;
    }

    // putting reverse array element in linked list
    curr = head;
    for (int i = 0; i < n; i++)
    {
        curr->data = arr[i];
        curr = curr->next;
    }
}

int main()
{
}