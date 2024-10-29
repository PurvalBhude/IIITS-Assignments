#include <stdio.h>

//direct recursion eg.factorial of number
int factorial(int n){
    if(n==1){
        return 1;
    }
    return factorial(n-1)*n;
}

//indirect recursion eg.printing first n number
void supportfun(int n);
void printn(int n);

void printn(int n){
    if(n>0){
        printf("%d ",n);
        supportfun(n-1);
    }
}
void supportfun(int n){
    if(n>0){
        printf("%d ",n);
        printn(n-1);
    }
}
int main(){
    printf("Example of direct recursion\n");
    printf("factorial: %d\n",factorial(5));
    printf("Example of indirect recursion\n");
    printf("first n number: ");
    printn(10);
}