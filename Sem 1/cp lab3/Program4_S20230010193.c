#include<stdio>

// defining the function for calculating next multiple 
int next_multiple(int k,int m);


void main(){
    int k,m;

    // defining it for first question and printing its next multiple result using formula given
    k = 1000;
    m = 50;
    printf("1) When k is 1000 and m is 50 next multiple is %d\n",next_multiple(k,m));

    // defining it for second question and printing its next multiple result using formula given
    k = 54321;
    m = 9876;
    printf("2) When k is 54321 and m is 9876 next multiple is %d\n",next_multiple(k,m));

    // defining it for third question and printing its next multiple result using formula given
    k = 500;
    m = 33;
    printf("3) When k is 500 and m is 33 next multiple is %d\n",next_multiple(k,m));
}

//defining the function
int next_multiple(int k,int m){
    int multiple = k+m-k%m;
    return multiple;
}