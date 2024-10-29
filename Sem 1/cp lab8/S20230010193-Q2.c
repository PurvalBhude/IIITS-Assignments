#include <stdio.h>
#include <string.h>

//target is string which we have to find in str and n is size of target string
void search(char target[],char str[],int n){
    int count;
    for(int i=0;i<strlen(str);i++){
        if(target[0]==str[i]){
            count=0;
            for(int j=0;j<n;j++){
                if(target[j]==str[i+j]){
                    count++;
                }
            }
            if(count==n){
                printf("target string exist in character array");
                return;
            }
        }
    }
    printf("target string does not exist in character array");
    return;
}

int main(){
    char str[] = "My Name Is Purval Madhukar Bhude";
    char Target[] = "Purval";
    search(Target,str,6);
}