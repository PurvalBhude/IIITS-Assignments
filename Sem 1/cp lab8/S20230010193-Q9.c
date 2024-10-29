#include <stdio.h>
#include <string.h>

void campare_without(char n[],char m[]){
    int j;
    if(strlen(n)>=strlen(m)){
        j = strlen(n);
    }
    else{
        j = strlen(m);
    }
    for(int i=0;i<j;i++){
        if(n[i]!=m[i]){
            printf("strings are not same when check without inbuild function\n");
            return;
        }
    }
    printf("strings are same when check without inbuild function\n");
    return;
}

void campare_with(char n[],char m[]){
    if(strcmp(n,m)){
        printf("strings are not equal when check with inbuild function\n");
    }
    else{
        printf("strings are equal when check with inbuild function\n");
    }
}

int main(){
    char n[] = "Purval";
    char m[] = "Purval";
    campare_without(n,m);
    campare_with(n,m);
}