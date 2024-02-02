#include <iostream>
#include <vector>

    bool canWinNim(int n) {
        if(n<=3)return true;
        // if(n<INT_MAX){
        //     std::cout<<"check";
        // }else{
        //     std::cout<<"large";
        // }
        // int dp[n];
        int *dp = (int*)malloc(sizeof(int)*n);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        for (auto i = 3; i < n; i++) {
            if ((!dp[i - 1]) || (!dp[i - 2]) || (!dp[i - 3])) {
                dp[i] = 1;
            } else {
                dp[i] = 0;
            }
        }
        return dp[n - 1];
    }