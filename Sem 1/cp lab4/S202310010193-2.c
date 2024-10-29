#include<stdio.h>

int main(){
    int a,b,c;
    printf("Value of A:");
    scanf("%d",&a);
    printf("Value of B:");
    scanf("%d",&b);
    printf("Value of C:");
    scanf("%d",&c);

    printf("value of a,b,c before operation\n");
    printf("value of A is %d\n",a);
    printf("value of B is %d\n",b);
    printf("value of C is %d\n",c);


    --a;
    printf("pre-decrement of A is %d\n",a);

    c--;
    printf("addition of pre-decrement of A with post decrement of C is %d\n",a+c);

    --b;
    printf("pre-decrement of B is %d\n",b);

    ++c;
    printf("addition of pre-decrement of B with pre-increment of C is %d\n",b+c);

    printf("value of a,b,c after operation \n");
    printf("value of A is %d\n",a);
    printf("value of B is %d\n",b);
    printf("value of C is %d\n",c);
}
