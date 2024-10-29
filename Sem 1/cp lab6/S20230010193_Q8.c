#include<stdio.h>
#include<math.h>
int main(){
    int a1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    printf("Matrix1: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",a1[i][j]);
        }
        printf("\n");
    }
    int a2[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    printf("Matrix2: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",a2[i][j]);
        }
        printf("\n");
    }
    int ans[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans[i][j] = (a1[i][0]*a2[0][j])+(a1[i][1]*a2[1][j])+(a1[i][2]*a2[2][j]);
        }
    }
    printf("\n");
    printf("Answer matrix:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}