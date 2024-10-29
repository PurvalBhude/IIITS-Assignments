/*
* Name : Purval Madhukar Bhude
* Roll No. S20230010193
* Assignment 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_KEYS 3
#define MIN_KEYS 1

typedef struct TwoFourNode {
    int keys[MAX_KEYS];
    struct TwoFourNode* children[MAX_KEYS + 1];
    int num_keys;
    bool is_leaf;
} TwoFourNode;

typedef struct RBNode {
    int key;
    struct RBNode *left, *right, *parent;
    int color; // 0 for Black, 1 for Red
} RBNode;

//create a new 2-4 Tree node
TwoFourNode* create_24_node() {
    TwoFourNode* new_node = (TwoFourNode*)malloc(sizeof(TwoFourNode));
    new_node->num_keys = 0;
    new_node->is_leaf = true;
    for (int i = 0; i < MAX_KEYS + 1; i++) {
        new_node->children[i] = NULL;
    }
    return new_node;
}

//insert a key
void insert_24_tree(TwoFourNode** root, int key) {
    if (*root == NULL) {
        *root = create_24_node();
        (*root)->keys[0] = key;
        (*root)->num_keys = 1;
    } else {
        if ((*root)->num_keys == MAX_KEYS) {
            TwoFourNode* new_root = create_24_node();
            new_root->is_leaf = false;
            new_root->children[0] = *root;
            split_child(new_root, 0);
            *root = new_root;
        }
        insert_non_full(*root, key);
    }
}

//split a full child during insertion
void split_child(TwoFourNode* parent, int index) {
    TwoFourNode* new_node = create_24_node();
    TwoFourNode* child = parent->children[index];
    new_node->is_leaf = child->is_leaf;
    new_node->num_keys = MIN_KEYS;

    for (int j = 0; j < MIN_KEYS; j++) {
        new_node->keys[j] = child->keys[j + MIN_KEYS + 1];
    }

    if (!child->is_leaf) {
        for (int j = 0; j <= MIN_KEYS; j++) {
            new_node->children[j] = child->children[j + MIN_KEYS + 1];
        }
    }

    child->num_keys = MIN_KEYS;

    for (int j = parent->num_keys; j > index; j--) {
        parent->children[j + 1] = parent->children[j];
    }
    parent->children[index + 1] = new_node;

    for (int j = parent->num_keys - 1; j >= index; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[index] = child->keys[MIN_KEYS];
    parent->num_keys++;
}

//insert a key into a non-full node
void insert_non_full(TwoFourNode* node, int key) {
    int i = node->num_keys - 1;

    if (node->is_leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->num_keys++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;
        if (node->children[i]->num_keys == MAX_KEYS) {
            split_child(node, i);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insert_non_full(node->children[i], key);
    }
}

//create a new Red-Black Tree node
RBNode* create_rb_node(int key) {
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    node->key = key;
    node->left = node->right = node->parent = NULL;
    node->color = 1;
    return node;
}

//convert 2-4 Tree to Red-Black Tree
RBNode* convert_24tree_to_rbtree(TwoFourNode* node) {
    if (node == NULL) return NULL;

    RBNode* rb_node = create_rb_node(node->keys[0]);
    rb_node->color = 0; // Root is always black

    if (!node->is_leaf) {
        rb_node->left = convert_24tree_to_rbtree(node->children[0]);
        if (rb_node->left) rb_node->left->parent = rb_node;

        if (node->num_keys > 1) {
            RBNode* right_child = create_rb_node(node->keys[1]);
            rb_node->right = right_child;
            right_child->parent = rb_node;
            right_child->left = convert_24tree_to_rbtree(node->children[1]);
            if (right_child->left) right_child->left->parent = right_child;
            right_child->right = convert_24tree_to_rbtree(node->children[2]);
            if (right_child->right) right_child->right->parent = right_child;

            if (node->num_keys == 3) {
                RBNode* far_right = create_rb_node(node->keys[2]);
                right_child->right = far_right;
                far_right->parent = right_child;
                far_right->left = convert_24tree_to_rbtree(node->children[2]);
                if (far_right->left) far_right->left->parent = far_right;
                far_right->right = convert_24tree_to_rbtree(node->children[3]);
                if (far_right->right) far_right->right->parent = far_right;
            }
        }
    }

    return rb_node;
}

//maximum path sum in the Red-Black Tree
int find_max_path_sum(RBNode* root) {
    if (root == NULL) return 0;
    int left_sum = find_max_path_sum(root->left);
    int right_sum = find_max_path_sum(root->right);
    return root->key + (left_sum > right_sum ? left_sum : right_sum);
}

//count Black and Red nodes in the Red-Black Tree
void count_br_nodes(RBNode* root, int* black_count, int* red_count) {
    if (root == NULL) return;
    if (root->color == 0) (*black_count)++;
    else (*red_count)++;
    count_br_nodes(root->left, black_count, red_count);
    count_br_nodes(root->right, black_count, red_count);
}

//find the minimum node in a subtree
RBNode* find_min(RBNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

//Red-Black Tree deletion
void rb_transplant(RBNode** root, RBNode* u, RBNode* v) {
    if (u->parent == NULL) {
        *root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}

//delete a node from the Red-Black Tree
RBNode* delete_rb_tree(RBNode* root, int key) {
    RBNode* z = root;
    while (z != NULL) {
        if (key < z->key) {
            z = z->left;
        } else if (key > z->key) {
            z = z->right;
        } else {
            break;
        }
    }

    if (z == NULL) return root;

    RBNode* y = z;
    RBNode* x;
    int y_original_color = y->color;

    if (z->left == NULL) {
        x = z->right;
        rb_transplant(&root, z, z->right);
    } else if (z->right == NULL) {
        x = z->left;
        rb_transplant(&root, z, z->left);
    } else {
        y = find_min(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            if (x != NULL) x->parent = y;
        } else {
            rb_transplant(&root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rb_transplant(&root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (y_original_color == 0) {
        delete_fixup(&root, x);
    }

    return root;
}

//function after deletion to maintain Red-Black properties
void delete_fixup(RBNode** root, RBNode* x) {
    while (x != *root && x->color == 0) {
        if (x == x->parent->left) {
            RBNode* w = x->parent->right;
            if (w->color == 1) {
                w->color = 0;
                x->parent->color = 1;
                left_rotate(root, x->parent);
                w = x->parent->right;
            }
            if ((w->left == NULL || w->left->color == 0) &&
                (w->right == NULL || w->right->color == 0)) {
                w->color = 1;
                x = x->parent;
            } else {
                if (w->right == NULL || w->right->color == 0) {
                    w->left->color = 0;
                    w->color = 1;
                    right_rotate(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 0;
                if (w->right) w->right->color = 0;
                left_rotate(root, x->parent);
                x = *root;
            }
        } else {
            RBNode* w = x->parent->left;
            if (w->color == 1) {
                w->color = 0;
                x->parent->color = 1;
                right_rotate(root, x->parent);
                w = x->parent->left;
            }
            if ((w->left == NULL || w->left->color == 0) &&
                (w->right == NULL || w->right->color == 0)) {
                w->color = 1;
                x = x->parent;
            } else {
                if (w->left == NULL || w->left->color == 0) {
                    w->right->color = 0;
                    w->color = 1;
                    left_rotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 0;
                if (w->left) w->left->color = 0;
                right_rotate(root, x->parent);
                x = *root;
            }
        }
    }
    if (x) x->color = 0;
}

//left rotate a subtree rooted with x
void left_rotate(RBNode** root, RBNode* x) {
    RBNode* y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

//right rotate a subtree rooted with y
void right_rotate(RBNode** root, RBNode* y) {
    RBNode* x = y->left;
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL) {
        *root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}

//check if a tree is a valid Red-Black Tree
bool is_valid_red_black_tree(RBNode* root) {
    if (root == NULL) return true;
    if (root->color == 1) {
        if ((root->left && root->left->color == 1) ||
            (root->right && root->right->color == 1)) {
            return false;
        }
    }
    int left_black_height = black_height(root->left);
    int right_black_height = black_height(root->right);
    if (left_black_height != right_black_height) {
        return false;
    }
    return is_valid_red_black_tree(root->left) &&
           is_valid_red_black_tree(root->right);
}

// calculate Black Height
int black_height(RBNode* node) {
    if (node == NULL) return 1;
    int left_black_height = black_height(node->left);
    int right_black_height = black_height(node->right);
    if (left_black_height == 0 || right_black_height == 0 ||
        left_black_height != right_black_height) {
        return 0;
    }
    return left_black_height + (node->color == 0 ? 1 : 0);
}

int main() {
    TwoFourNode* root24 = NULL;
    insert_24_tree(&root24, 10);
    insert_24_tree(&root24, 20);
    insert_24_tree(&root24, 5);
    insert_24_tree(&root24, 30);
    insert_24_tree(&root24, 15);

    // part a
    RBNode* rb_root = convert_24tree_to_rbtree(root24);
    int max_sum = find_max_path_sum(rb_root);
    printf("Maximum Path Sum in the Red-Black Tree: %d\n", max_sum);

    // part b
    int black_count = 0, red_count = 0;
    count_br_nodes(rb_root, &black_count, &red_count);
    printf("Number of Black nodes: %d\n", black_count);
    printf("Number of Red nodes: %d\n", red_count);

    // part c
    rb_root = delete_rb_tree(rb_root, 15);
    printf("Deleted node 15 from Red-Black Tree.\n");

    if (is_valid_red_black_tree(rb_root)) {
        printf("The Red-Black Tree is valid.\n");
    } else {
        printf("The Red-Black Tree is invalid.\n");
    }
    return 0;
}
