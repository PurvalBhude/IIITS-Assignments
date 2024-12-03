#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node * init(){
    struct Node* a = (struct Node* ) malloc(sizeof(struct Node));
    a->val = 0;
    a->left = NULL;
    a->right = NULL;
    return a;
}

struct Node* minimumnodeavl(int height){
    if(height<=0){
        return NULL;
    }
    struct Node* ans = init();
    printf("%d\n",height);
    ans->left = minimumnodeavl(height-1);
    ans->right = minimumnodeavl(height-2);
    return ans;
}

void traversal(struct Node* a){
    if(a==NULL) return;
    traversal(a->left);
    printf("%d ",a->val);
    traversal(a->right);
}

int main(){
    struct Node* ans = minimumnodeavl(5);

    traversal(ans);
}