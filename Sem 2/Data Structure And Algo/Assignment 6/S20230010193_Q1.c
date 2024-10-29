#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *child;
} Node;

// Function to create a new node
Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->child = NULL;
    return node;
}

// Function to flatten the linked list
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

// Function to print the linked list
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

int main()
{
    Node *head = newNode(1);
    head->next = newNode(6);
    head->next->next = newNode(3);
    head->next->next->next = newNode(5);
    head->next->next->next->next = newNode(5);

    head->child = newNode(2);
    head->child->next = newNode(9);
    head->child->next->next = newNode(0);

    head->next->next->child = newNode(19);
    head->next->next->child->next = newNode(3);

    printf("Original List:\n");
    printList(head);

    //a) one pointer
    head = one_pointer(head);

    printf("one pointer List:\n");
    printList(head);

    //b) sort array
    int n = sizeoflist(head);
    int arr[n];
    Node *curr = head;
    for(int i=0;i<n;i++){
        arr[i] = curr->data;
        curr = curr->next;
    }

    sort(arr,n);
    curr = head;
    for(int i=0;i<n;i++){
        curr->data = arr[i];
        curr = curr->next;
    }

    printf("sorted list\n");
    printList(head);

    return 0;
}
