#include <stdio.h>

//a[] is input array and n is size of array
void reverse(int a[],int n){
    for(int i=0;i<n-i-1;i++){
        a[i] = a[i]^a[n-i-1];
        a[n-i-1] = a[i]^a[n-i-1];
        a[i] = a[i]^a[n-i-1];
    }

    //printing reverse array
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    reverse(a,9);
}