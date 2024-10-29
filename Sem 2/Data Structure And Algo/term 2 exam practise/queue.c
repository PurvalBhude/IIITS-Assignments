#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int isfull(int *front,int *rear,int n){
    if((*rear)==n-1){
        return 1;
    }
    return 0;
}

int isempty(int *front,int *rear,int n){
    if((*front)>(*rear)){
        return 1;
    }
    return 0;
}

int enqueue(int *arr,int *front,int *rear,int n){
    if(isfull(front,rear,n)){
        printf("it can't be enqueued\n");
        return 0;
    }
    int data;
    printf("enter data to be enqueued: ");
    scanf("%d",&data);
    (*rear) = (*rear)+1;
    arr[(*rear)] = data;
    return 1;
}

int dequeue(int *arr,int *front,int *rear,int n){
    if(isempty(&front,&rear,n)){
        printf("array is empty no dequeue possible\n");
    }
    printf("dequeued element is %d",arr[(*front)]);
    *front = *front +1;
    return 1;
}

int peek(int *arr,int front){
    return arr[front];
}

int main(){
    int queue[5];
    int front=-1,rear=-1;
    enqueue(queue,&front,&rear,5);
}