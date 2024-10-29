#include <stdio.h>
#include <stdlib.h>



// Q1
struct Node
{
    int data;
    struct Node *next;
};

void printlist(struct Node * head){
    struct Node* curr = head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

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
    for (int i = 0; i < position - 1 && (curr->next != NULL); i++)
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

// Q2
struct Double_Node
{
    struct Double_Node *prev;
    int data;
    struct Double_Node *next;
};

void doubly_printlist(struct Double_Node * head){
    struct Double_Node* curr = head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

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
    for (int i = 0; i < position - 1 && (curr->next != NULL); i++)
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
    for (int i = 0; i < position - 1 && (curr->next != NULL); i++)
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

// Q3
/*in this question first element will show value of x^0 second element will show value of x^1 and so on....
ex. if f(x) = x^4 - 4x^2 + 5x -8  .
    in linked list it will be -8 -> 5 -> -4 -> 1*/

struct Node *Addition(struct Node *head1, struct Node *head2)
{
    struct Node *curr1 = head1;
    struct Node *curr2 = head2;
    int add;
    struct Node *head = NULL;
    while (curr1 != NULL && curr2 != NULL)
    {
        add = curr1->data + curr2->data;
        insert_end(head, add);
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    while (curr1 != NULL)
    {
        insert_end(head, curr1->data);
        curr1 = curr1->next;
    }
    while (curr2 != NULL)
    {
        insert_end(head, curr2->data);
        curr2 = curr2->next;
    }
    return head;
}

struct Node *subtraction(struct Node *head1, struct Node *head2)
{
    struct Node *curr1 = head1;
    struct Node *curr2 = head2;
    int sub;
    struct Node *head = NULL;
    while (curr1 != NULL && curr2 != NULL)
    {
        sub = curr1->data - curr2->data;
        insert_end(head, sub);
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    while (curr1 != NULL)
    {
        insert_end(head, curr1->data);
        curr1 = curr1->next;
    }
    while (curr2 != NULL)
    {
        insert_end(head, -(curr2->data));
        curr2 = curr2->next;
    }
    return head;
}

int main()
{
    // //Q1
    // struct Node* head = NULL;
    // insert_begin(head,5);
    // insert_end(head,1);
    // insert_position(head,2,8);
    // delete(head,0);
    // cycle_detection(head);

    // //Q2
    // struct Double_Node* doubly_head = NULL;
    // doubly_insert_begin(doubly_head,5);
    // doubly_insert_end(doubly_head,5);
    // doubly_insert_position(doubly_head,2,4);
    // Doubly_search_update(doubly_head,5,4);
    // doubly_delete_position(doubly_delete_position,2);    
    // doubly_delete_begin(doubly_head);
    // doubly_delete_end(doubly_head);
    
}