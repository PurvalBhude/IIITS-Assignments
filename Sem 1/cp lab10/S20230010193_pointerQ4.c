#include <stdio.h>
#include <string.h>

void removespace(char *a,int n){
    int i=0;
    while(i<n){
        if(a[i]==' '){
            for(int j=i;j<n;j++){
                a[j] = a[j+1];
            }
            
        }
        else{
            i++;
        }
    }
}

int main(){
    char a[] = "Purval Madhukar Bhude";
    printf("before removing : %s\n",a);
    int length = strlen(a);
    removespace(a,length);
    printf("after removing : %s\n",a);
}