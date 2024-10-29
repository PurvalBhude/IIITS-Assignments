#include<stdio.h>


void main(){
    int P,Q;
    float R,S,X;

    //taking input from user for values of variable P,Q,R,S.
    printf("Enter P:");
    scanf("%d",&P);
    printf("Enter Q:");
    scanf("%d",&Q);
    printf("Enter R:");
    scanf("%f",&R);
    printf("Enter S:");
    scanf("%f",&S);

    //NOW, SOLVING ALL SIX EQUATIONS

    X = P + Q / 4 * S/ 3 + Q;
    printf("1)X = P + Q / 4 * S/ 3 + Q IS EQUAL TO %f\n",X);

    X = R + S / 4 * Q / 3 + S;
    printf("2)X = X = R + S / 4 * Q / 3 + S IS EQUAL TO %f\n",X);

    X =(int) R / P * Q / 3;
    printf("3)X = X = (int) R / P * Q / 3 IS EQUAL TO %f\n",X);

    X = P / Q * Q % 5 % 3;
    printf("4)X = P + Q / 4 * S/ 3 + Q IS EQUAL TO %f\n",X);

    X = 10 - 5 - 7 / 4 * 4;
    printf("5)X = 10 - 5 - 7 / 4 * 4 IS EQUAL TO %f\n",X);

    X = 24/(1 + 2%3 + 4/5 + 6 + 31%8);
    printf("6)X = 24/(1 + 2%3 + 4/5 + 6 + 31%8) IS EQUAL TO %f\n",X);

}