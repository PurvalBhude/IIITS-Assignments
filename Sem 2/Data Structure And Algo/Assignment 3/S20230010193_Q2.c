#include <stdio.h>

//n is row and m is column
void largestregion(int arr[][5],int n,int m){
    int spererc[25][2];
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 1){
                spererc[k][0] = i;
                spererc[k][1] = j;
                k++;
            }
        }
    }

    int max = -1;
    int count = 0;
    for(int i=1;i<k;i++){
        if((spererc[i-1][0]+1 == spererc[i][0]) && ((spererc[i-1][1]+1 == spererc[i][1]) || (spererc[i-1][1] == spererc[i][1]))){
            count++;
        }
        else if((spererc[i-1][0] == spererc[i][0]) && (spererc[i-1][1]+1 == spererc[i][1])){
            count++;
        }
        else{
            if(count>max){
                max = count;
            }
            count = 0;
        }
    }

    int sperecr[25][2];
    k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[j][i] == 1){
                sperecr[k][0] = j;
                sperecr[k][1] = i;
                k++;
            }
        }
    }

    count = 0;
    for(int i=1;i<k;i++){
        if((sperecr[i-1][1]+1 == sperecr[i][1]) && ((sperecr[i-1][0]+1 == sperecr[i][0]) || (sperecr[i-1][0] == sperecr[i][0]))){
            count++;
        }
        else if((sperecr[i-1][1] == sperecr[i][1]) && (sperecr[i-1][0]+1 == sperecr[i][0])){
            count++;
        }
        else{
            if(count>max){
                max = count;
            }
            count = 0;
        }
    }
    
    max++; //max++ beacuse it take count t-1 only 
    printf("largest region is: %d",max);
    return;
}

int main(){
    int arr[5][5] = {{1,1,0,0,0},{0,1,1,0,0},{0,0,1,0,1},{1,0,0,0,1},{0,1,0,1,1}};
    largestregion(arr,5,5);

    // time Complexity : O(n*m) where n and m is row and column respectively
}