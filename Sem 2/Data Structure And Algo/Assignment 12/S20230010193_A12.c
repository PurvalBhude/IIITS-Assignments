#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Appends a node to the end of a linked list
void Append(struct Node **headRef, struct Node **tailRef, struct Node *newNode)
{
    if (*headRef == NULL)
    {
        *headRef = newNode;
    }
    else
    {
        (*tailRef)->next = newNode;
    }
    *tailRef = newNode;
}

// Joins two linked lists
void Join(struct Node **head1Ref, struct Node **tail1Ref, struct Node *head2, struct Node *tail2)
{
    if (*head1Ref == NULL)
    {
        *head1Ref = head2;
    }
    else
    {
        (*tail1Ref)->next = head2;
    }
    *tail1Ref = tail2;
}

// Partitions the list into nodes less than, equal to, and greater than the pivot
// Returns the pivot node after partitioning
struct Node *partition(struct Node *head, struct Node *tail, struct Node **less, struct Node **equal, struct Node **greater)
{
    struct Node *pivot = head;
    struct Node *current = head->next;

    // Initialize less, equal, and greater to NULL
    *less = *equal = *greater = NULL;

    while (current != tail->next)
    {
        struct Node *nextNode = current->next;
        if (current->data < pivot->data)
        {
            Append(less, equal, current);
        }
        else if (current->data == pivot->data)
        {
            Append(equal, equal, current);
        }
        else
        {
            Append(greater, equal, current); // Append to greater, not equal
        }
        current = nextNode;
    }

    return pivot;
}


// Performs modified quick sort on a singly linked list
void quickSort(struct Node **headRef, struct Node **tailRef)
{
    struct Node *head = *headRef;
    struct Node *tail = *tailRef;

    // Base case: If list is empty or contains only one node
    if (head == NULL || head == tail)
    {
        return;
    }

    // Initialize less, equal, and greater lists
    struct Node *less = NULL;
    struct Node *equal = head;
    struct Node *greater = NULL;

    // Partition the list and get the pivot
    struct Node *pivot = partition(head, tail, &less, &equal, &greater);

    // Recursively sort less and greater lists
    quickSort(&less, tailRef);
    quickSort(&greater, tailRef);

    // Join the sorted less, equal, and greater lists
    *headRef = *tailRef = NULL;
    Join(headRef, tailRef, less, equal);
    Join(headRef, tailRef, equal, greater);
}

// Displays the linked list
void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Driver program
int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;

    printf("enter number of element you want to enter: ");
    int size;
    scanf("%d", &size);

    // Create linked list
    printf("enter the element: ");
    int da;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &da);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = da;
        newNode->next = NULL;
        Append(&head, &tail, newNode);
    }

    printf("Before Sort: ");
    display(head);

    // Sort the list
    quickSort(&head, &tail);

    printf("After Sort: ");
    display(head);

    return 0;
}