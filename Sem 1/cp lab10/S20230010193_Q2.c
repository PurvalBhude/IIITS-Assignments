#include <stdio.h>
int toh(int n,char a[],char b[],char c[]){
    if(n==1){
        printf("move %d from %s to %s\n",n,a,c);
        return 0;
    }
    int moves = 0;
    moves = moves + toh(n-1,a,c,b);
    printf("move %d from %s to %s\n",n,a,c);
    moves++;
    moves = moves + toh(n-1,b,a,c);
    return moves;
}
int main(){
    toh(3,"current","helping","destination");
}