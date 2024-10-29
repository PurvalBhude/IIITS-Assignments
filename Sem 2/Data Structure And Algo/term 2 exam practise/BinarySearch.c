#include <stdio.h>
#include <stdlib.h>

int bs(int *arr,int n,int key){
    int front = 0,mid;
    int rear = n-1;
    while(front<=rear){
        mid = (front+rear)/2;
        if(arr[mid]>key){
            rear = mid-1;
        }
        else if(arr[mid]<key){
            front = mid+1;
        }
        else{
            printf("%d\n",mid);
            return mid;
        }
    }
    printf("key not found\n");
    return -1;
}

int main(){
    int n = 10;
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    bs(arr,n,90);
    bs(arr,n,10);
    bs(arr,n,100258);
    return 0;   
}