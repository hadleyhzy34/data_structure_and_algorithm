class Solution {
public:
	void backtracking(vector<int>& coins, int amount, int index, vector<int>subset,vector<vector<int>>&res){
		if(amount==0){
			res.push_back(subset);
		}
		for(int i=index;i<coins.size();i++){
			if(amount-coins[i]<0)continue;
			subset.push_back(coins[i]);
			backtracking(coins,amount-coins[i],i,subset,res);
			subset.pop_back();
		}
	}

    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        
//         sort(coins.begin(),coins.end());

//         for(int i=1;i<=amount;i++){
//         	for(int j=0;j<coins.size();j++){
//         		if(i-coins[j]>0){
//         			dp[i]+=dp[i-coins[j]];
//         		}else if(i==coins[j]){
//         			dp[i]++;
//         		}
//         	}
//             cout<<i<<" "<<dp[i]<<endl;
//         }
        
        for(int coin:coins){
            for(int i=coin;i<amount+1;i++){
                dp[i]+=dp[i-coin];
            }
        }
        return dp[amount];
    }
};

