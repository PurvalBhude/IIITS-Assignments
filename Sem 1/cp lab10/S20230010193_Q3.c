#include <stdio.h>
int nCr(int n,int r){
    if(n==r){
        return 1;
    }
    if(r==0){
        return 1;
    }
    return nCr(n-1,r-1)+nCr(n-1,r);
}
int main(){
    printf("answer: %d",nCr(10,5));
}