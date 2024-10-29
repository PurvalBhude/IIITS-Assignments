#include <stdio.h>

int way(int n){
    if(n<0){
        return 0;
    }
    if(n==1 || n==0){
        return 1;
    }
    else if(n==2){
        return 2;
    }
    else{
        return way(n-1)+way(n-2)+way(n-3);
    }
}

int main(){
    printf("%d",way(10));
    
}