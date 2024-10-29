#include <stdio.h>
#include <stdlib.h>

// Q2
struct Double_Node
{
    struct Double_Node *prev;
    int data;
    struct Double_Node *next;
};

// doubly linked list
// inserting at begining
void doubly_insert_begin(struct Double_Node *head, int data)
{
    if (head == NULL)
    {
        struct Double_Node *temp = (struct Double_Node *)malloc(sizeof(struct Double_Node));
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return;
    }
    struct Double_Node *temp = (struct Double_Node *)malloc(sizeof(struct Double_Node));
    head->prev = temp;
    temp->next = head;
    temp->prev = NULL;
    temp->data = data;
    head = temp;
}

// inserting at end
void doubly_insert_end(struct Double_Node *head, int data)
{
    if (head == NULL)
    {
        struct Double_Node *temp = (struct Double_Node *)malloc(sizeof(struct Double_Node));
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return;
    }
    struct Double_Node *temp = (struct Double_Node *)malloc(sizeof(struct Double_Node));
    struct Double_Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    temp->next = NULL;
    temp->data = data;
}

// inserting at any position
void doubly_insert_position(struct Double_Node *head, int position, int data)
{
    struct Double_Node *temp = (struct Double_Node *)malloc(sizeof(struct Double_Node));
    struct Double_Node *curr = head;
    for (int i = 0; i < position - 1; i++)
    {
        curr = curr->next;
    }
    temp->data = data;
    temp->prev = curr;
    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
}

// deletion at begining
void doubly_delete_begin(struct Double_Node *head)
{
    struct Double_Node *temp = head;
    head = temp->next;
    head->prev = NULL;
    free(temp);
}

// deletion at end
void doubly_delete_end(struct Double_Node *head)
{
    struct Double_Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    struct Double_Node *temp = curr->next;
    curr->next = NULL;
    free(temp);
}

// deletion at any position
void doubly_delete_position(struct Double_Node *head, int position)
{
    struct Double_Node *curr = head;
    for (int i = 0; i < position - 1; i++)
    {
        curr = curr->next;
    }
    struct Double_Node *temp = curr->next;
    curr->next->prev = curr;
    curr->next = temp->next;
    free(temp);
}

// search and update
void Doubly_search_update(struct Double_Node *head, int search, int update)
{
    struct Double_Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == search)
        {
            curr->data = update;
            printf("search element is found and it is updated\n");
        }
        curr = curr->next;
    }
    printf("search element is not found un the linked list\n");
}

// merge two sorted array
struct Double_Node *merge_two_sorted_array(struct Double_Node *head1, struct Double_Node *head2)
{
    struct Double_Node *curr1 = head1;
    struct Double_Node *curr2 = head2;
    struct Double_Node *head = NULL;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data > curr2->data)
        {
            doubly_insert_end(head, curr2->data);
            curr2 = curr2->next;
        }
        else if (curr1->data < curr2->data)
        {
            doubly_insert_end(head, curr1->data);
            curr1 = curr1->next;
        }
        else
        {
            doubly_insert_end(head, curr2->data);
            curr2 = curr2->next;
            curr1 = curr1->next;
        }
    }
    while (curr1 != NULL)
    {
        doubly_insert_end(head, curr1->data);
        curr1 = curr1->next;
    }
    while (curr2 != NULL)
    {
        doubly_insert_end(head, curr2->data);
        curr2 = curr2->next;
    }
    return head;
}

int main()
{
}