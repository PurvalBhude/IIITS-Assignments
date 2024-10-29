#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

// create newnode
struct Node *CreateNode(int key)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// recursive solution
struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }

    /*otherwise recure down the tree*/

    if (key < root->data)
        root->left = insert(root->left, key);

    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

// iterative solution
struct Node *insert(struct Node *root, int key)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("can't insert as it is already present in BST\n");
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->left;
        }
    }
    struct Node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

// recursive way
struct Node *search(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

// itrative way
struct Node *search(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (root->data > key)
        {
            root = root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

// deletion
struct Node *delete(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    // find node to be deleted
    if (key < root->data)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        // if the node is with only one child or no child
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

        // if the node has two children
        struct Node *temp = minvaluenode(root->right);

        // place the inorder successor in position of the node to be deleted
        root->data = temp->data;

        // delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
} 

int main()
{
}