#include <stdio.h>

//i will always given as 1 in all cases

void pattern1(int n,int i){
    for(int j=1;j<=i;j++){
        printf("%d",i);
    }
    printf("\n");
    if(i==n){
        return;
    }
    return pattern1(n,i+1);
}

void pattern2(int n,int i){
    for(int j=1;j<=n-i;j++){
        printf(" ");
    }
    for(int j=1;j<=i;j++){
        printf("* ");
    }
    printf("\n");
    if(n==i){
        return;
    }
    return pattern2(n,i+1);
}

void pattern3(int n,int i){
    for(int j=1;j<=n-i;j++){
        printf("  ");
    }
    for(int j=1;j<=i;j++){
        printf("* ");
    }
    printf("\n");
    if(n==i){
        return;
    }
    return pattern3(n,i+1);
}

void pattern4(int n,int i){
    for(int j=1;j<=i;j++){
        printf("* ");
    }
    printf("\n");
    if(n==i){
        return;
    }
    return pattern4(n,i+1);
}
int main(){
    pattern1(5,1);
    pattern2(5,1);
    pattern3(5,1);
    pattern4(5,1);
}