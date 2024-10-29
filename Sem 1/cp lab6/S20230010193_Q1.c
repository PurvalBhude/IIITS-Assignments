#include<stdio.h>

int main(){
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    int rev = 0;
    int new_n = n;
    while(n!=0){
        int k = n%10;
        rev = (rev*10)+k;
        n=n/10;
    }
    if(new_n==rev){
        printf("Number is Palindrome");
    }
    else{
        printf("Number is not Palindrome");
    }
}