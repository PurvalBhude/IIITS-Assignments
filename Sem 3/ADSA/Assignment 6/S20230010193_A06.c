/*
* Name : Purval Madhukar Bhude
* Roll No. S20230010193
* Subject : ADSA
* Assginment 6
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

// B+ Tree
typedef struct BPNode {
    int *keys;
    struct BPNode **ptrs;
    struct BPNode *parent;
    bool is_leaf;
    int num_keys;
    struct BPNode *next;
} BPNode;

BPNode *bp_root = NULL;
int bp_order = 3;

// Red-Black Tree
typedef struct RBNode {
    int key;
    char color;
    struct RBNode *left, *right, *parent;
} RBNode;

RBNode *rb_root = NULL;

// B+ Tree functions
BPNode* create_bp_node() {
    BPNode *n = malloc(sizeof(BPNode));
    n->keys = malloc(sizeof(int) * (bp_order - 1));
    n->ptrs = malloc(sizeof(BPNode*) * bp_order);
    n->is_leaf = true;
    n->num_keys = 0;
    n->parent = n->next = NULL;
    return n;
}

void bp_insert(int key) {
    if (!bp_root) {
        bp_root = create_bp_node();
        bp_root->keys[0] = key;
        bp_root->num_keys++;
        return;
    }
    
    BPNode *leaf = bp_root;
    while (!leaf->is_leaf)
        leaf = leaf->ptrs[0];
    
    if (leaf->num_keys < bp_order - 1) {
        int i = leaf->num_keys - 1;
        while (i >= 0 && leaf->keys[i] > key) {
            leaf->keys[i+1] = leaf->keys[i];
            i--;
        }
        leaf->keys[i+1] = key;
        leaf->num_keys++;
    } else {
        BPNode *new_leaf = create_bp_node();
        int temp_keys[bp_order];
        for (int i = 0; i < bp_order - 1; i++)
            temp_keys[i] = leaf->keys[i];
        int i = bp_order - 2;
        while (i >= 0 && temp_keys[i] > key) {
            temp_keys[i+1] = temp_keys[i];
            i--;
        }
        temp_keys[i+1] = key;
        leaf->num_keys = (bp_order) / 2;
        new_leaf->num_keys = bp_order - (bp_order / 2);
        for (int i = 0; i < leaf->num_keys; i++)
            leaf->keys[i] = temp_keys[i];
        for (int i = 0; i < new_leaf->num_keys; i++)
            new_leaf->keys[i] = temp_keys[i + leaf->num_keys];
        new_leaf->next = leaf->next;
        leaf->next = new_leaf;
        new_leaf->parent = leaf->parent;
        if (!leaf->parent) {
            BPNode *new_root = create_bp_node();
            new_root->keys[0] = new_leaf->keys[0];
            new_root->ptrs[0] = leaf;
            new_root->ptrs[1] = new_leaf;
            new_root->num_keys = 1;
            new_root->is_leaf = false;
            bp_root = new_root;
            leaf->parent = new_leaf->parent = new_root;
        } else {
            // Insert in parent (recursive split if needed)
        }
    }
}

void bp_delete(int key) {
    // TODO: Implement B+ Tree deletion
}

void bp_print(BPNode *n, int level) {
    if (!n) return;
    for (int i = 0; i < level; i++) printf("  ");
    for (int i = 0; i < n->num_keys; i++)
        printf("%d ", n->keys[i]);
    printf("\n");
    if (!n->is_leaf)
        for (int i = 0; i <= n->num_keys; i++)
            bp_print(n->ptrs[i], level + 1);
}

// Red-Black Tree functions
RBNode* create_rb_node(int key) {
    RBNode *n = malloc(sizeof(RBNode));
    n->key = key;
    n->color = 'R';
    n->left = n->right = n->parent = NULL;
    return n;
}

void left_rotate(RBNode *x) {
    RBNode *y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->parent = x->parent;
    if (!x->parent) rb_root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void right_rotate(RBNode *y) {
    RBNode *x = y->left;
    y->left = x->right;
    if (x->right) x->right->parent = y;
    x->parent = y->parent;
    if (!y->parent) rb_root = x;
    else if (y == y->parent->right) y->parent->right = x;
    else y->parent->left = x;
    x->right = y;
    y->parent = x;
}

void rb_insert_fixup(RBNode *z) {
    while (z->parent && z->parent->color == 'R') {
        if (z->parent == z->parent->parent->left) {
            RBNode *y = z->parent->parent->right;
            if (y && y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    left_rotate(z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                right_rotate(z->parent->parent);
            }
        } else {
            RBNode *y = z->parent->parent->left;
            if (y && y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    right_rotate(z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                left_rotate(z->parent->parent);
            }
        }
    }
    rb_root->color = 'B';
}

void rb_insert(int key) {
    RBNode *z = create_rb_node(key);
    RBNode *y = NULL;
    RBNode *x = rb_root;
    while (x) {
        y = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->parent = y;
    if (!y) rb_root = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z;
    rb_insert_fixup(z);
}

void rb_print(RBNode *root, int space) {
    if (!root) return;
    space += 10;
    rb_print(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++) printf(" ");
    printf("%d%c\n", root->key, root->color);
    rb_print(root->left, space);
}

RBNode* create_max_height_rb_tree(int n) {
    if (n <= 0) return NULL;
    RBNode *root = create_rb_node(n);
    root->color = 'B';
    if (n > 1) {
        root->left = create_max_height_rb_tree(n - 1);
        root->left->parent = root;
    }
    return root;
}

int main() {
    int choice, key, n;
    while (1) {
        printf("\n1. B+ Tree Insert\n2. B+ Tree Delete\n3. B+ Tree Print\n");
        printf("4. RB Tree Insert\n5. RB Tree Max Height\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert in B+ Tree: ");
                scanf("%d", &key);
                bp_insert(key);
                break;
            case 2:
                printf("Enter key to delete from B+ Tree: ");
                scanf("%d", &key);
                bp_delete(key);
                break;
            case 3:
                bp_print(bp_root, 0);
                break;
            case 4:
                printf("Enter key to insert in RB Tree: ");
                scanf("%d", &key);
                rb_insert(key);
                break;
            case 6:
                printf("Enter n for max height RB Tree: ");
                scanf("%d", &n);
                rb_root = create_max_height_rb_tree(n);
                rb_print(rb_root, 0);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}