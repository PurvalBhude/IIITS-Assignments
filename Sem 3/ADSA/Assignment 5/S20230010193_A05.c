/*
* Name: Purval Madhukar Bhude
* Roll No. S20230010193
*/

#include <stdio.h>
#include <stdlib.h>

struct Tree{
    int val;
    struct Tree *right;
    struct Tree *left;
};

int max(int l,int r){
    if(l>r){
        return l;
    }
    else{
        return r;
    }
}

int maxheight(struct Tree *node)
{
    if (node == NULL)
        return 0;

    int l = maxheight(node->left);
    int r = maxheight(node->right);
    return max(l, r) + 1;
}

void ValidAVL(struct Tree *node){
    int right = 0;
    int left = 0;

    if(node == NULL){
        return;
    }

    if(node->right != NULL){
        right = maxheight(node->right);
    }
    if(node->left != NULL){
        left = maxheight(node->left);
    }
    
    int balance = right - left;
    
    if(balance > -2 && balance < 2){
        ValidAVL(node->right);
        ValidAVL(node->left);
    }
    else{
        printf("AVL tree not valid\n");
        exit(0);
    }
}

struct Tree* newNode(int val) {
    struct Tree* node = (struct Tree*)malloc(sizeof(struct Tree));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Tree* insert(struct Tree* node, int key) {
    if (node == NULL)
        return newNode(key);
    if (node->val == key)
        return node;
    if (node->val < key)
        node->right = insert(node->right, key);
    else
        node->left = insert(node->left, key);
    return node;
}

int inorder[15];
int i=0;
void Inorder(struct Tree* node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    inorder[i]=node->val;
    i++;
    Inorder(node->right);
}
int count(struct Tree *node,int a,int b){
    Inorder(node);
    int count = 0;
    for(int j=0;j<i;j++){
        if(inorder[j]>=a){
            count++;
        }
        if(inorder[j]==b){
            break;
        }
    }
    return count;
}

struct Tree* getSuccessor(struct Tree *root){
    for(int j=0;j<i;j++){
        if(root->val==inorder[j]){
            return inorder[j+1];
        }
    }
    return 0;
}

struct Tree* deltree(struct Tree* root, int x)
{
    if (root == NULL)
        return root;
    if (root->val > x)
        root->left = deltree(root->left, x);
    else if (root->val < x)
        root->right = deltree(root->right, x);

    else {
        if (root->left == NULL) {
            struct Tree* temp = root->right;
            return temp;
        }
        if (root->right == NULL) {
            struct Tree* temp = root->left;
            return temp;
        }
        struct Tree* succ = getSuccessor(root);
        root->val = succ->val;
        root->right = deltree(root->right, succ->val);
    }
    return root;
}

int main(){


    // Question 1 a)
    struct Tree* root = newNode(5);
    
    root->left = newNode(3);
    root->right = newNode(10);
    
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    
    root->left->left->left = newNode(1);
    
    root->right->left = newNode(7);
    root->right->right = newNode(11);
    
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(9);
    
    root->right->left->left->right = newNode(8);
    
    root->right->right->right = newNode(12);

    ValidAVL(root);
    printf("AVL tree is valid\n");
    
    //Question 1 b)
    int a,b;
    printf("Enter a: ");
    scanf("%d",&a);
    printf("Enter b: ");
    scanf("%d",&b);

    printf("the number of nodes: %d",count(root,a,b));

    //Question 1 c)
    printf("enter number of element you want to delete");
    int del;
    int delete;
    scanf("%d",&del);
    for(int k=0;k<del;k++){
        printf("enter deleting element: ");
        scanf("%d",&delete);
        deltree(root,delete);
        printf("deleted!!!\n");
    }

    //Question 2 
    printf("Enter number of nodes to be inserted");
    int ele;
    scanf("%d",&ele);
    root = NULL;
    int element;
    for(int j=0;j<ele;j++){
        printf("enter the element you want to insert: ");
        scanf("%d",&element);
        insert(root,element);
        printf("Inserted!!!\n");
    }
}