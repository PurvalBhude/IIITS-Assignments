#include <stdio.h>
#include <string.h>

void findnumberofchar(char* str,char* find,int* count){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==find){
            (*count)++;
        }
    }
}

int main(){
    char str[] = "Purval Madhukar Bhude";
    char find = 'a';
    int count = 0;
    findnumberofchar(str,find,&count);
    printf("number of occurance of %c in %s is %d",find,str,count);
}