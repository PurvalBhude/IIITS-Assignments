#include <stdio.h>
#include <string.h>

void string_with(char s[]){
    printf("length of string using strlen(): %d\n",strlen(s));
    return;
}

void string_without(char s[]){
    int length = 0;
    while(s[length]!='\0'){
        length++;
    }
    printf("length of string without using strlen(): %d\n",length);
    return;
}
int main(){
    char s[] = "Purval Madhukar Bhude";
    string_with(s);
    string_without(s);
}