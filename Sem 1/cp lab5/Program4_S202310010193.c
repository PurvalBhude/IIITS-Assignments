#include <stdio.h>
int main() {
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    int i = n;
    int j = n;
    int sum=0;
    int product=1;
    do{
        sum = sum + i;
        i--;
    }while(i>0);
    do{
        product = product*j;
        j--;
    }while(j>0);
    printf("Sum is %d\n",sum);
    printf("Sum is %d",product);
}
