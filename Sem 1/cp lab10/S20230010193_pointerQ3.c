#include <stdio.h>
void reverse(int* arr,int n){
    int left=0,right=n-1;
    while(left<right){
        arr[left]= arr[left] ^ arr[right];
        arr[right]= arr[left] ^ arr[right];
        arr[left]= arr[left] ^ arr[right];
        right--;
        left++;
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    reverse(arr,10);
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}