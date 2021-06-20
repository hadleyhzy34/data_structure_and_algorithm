#include <iostream>
#include <vector>

class solution{
public:
    int climbStairs(int n){
        if(n==1)return 1;
        std::vector<int> dp(n);
        dp[0]=1;
        dp[1]=2;
        // for(int i:n)
        for(int i=2;i<n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n-1];
    }
};