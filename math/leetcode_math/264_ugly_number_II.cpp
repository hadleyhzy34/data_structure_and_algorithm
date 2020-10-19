class Solution {
public:
    int nthUglyNumber(int n) {
    	int dp[n];
    	memset(dp,0,sizeof(dp));
        dp[0]=1;

        int i2=0,i3=0,i5=0;

        for(int i=1;i<n;i++){
        	dp[i]=min(dp[i2]*2,min(dp[i3]*3,dp[i5]*5));
            
            //be carefull that we cannot use if/else if considering case 2*3, 3*2
            if(dp[i]==dp[i2]*2)i2++;
            if(dp[i]==dp[i3]*3)i3++;
            if(dp[i]==dp[i5]*5)i5++;
        }
        return dp[n-1];
    }
};