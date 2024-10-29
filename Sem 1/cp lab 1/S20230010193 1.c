Code:
#include<stdio.h>

void main(){
    int a;
    printf("Enter Num1:");
    scanf("%d",&a);

    int b;
    printf("Enter Num2:");
    scanf("%d",&b);

    int sum = a+b;
    int sub = a-b;
    int mul = a*b;
    int div = a/b;

    printf("addition:%d\n",sum);
    printf("subtraction:%d\n",sub);
    printf("multiplication:%d\n",mul);
    printf("division:%d\n",div);

}


Input:
Enter Num1:5
Enter Num2:5

Output:
addition:10
subtraction:0
multiplication:25
division:1

Observation:
The division operater shown integer value division