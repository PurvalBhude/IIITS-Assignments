#include<stdio.h>

int main(){
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    int sum,term1,term2;
    term1=0;
    term2=1;
    printf("Fibonacci series: %d %d ",term1,term2);
    int i=3;
    while(i<=n){
        sum = term1+term2;
        term1=term2;
        term2=sum;
        printf("%d ",sum);
        i++;
    }
}