#include <stdio.h>
#include <math.h>

// A}
int factorial(int n){
    if(n==1){
        return 1;
    }
    else{
        return factorial(n-1)*n;
    }
} 

// B}
int sum_of_n_number(int n){
    if(n==1){
        return 1;
    }
    return sum_of_n_number(n-1)+n;
}

// C}
int amstrong(int n){
    if(n==0){
        return 0;
    }
    return (pow(n%10,3)+amstrong(n/10));
}
void is_amstrong(int n){
    if(amstrong(n)==n){
        printf("Its a amstrong number\n");
    }
    else{
        printf("Its not a amstrong number\n");
    }
}

// D}
int factorial_tailrecurrsion(int n){
    if(n==1){
        return 1;
    }
    return factorial(n-1)*n;
}

// E}
void printnto0(int n){
    if(n<0){
        return;
    }
    printf("%d ",n);
    printnto0(n-1);
}

int main(){
    printf("A)Factorial of 5: %d\n",factorial(5));
    printf("B)sum of first 5: %d\n",sum_of_n_number(5));
    printf("C)check wheater 153 is amstrong: ");
    is_amstrong(153);
    printf("D)factorial using tail recursion: %d\n",factorial_tailrecurrsion(5));
    printf("E)print number of 10 to 0: ");
    printnto0(10);
}