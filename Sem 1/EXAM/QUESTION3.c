#include <stdio.h>
#include <string.h>

void swap(char a[],int i,int j){
    a[i] = a[i]^a[j];
    a[j] = a[i]^a[j];
    a[i] = a[i]^a[j];
}

void permutation(char a[],int counter){
    if(counter >= strlen(a)){
        return;
    }
    swap(a,0,1);
    printf("%s\n",a);
    swap(a,0,2);
    printf("%s\n",a);
    permutation(a,counter+1);
}
int main(){
    char a[] = "SRI";
    permutation(a,0);
}