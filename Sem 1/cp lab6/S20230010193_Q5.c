#include<stdio.h>

int main(){
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    printf("Prime Number: ");
    int i =2;
    while(i<=n){
        int count = 0;
        int j=2;
        while(j<i){
            if(i%j==0){
                count++;
            }
            j++;
        }
        if(count == 0){
            printf("%d ",i);
        }
        i++;
    }
}
