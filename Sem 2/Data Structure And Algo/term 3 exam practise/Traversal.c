#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* right;
    struct Node* left;
};

struct Node* createNode(int data){
    struct Node*n;
    n = (struct Node *) malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(struct Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int isleaf(struct Node* root){
    if(root->right==NULL && root->left==NULL){
        return 1;
    }
    return 0;
}

void left(struct Node* root){
    if (root) {
        if (root->left || root->right) {
            printf("%d ", root->data);
            if (root->left)
                left(root->left);
            else
                left(root->right);
        }
    }
}

void right(struct Node* root){
    if (root) {
        if (root->right || root->left) {
            if (root->right)
                right(root->right);
            else
                right(root->left);
            printf("%d ", root->data);
        }
    }
}

void printleaf(struct Node* root){
    if(root != NULL){
        if(!isleaf(root)){
            printleaf(root->left);
            printleaf(root->right);
        }
        else{
            printf("%d ",root->data);
        }
    }
}

int height(struct Node* root){
    if(root==NULL){
        return 0;
    }
    int leftheight= height(root->left);
    int rightheight= height(root->right);

    int ans;

    if(leftheight>rightheight){
        ans = leftheight+1;
    }
    else{
        ans = rightheight+1;
    }
    return ans;
}

int isempty(struct Node *arr[], int front, int rear) {
    if (front == -1 || front == rear + 1) {
        return 1; // Queue is empty
    }
    return 0; // Queue is not empty
}


int enqueue(struct Node *arr[], int n, int *front, int *rear, struct Node *data) {
    if (*rear == n - 1) {
        printf("Queue is full\n");
        return 0;
    }
    if (*front == -1) {
        *front = 0;
    }
    *rear = (*rear + 1) % n;
    arr[*rear] = data;
    return 1;
}

struct Node* dequeue(struct Node *arr[], int n, int *front, int *rear) {
    if (*front == -1) {
        printf("Queue is empty\n");
        return NULL;
    }
    struct Node *data = arr[*front];
    if (*front == *rear) {
        *front = -1;
        *rear = -1;
    } else {
        *front = (*front + 1) % n;
    }
    return data;
}

void levelorder(struct Node* root) {
    printf("a");
    if (root == NULL)
        return;
    int n = 50;
    struct Node* queue[50];
    int front = -1;
    int rear = -1;
    enqueue(queue, n, &front, &rear, root);
struct Node* data;
    while (!isempty(queue, front, rear)) {
        
        data = dequeue(queue, n, &front, &rear);
        printf("%d ", data->data);
        if (data->left != NULL) {
            enqueue(queue, n, &front, &rear, data->left);
        }
        if (data->right != NULL) {
            enqueue(queue, n, &front, &rear, data->right);
        }
    }
}

int main(){
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(2);
    //      4
    //     / \ 
    //    1   6
    //   / \
    //  5   2
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    levelorder(p);

    // printf("PreOrder Traversal: ");
    // preorder(p);
    // printf("\nPostOrder Traversal: ");
    // postorder(p);
    // printf("\nInOrder Traversal: ");
    // inorder(p);
    // printf("\nouter element: ");
    // left(p);
    // printleaf(p);
    // right(p);
}