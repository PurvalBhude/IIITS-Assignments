#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int data;
    struct Node *prev;
};

struct NodeBST
{
    int data;
    struct NodeBST *left, *right;
};

// if return 0 means not a max heap
// if return 1 means max heap
int checkmaxheap(int arr[], int n)
{
    for (int i = 0; i <= (n - 2) / 2; i++)
    {
        // Check left child
        if (arr[2 * i + 1] > arr[i])
            return 0;

        // Check right child (if it exists)
        if (2 * i + 2 < n && arr[2 * i + 2] > arr[i])
            return 0;
    }
    return 1;
}

// Function to create a new binary tree node
struct NodeBST *createNode(int value)
{
    struct NodeBST *newNode = (struct NodeBST *)malloc(sizeof(struct NodeBST));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform inorder traversal of BST and store elements in an array
void inorderTraversal(struct NodeBST *root, int arr[], int *index)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, arr, index);
    arr[*index] = root->data;
    (*index)++;
    inorderTraversal(root->right, arr, index);
}

// Function to convert a sorted array into a min heap
void arrayToMinHeap(int arr[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        int parent = i;
        while (2 * parent + 1 < n)
        {
            int leftChild = 2 * parent + 1;
            int rightChild = 2 * parent + 2;
            int smallest = parent;
            if (leftChild < n && arr[leftChild] < arr[smallest])
            {
                smallest = leftChild;
            }
            if (rightChild < n && arr[rightChild] < arr[smallest])
            {
                smallest = rightChild;
            }
            if (smallest != parent)
            {
                int temp = arr[parent];
                arr[parent] = arr[smallest];
                arr[smallest] = temp;
                parent = smallest;
            }
            else
            {
                break;
            }
        }
    }
}

// Function to convert BST to min heap
void BSTtoMinHeap(struct NodeBST *root)
{
    if (root == NULL)
        return;

    int n = 0;
    int arr[100];
    inorderTraversal(root, arr, &n);
    arrayToMinHeap(arr, n);
    printf("Min Heap: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

struct Node *insertatend(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void swapLinkedListElement(struct Node *element1, struct Node *element2)
{
    int c = element1->data;
    element1->data = element2->data;
    element2->data = c;
}
// Function to perform bubble sort on a doubly linked list
struct Node *bubblesortinlinkedlist(struct Node *head, int n)
{
    int swapped;
    struct Node *tempi = head;
    struct Node *tempj = head;

    for (int i = 0; i < n - 1; i++)
    {
        tempj = head;
        swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (tempj->data > tempj->next->data)
            {
                swapLinkedListElement(tempj, tempj->next);
                swapped = 1;
            }
            tempj = tempj->next;
        }

        if (swapped == 0)
        {
            break;
        }

        tempi = tempi->next;
    }

    return head;
}

void insertionSort(int arr[], int n)
{
    int camparison = 0;
    int j, key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            camparison++;
        }
        arr[j + 1] = key;
    }
    printf("%d camparision required\n", camparison);
}

void main()
{
    printf("print which question to run: ");
    int question;
    scanf("%d", &question);
    if (question == 1)
    {
        // Question 1
        printf("enter nuumber of elements that you have to enter: ");
        int n;
        scanf("%d", &n);
        int arr[n];
        printf("enter elements in array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int answer = checkmaxheap(arr, n);
        if (answer == 0)
        {
            printf("not a max heap");
        }
        else
        {
            printf("it is max heap");
        }
    }

    if (question == 2)
    {
        // Question 2
        struct NodeBST *root = createNode(5);
        root->left = createNode(3);
        root->right = createNode(8);
        root->left->left = createNode(2);
        root->left->right = createNode(4);
        root->right->left = createNode(6);
        root->right->right = createNode(10);

        BSTtoMinHeap(root);
        printf("BST converted to minHeap");
    }

    if (question == 3)
    {
        // Question 3
        printf("enter number of element you have to enter in linked list: ");
        int n;
        scanf("%d", &n);
        printf("enter element: ");
        int data;
        struct Node *head = NULL;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &data);
            head = insertatend(head, data);
        }
        printf("your inserted list is: ");
        struct Node *temp = head;
        for (int i = 0; i < n; i++)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
        head = bubblesortinlinkedlist(head, n);
        temp = head;
        printf("after sorting linked list: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }

    if (question == 4)
    {
        // Question 4
        printf("enter number of element you have to enter in array: ");
        int n;
        scanf("%d", &n);
        printf("enter element: ");
        int arr[n];
        printf("enter elements in array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("your entered array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        insertionSort(arr, n);
        printf("your array after insertion sort: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}