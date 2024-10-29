#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a node in the binary search tree
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

// Function to create a new node with the given value
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// Function to find the maximum value in a subtree
int maxValue(struct Node *node)
{
    if (node == NULL)
    {
        return INT_MIN;
    }

    int value = node->data;
    int leftMax = maxValue(node->left);
    int rightMax = maxValue(node->right);

    return max(value, max(leftMax, rightMax));
}

// Function to find the minimum value in a subtree
int minValue(struct Node *node)
{
    if (node == NULL)
    {
        return INT_MAX;
    }

    int value = node->data;
    int leftMin = minValue(node->left);
    int rightMin = minValue(node->right);

    return min(value, min(leftMin, rightMin));
}

// Function to check if a tree is a binary search tree (BST)
int isBST(struct Node *node)
{
    if (node == NULL)
    {
        return 1;
    }

    if (node->left != NULL && (maxValue(node->left) >= node->data))
    {
        return 0;
    }

    if (node->right != NULL && (minValue(node->right) <= node->data))
    {
        return 0;
    }

    if (!isBST(node->left) || !isBST(node->right))
    {
        return 0;
    }

    return 1;
}

// Function to print the tree in inorder traversal
void printInorder(struct Node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    printf("%d ", node->data);

    printInorder(node->right);
}

// Function to print the tree in preorder traversal
void printPreOrder(struct Node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);

    printPreOrder(node->left);

    printPreOrder(node->right);
}

// Function to print the tree in postorder traversal
void printPostOrder(struct Node *node)
{
    if (node == NULL)
        return;

    printPostOrder(node->left);

    printPostOrder(node->right);

    printf("%d ", node->data);
}

// Function to insert a new node into the BST
struct Node *Insert(struct Node *root, int value)
{
    if (!root)
    {
        struct Node *temp;
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if (value > root->data)
    {
        root->right = Insert(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = Insert(root->left, value);
    }
    return root;
}

// Function to create a mirror image of the tree
struct Node *mirrorimage(struct Node *root)
{
    struct Node *node = root;
    if (node == NULL)
        return root;
    else
    {
        struct Node *temp;

        mirrorimage(node->left);
        mirrorimage(node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

//// Function to remove element from the tree
struct Node *removeNode(struct Node *root, int val)
{
    if (root == NULL)
        return root;

    if (root->data > val)
    {
        root->left = removeNode(root->left, val);
        return root;
    }
    else if (root->data < val)
    {
        root->right = removeNode(root->right, val);
        return root;
    }

    if (root->left == NULL)
    {
        struct Node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        struct Node *temp = root->left;
        free(root);
        return temp;
    }
    else
    {
        struct Node *temp2 = root;
        struct Node *temp1 = root->right;
        while (temp1->left != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->left;
        }

        if (temp2 != root)
            temp2->left = temp1->right;
        else
            temp2->right = temp1->right;

        root->data = temp1->data;

        free(temp1);
        return root;
    }
}

void fillArrayInorder(struct Node *node, int *arr, int *i)
{
    if (node == NULL)
        return;

    fillArrayInorder(node->left, arr, i);
    arr[(*i)++] = node->data;
    fillArrayInorder(node->right, arr, i);
}

int countNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void median(struct Node *root)
{
    int size = countNodes(root);
    int *arr = (int *)malloc(size * sizeof(int));
    int index = 0;
    fillArrayInorder(root, arr, &index);

    int median;
    if (size % 2 == 0)
    {
        median = (arr[size / 2] + arr[(size / 2) - 1]) / 2;
    }
    else
    {
        median = arr[size / 2];
    }

    printf("After inserting, the median is: %d\n", median);
    free(arr);
}

// Function to find ancestor in binary search tree
void find_ancestor(struct Node *root, int target, int ancestor)
{
    if (root == NULL)
        return;

    if (root->data == target)
    {
        printf("Ancestor of %d is %d\n", target, ancestor);
    }
    else
    {
        find_ancestor(root->left, target, root->data);
        find_ancestor(root->right, target, root->data);
    }
}

int main()
{
    // Question 1
    // a)
    struct Node *root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(7);
    root->right->right = newNode(11);
    root->left->left->left = newNode(1);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(9);
    root->right->right->right = newNode(12);
    root->right->left->right->left = newNode(8);
    printf("given Tree Constructed!!!\n");
    int answer = isBST(root);
    if (answer == 1)
    {
        printf("the tree is BST\n");
    }
    else
    {
        printf("the tree is not BST\n");
    }

    // b)
    printf("printing Inorder: ");
    printInorder(root);
    printf("\nprinting preorder: ");
    printPreOrder(root);
    printf("\nprinting postorder: ");
    printPostOrder(root);

    // c)
    printf("\nmirror image of tree\n");
    struct Node *newroot = mirrorimage(root);
    printf("mirror image is done and root pointer saved in newroot\n");

    // d)
    printf("removing root element\n");
    root = removeNode(root, root->data);
    printf("new root element is %d\n", root->data);

    // Question 2
    printf("enter the number whose ansester you have to find: ");
    int number;
    scanf("%d", &number);
    find_ancestor(root, number, 0);

    // Question 3
    int size;
    printf("Enter Number of element to insert: ");
    scanf("%d", &size);
    int data;
    root = NULL;
    printf("insert element: ");
    for (int i = 1; i <= size; i++)
    {
        scanf("%d", size);
        root = Insert(root, data);
        median(root);
    }
}