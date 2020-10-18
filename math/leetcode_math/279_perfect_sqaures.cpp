class Solution {
public:
    int numSquares(int n) {
        int lNumber[n+1];
        memset(lNumber, 0, sizeof(lNumber));

        for(int i=1;i<=n;i++){
            if((sqrt(i)-floor(sqrt(i)))==0){
                lNumber[i]=1;
            }else{
                for(int j=1;(j*j)<i;j++){
                    int count=1+lNumber[i-(j*j)];
                    if(lNumber[i]==0||count<lNumber[i])lNumber[i]=count;
                }
            }
        }
        return lNumber[n];
    }
};

class Solution2 {
public:
    int numSquares(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++){
            if(sqrt(i)==floor(sqrt(i))){
                dp[i]=1;
            }else{
                for(int j=1;j*j<i;j++){
                    if(dp[i]==0||1+dp[i-j*j]<dp[i]){
                        dp[i]=1+dp[i-j*j];
                    }
                }
            }
        }
        return dp[n];
    }
};