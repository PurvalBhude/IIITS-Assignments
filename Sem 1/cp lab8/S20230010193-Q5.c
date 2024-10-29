#include <stdio.h>
int fibonacci_number(int n){
    if(n==1 || n==2){
        return 1;
    }
    return fibonacci_number(n-1)+fibonacci_number(n-2);
}
void fibonaccintom(int n,int m){
    for(int i=n;i<=m;i++){
        printf("%d ",fibonacci_number(i));
    }
    return;
}
int main(){
    fibonaccintom(5,15);
}