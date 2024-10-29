#include <stdio.h>

void prime_number(int n,int m){
    int count;
    for(int i=n;i<=m;i++){
        count=0;
        for(int j=2;j<n;j++){
            if(i%j==0){
                count++;
            }
        }
        if(count==0){
            printf("%d ",i);
        }
    }
}

int main(){
    prime_number(10,100);
}