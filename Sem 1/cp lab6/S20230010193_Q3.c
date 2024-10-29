#include<stdio.h>

int main(){
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    printf("Factorial: ");
    int factorial = 1;
    for(int i=2;i<=n;i++){
        factorial = factorial*i;
    }
    printf("%d",factorial);
}
