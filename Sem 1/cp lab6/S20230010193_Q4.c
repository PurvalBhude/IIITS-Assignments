#include<stdio.h>

int main(){
    int n1;
    printf("Enter Number1: ");
    scanf("%d",&n1);
    int n2;
    printf("Enter Number2: ");
    scanf("%d",&n2);
    printf("GCD: ");

    if(n1>n2){
        for(int i=n2;i>0;i--){
        if(n1%i==0&&n2%i==0){
            printf("%d",i);
            break;
        }
    }
    }
    else{
        for(int i=n1;i>0;i--){
        if(n1%i==0&&n2%i==0){
            printf("%d",i);
            break;
        }
    }
    }

}