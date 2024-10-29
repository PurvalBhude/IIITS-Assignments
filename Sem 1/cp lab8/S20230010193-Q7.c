#include <stdio.h>

//multiplication of 3 order matrix
void multiple_3order_matrix(int n[3][3],int m[3][3]){
    int ans[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans[i][j] = (n[i][0]*m[0][j])+(n[i][1]*m[1][j])+(n[i][2]*m[2][j]);
        }
    }
    printf("Answer matrix:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}

//multiplication of 2 order matrix
void multiple_2order_matrix(int n[2][2],int m[2][2]){
    int ans[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ans[i][j] = (n[i][0]*m[0][j])+(n[i][1]*m[1][j]);
        }
    }
    printf("\n");
    printf("Answer matrix:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int m[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    multiple_3order_matrix(n,m);
    printf("\n");

    int a[2][2] = {{1,0},{0,1}};
    int b[2][2] = {{69,70},{419,420}};
    multiple_2order_matrix(a,b);
}