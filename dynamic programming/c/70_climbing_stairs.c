#include <stdlib.h>

int climbStaris(int n){
    if(n==1)return 1;
    int dp[n+1];
    memset(dp,0,n+1);

    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<n+1;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];
}