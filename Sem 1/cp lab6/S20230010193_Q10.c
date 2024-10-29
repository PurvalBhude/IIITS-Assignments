#include<stdio.h>
#include<string.h>
int main(){
    char str1[] = "Purval Madhukar Bhude";
    printf("String1: ");
    printf("%s",str1);
    printf("\n");
    char str2[] = "He studies in IIIT Sricity";
    printf("String2: ");
    printf("%s",str2);
    printf("\n");
    printf("on comparing str1 and str2 using strcmp: %d\n",strcmp(str1,str2));
    int i = 0;
    int count = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            count++;
        }
        i++;
    }
    if(count!=0){
        printf("on comparing str1 and str2 using loop: 1\n");
    }
    else{
        printf("on comparing str1 and str2 using loop: 0\n");
    }
}
