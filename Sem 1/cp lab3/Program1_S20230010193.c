#include<stdio.h>


void main(){
    //defining the functions
    int a;
    float b;
    char ch;
    char d[13];
    
    //taking integer input
    printf("Enter integer:");
    scanf("%d",&a);

    //taking float input 
    printf("Enter float:");
    scanf("%f",&b);

    //taking character input
    printf("Enter charater:");
    scanf("%c",&ch);

    //taking string input
    printf("Enter string:");
    scanf("%s",d);

    //printing the all the values which where taken input
    printf("entered integer is %d\n",a);
    printf("entered float is %f\n",b);
    printf("entered character is %c\n",ch);
    printf("entered string is ");
    puts(d);
}
