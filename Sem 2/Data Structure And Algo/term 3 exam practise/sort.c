#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode *slow_ptr = head;
    struct ListNode *fast_ptr = head;
    struct ListNode *prev_ptr = NULL;

    while (fast_ptr && fast_ptr->next) {
        prev_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    if (prev_ptr) {
        prev_ptr->next = NULL; // Disconnect the left half of the list
    }

    return slow_ptr;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (!head) {
        return NULL;
    }

    if (!head->next) {
        struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = head->val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    struct ListNode *mid = findMiddle(head);

    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = mid->val;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);

    return root;
}

void printInorder(struct TreeNode* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->val);
        printInorder(root->right);
    }
}

// Function to create a new node in linked list
struct ListNode* newNode(int key) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = key;
    temp->next = NULL;
    return temp;
}

// Function to insert a new node at the beginning of linked list
struct ListNode* push(struct ListNode* head, int key) {
    struct ListNode* temp = newNode(key);
    temp->next = head;
    head = temp;
    return head;
}

// Function to print nodes in a given linked list
void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
}

int main() {
    struct ListNode* head = NULL;
    head = push(head, 9);
    head = push(head, 5);
    head = push(head, 0);
    head = push(head, -3);
    head = push(head, -10);

    printf("Given Linked List: ");
    printList(head);
    printf("\n");

    struct TreeNode* root = sortedListToBST(head);

    printf("Inorder Traversal of constructed BST: ");
    printInorder(root);
    printf("\n");

    return 0;
}
