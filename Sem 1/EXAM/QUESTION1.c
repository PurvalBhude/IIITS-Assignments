#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
    FILE *ptr1, *ptr2;
    ptr1 = fopen("input.txt","r");
    ptr2 = fopen("output.txt","w");

    if(ptr1==NULL || ptr2==NULL){
        printf("error in opening file");
        exit(-1);
    }

    int key;
    printf("Enter key: ");
    scanf("%d",&key);

    char cpy = fgetc(ptr1);
    while(cpy != EOF){
        if((cpy>='a' && cpy <='z') || (cpy>='A' && cpy <='Z')){
            cpy = cpy+key;
            fputc(cpy,ptr2);
        }
        else{
            fputc(cpy,ptr2);
        }
        cpy = fgetc(ptr1);
    }
    fclose(ptr1);
    fclose(ptr2);
}