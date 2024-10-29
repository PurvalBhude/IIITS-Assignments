#include <stdio.h>

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

int main(){
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
}