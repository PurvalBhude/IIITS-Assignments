#include <stdio.h>
#include <string.h>

void palindrome_character(char a[]){
    int  k = strlen(a);
    int  A = 0;
    int  B = k-A-1;
    while(A<B){
        if(a[A]!=a[B]){
            printf("Its not palindrome");
            return;
        }
        A++;
        B--;
    }
    printf("Its palindrome");
    return;
}

void palindrome_integer(int a){
    int b = a;
    int rev = 0;
    int k;
    while(a>0){
        k=a%10;
        rev = (rev*10)+k;
        a=a/10;
    }
    if(rev==b){
        printf("Its palindrome");
    }
    else{
        printf("Its not palindrome");
    }
    return;
}

int main(){
    char a[] = "madam";
    palindrome_character(a);
    printf("\n");
    int b = 132231;
    palindrome_integer(b);
}