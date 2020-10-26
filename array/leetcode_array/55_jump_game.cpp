class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        bool dp[n];
        std::fill_n(dp,n,false);

        dp[0]=true;
        for(int i=0;i<n;i++){
        	if(dp[i]==true){
        		for(int j=1;j<=nums[i]&&(i+j)<n;j++){
        			dp[i+j]=true;
        		}
        	}
        }
        return dp[n-1];
    }
};



class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        // if(nums.size()==1)return true;
        int n=nums.size();

        int rightmost=0;
        for(int i=0;i<n;i++){
        	rightmost=max(rightmost,i+nums[i]);
        	if(rightmost<=i&&i!=n-1){
        		return false;
        	}
        }
	    return true;
    }
};