#include <stdio.h>

//returns 1 if palindrome or return 0;
int checkpalindrome(int arr[],int n){
    for(int i=0;i<n/2;i++){
        if(arr[i]!=arr[n-i-1]){
            return 0;
        }
    }
    return 1;
}

//n is rows and m is columns
void check_palindrome_for_row_majar(int arr[][3],int n,int m){
    int order = n*m;
    int row[order];
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            row[k] = arr[i][j];
            k++;
        }
    }
    
    int result = checkpalindrome(row,order);
    if(result){
        printf("it is palindrome\n");
    }
    else{
        printf("it is not palindrome\n");
    }
    return;
}

//n is rows and m is columns
void check_palindrome_for_column_majar(int arr[][3],int n,int m){
    int order = n*m;
    int column[order];
    int k = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            column[k] = arr[i][j];
            k++;
        }
    }
    
    int result = checkpalindrome(column,order);
    if(result){
        printf("it is palindrome\n");
    }
    else{
        printf("it is not palindrome\n");
    }
    return;
}

void main(){
    int arr[3][3] = {{1,2,3},{4,5,4},{3,2,1}};
    printf("checking for row major: ");
    check_palindrome_for_row_majar(arr,3,3);
    printf("checking for column major: ");
    check_palindrome_for_column_majar(arr,3,3);

    //time complexity : O(n*m) where n and m are row and column respectively
    //space complexity : O(n*m) where n and m are row and column respectively
}