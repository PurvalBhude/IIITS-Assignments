#include<stdio.h>

int main(){
    int a,b,c;
    a = 5;
    b = 10;
    c = 15;

    printf("A bitwise AND B : %d\n",a&b);
    printf("A bitwise OR B : %d\n",a|b);
    printf("A bitwise Exclusive OR B : %d\n",a^b);
    printf("A left shift 2 : %d\n",a<<2);
    printf("B right shift 4 : %d\n",b>>4);
    printf("one's complement of C : %d\n",~c);
    
}