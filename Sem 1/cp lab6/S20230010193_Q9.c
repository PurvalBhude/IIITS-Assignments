#include<stdio.h>
#include<math.h>
int main(){
    char str[] = "Purval Madhukar Bhude";
    printf("String: ");
    printf("%s",str);
    printf("\n");
    int i=1;
    while(str[i]!='\0'){
        i++;
    }
    printf("using loop string size: %d\n",i);
    printf("using string.h library string size: %d",strlen(str));
}