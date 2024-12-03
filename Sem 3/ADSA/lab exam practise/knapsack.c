#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
    if(a<b){
        return b;
    }
    return a;
}

int knapsack(int *w,int *pro,int n,int capacity){
    if(n==0){
        return 0;
    }
    if(w[n-1]>capacity){
        return knapsack(w,pro,n-1,capacity);
    }

    return max(knapsack(w,pro,n-1,capacity-w[n-1])+pro[n-1],knapsack(w,pro,n-1,capacity));
}


int knapsack_dp(int *w,int *pro,int n,int capacity,int *dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    if(w[n-1]>capacity){
        return knapsack(w,pro,n-1,capacity);
    }

    int result = max(knapsack(w,pro,n-1,capacity-w[n-1])+pro[n-1],knapsack(w,pro,n-1,capacity));
    dp[n] = result;
    return result;
}


int main(){
    int arr[] = {2,3,5};
    int pro[] = {10,20,30};
    int *dp = (int *) malloc(sizeof(int)*3);
    for(int i=0;i<=3;i++){
        dp[i] = -1;
    }
    printf("ans: %d\n",knapsack(arr,pro,3,8));
    printf("ans using dp: %d",knapsack_dp(arr,pro,3,8,dp));
}