#include <stdio.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)

//question 1
//i is always zero
void diagonal(int a[][3], int n, int m, int i) {
    if (i < n) {
        a[i][i] = 0;
        diagonal(a, n, m, i + 1);
    }
}
//i and j is always zero
void transpose(int a[][3], int n, int m, int i, int j) {
    if (i < m) {
        if (j < n) {
            printf("%d ", a[j][i]);
            transpose(a, n, m, i, j + 1);
        } else {
            printf("\n");
            transpose(a, n, m, i + 1, 0);
        }
    }
}

void equality_matrix(int arr1[][3],int arr2[][3],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr1[i][j]!=arr2[i][j]){
                printf("Not Equal\n");
                transpose(arr1,n,m,0,0);
                return;
            }
        }
    }
    printf("Matrix Equal\n");
    diagonal(arr1,n,m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
    return;
}

//question 2
void printarray(int arr[],int strlen){
    if(strlen==0){
        return;
    }
    printf("%d ",arr[strlen-1]);
    return printarray(arr,strlen-1);
}
//index will away be entered 0
int findMax(int arr[], int size, int index) {
    if (index == size - 1) {
        return arr[index];
    }
    
    int max = findMax(arr, size, index + 1);
    
    return (arr[index] > max) ? arr[index] : max;
}

int findMin(int arr[], int size, int index) {
    if (index == size - 1) {
        return arr[index];
    }
    
    int min = findMin(arr, size, index + 1);
    
    return (arr[index] < min) ? arr[index] : min;
}


//question 3
int gcd(int n,int m){
    if(n==0){
        return m;
    }
    if(m==0){
        return n;
    }
    if(n>m){
        return gcd(n%m,m);
    }
    else{
        return gcd(n,m%n);
    }
}


//question 4
void encodestring(char str[] , char encode[]){
    int index=0;
    for(int i=0;str[i]!='\0';i++){
        encode[index++]=str[i];
        encode[index++]='0';
    }
    encode[index]='\0';
}
void decodestring(char encode[],char decode[]){
    int index=0;
    for(int i=0;encode[i]!='\0';i++){
        if(encode[i]!='0'){
            decode[index++]=encode[i];
        }
    }
    decode[index]='\0';
}
//question 5
void divideString(char str[], int n, int index, int len) {
  if (index >= len) {
    return;
  }

  int partLen = len / n;
  int end = index + partLen - 1;

  if (end >= len) {
    end = len - 1;
  }

  for (int i = index; i <= end; i++) {
    printf("%c", str[i]);
  }
  printf("\n");

  divideString(str, n, end + 1, len);
}

//main should be writing in such a way in which way above function has to use
int main(){
    int arr1[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int arr2[][3] = {{10,2,3},{4,5,6},{7,8,9}};
    equality_matrix(arr1,arr2,3,3);

    int arr3[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    equality_matrix(arr1,arr3,3,3);
}