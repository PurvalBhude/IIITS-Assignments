#include <stdio.h>

// //Question 1

// //it will give 0 if not sorted
// //it will give 1 if sorted
// int issorted(int arr[], int n)
// {
//     if (n == 1)
//     {
//         return 1;
//     }
//     if (arr[n - 1] >= arr[n - 2])
//     {
//         return issorted(arr, n - 1);
//     }
//     else
//     {
//         return 0;
//     }
// }

// //Question 2 

// //n is row and m is column
// void largestregion(int arr[][5],int n,int m){
//     int spererc[25][2];
//     int k = 0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j] == 1){
//                 spererc[k][0] = i;
//                 spererc[k][1] = j;
//                 k++;
//             }
//         }
//     }

//     int max = -1;
//     int count = 0;
//     for(int i=1;i<k;i++){
//         if((spererc[i-1][0]+1 == spererc[i][0]) && ((spererc[i-1][1]+1 == spererc[i][1]) || (spererc[i-1][1] == spererc[i][1]))){
//             count++;
//         }
//         else if((spererc[i-1][0] == spererc[i][0]) && (spererc[i-1][1]+1 == spererc[i][1])){
//             count++;
//         }
//         else{
//             if(count>max){
//                 max = count;
//             }
//             count = 0;
//         }
//     }

//     int sperecr[25][2];
//     k=0;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(arr[j][i] == 1){
//                 sperecr[k][0] = j;
//                 sperecr[k][1] = i;
//                 k++;
//             }
//         }
//     }

//     count = 0;
//     for(int i=1;i<k;i++){
//         if((sperecr[i-1][1]+1 == sperecr[i][1]) && ((sperecr[i-1][0]+1 == sperecr[i][0]) || (sperecr[i-1][0] == sperecr[i][0]))){
//             count++;
//         }
//         else if((sperecr[i-1][1] == sperecr[i][1]) && (sperecr[i-1][0]+1 == sperecr[i][0])){
//             count++;
//         }
//         else{
//             if(count>max){
//                 max = count;
//             }
//             count = 0;
//         }
//     }
    
//     max++; //max++ beacuse it take count t-1 only 
//     printf("largest region is: %d",max);
//     return;
// }


// //Question 3

// //returns 1 if palindrome or return 0;
// int checkpalindrome(int arr[],int n){
//     for(int i=0;i<n/2;i++){
//         if(arr[i]!=arr[n-i-1]){
//             return 0;
//         }
//     }
//     return 1;
// }

// //n is rows and m is columns
// void check_palindrome_for_row_majar(int arr[][3],int n,int m){
//     int order = n*m;
//     int row[order];
//     int k = 0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             row[k] = arr[i][j];
//             k++;
//         }
//     }
    
//     int result = checkpalindrome(row,order);
//     if(result){
//         printf("it is palindrome\n");
//     }
//     else{
//         printf("it is not palindrome\n");
//     }
//     return;
// }

// //n is rows and m is columns
// void check_palindrome_for_column_majar(int arr[][3],int n,int m){
//     int order = n*m;
//     int column[order];
//     int k = 0;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             column[k] = arr[i][j];
//             k++;
//         }
//     }
    
//     int result = checkpalindrome(column,order);
//     if(result){
//         printf("it is palindrome\n");
//     }
//     else{
//         printf("it is not palindrome\n");
//     }
//     return;
// }


// void main()
// {
//     //Question 1

//     int arr[11] = {1,2,3,4,5,6,78,89,765,1654,913456};
//     printf("%d",issorted(arr,11));

//     // recursive relation => T[n] = T[n-1] + 1;
//     // time complexitty : O(n) where n is size of array


//     //Question 2 
//     int arr[5][5] = {{1,1,0,0,0},{0,1,1,0,0},{0,0,1,0,1},{1,0,0,0,1},{0,1,0,1,1}};
//     largestregion(arr,5,5);

//     // time Complexity : O(n*m) where n and m is row and column respectively

//     //Question 3
//     int arr[3][3] = {{1,2,3},{4,5,4},{3,2,1}};
//     printf("checking for row major: ");
//     check_palindrome_for_row_majar(arr,3,3);
//     printf("checking for column major: ");
//     check_palindrome_for_column_majar(arr,3,3);

    // time complexity : O(n*m) where n and m are row and column respectively
//     //space complexity : O(n*m) where n and m are row and column respectively
// }