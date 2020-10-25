//backtracking->dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //fewest amount of coins for each amount
        if(amount==0)return 0;
        int n=coins.size();
        int dp[amount+1];
        std::fill_n(dp,amount+1,-1);

        for(int i=1;i<=amount;i++){
        	for(int j=0;j<coins.size();j++){
        		if(i==coins[j]){
        			dp[i]=1;
        			break;
        		}else{
        			if(coins[j]<i&&dp[i-coins[j]]!=-1){
                        // cout<<i<<" "<<dp[i]<<" "<<dp[i-coins[j]]<<endl;
                        if(dp[i]==-1){
                            dp[i]=1+dp[i-coins[j]];
                        }else{
                            dp[i]=min(dp[i],1+dp[i-coins[j]]);
                        }
        			}
        		}
        	}
        }
        return dp[amount];
    }
};