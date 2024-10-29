#include <stdio.h>

//Question 1
struct Matrix{
    int i;
    int j;
    int arr[100][100];
};

void transpose(struct Matrix *M){
    int result[M->j][M->i];
    //storing transpose matrix in result matrix
    for(int m=0;m<M->i;m++){
        for(int n=0;n<M->j;n++){
            result[n][m] = M->arr[m][n];
        }
    }
    
    //changing the order
    int c = M->j;
    M->j = M->i;
    M->i = c;

    //putting result matrix in structure matrix
    for(int m=0;m<M->i;m++){
        for(int n=0;n<M->j;n++){
            M->arr[m][n] = result[m][n];
        }
    }
    return;
}

//Question 2
int palindromeparmutation(char s[]){
    //creating array which store frequency of character in letter
    int freq[26] = {0};
    for(int i=0;i<strlen(s);i++){
        freq[s[i]-'a'] = freq[s[i]-'a'] + 1;
    }

    //count odd number of freqency 
    int count = 0;
    for(int i=0;i<26;i++){
        if(freq[i]%2 == 1 ){
            count++;
        }
    }

    if(count <= 1){
        return 1;
    }
    return 0;
}

//Question 3
int way(int n){
    if(n<0){
        return 0;
    }
    if(n==1 || n==0){
        return 1;
    }
    else if(n==2){
        return 2;
    }
    else{
        return way(n-1)+way(n-2)+way(n-3);
    }
}

int main(){
    //Question 1
    struct Matrix M1;
    //scaning the elements
    printf("Enter the order of matrix in i*j: \n");
    scanf("%d",&M1.i);
    scanf("%d",&M1.j);
    printf("Enter the matrix:\n");
    for(int m=0;m<M1.i;m++){
        for(int n=0;n<M1.j;n++){
            scanf("%d",&M1.arr[m][n]);
        }
    }
    //printing the scan matrix
    printf("your enter matrix is: \n");
    for(int m=0;m<M1.i;m++){
        for(int n=0;n<M1.j;n++){
            printf("%d ",M1.arr[m][n]);
        }
        printf("\n");
    }
    //printing its transpose
    transpose(&M1);
    printf("\nAfter transposing the matrix:\n");
    printf("order of matrix is %d*%d\n",M1.i,M1.j);
    printf("the matrix is:\n");
    for(int m=0;m<M1.i;m++){
        for(int n=0;n<M1.j;n++){
            printf("%d ",M1.arr[m][n]);
        }
        printf("\n");
    }
    return 0;
    // time complexity = O(i*j) where i and j is rows and columns of matrix respectively
    // space complexity = O(i*j) where i and j is rows and columns of matrix respectively


    //Question 2
    char a[] = "mmaad";
    printf("%d",palindromeparmutation(a));

    // time complexity: O(n) where n is size of string
    // space complexity: O(1) it is constant as we need constant amount of space which is 26 element matrix to store frequency


    //Question 3
    printf("%d",way(10));

    //recursive relation: F[n] = F[n-1] + F[n-2] + F[n-3]
}