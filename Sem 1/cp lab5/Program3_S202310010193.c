#include <stdio.h>
int main() {
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    int i = n;
    int j = n;
    int sum=0;
    int product=1;
    while(i>0){
        sum = sum + i;
        i--;
    }
    while(j>0){
        product = product*j;
        j--;
    }
    printf("Sum is %d\n",sum);
    printf("Product is %d",product);
}