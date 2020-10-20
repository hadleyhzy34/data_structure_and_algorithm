//backtracking->dp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if(nums.empty())return 0;
        int n=nums.size();
    	int max_length=1;
    	vector<int>dp(n,1);
    	for(int i=0;i<n;i++){
    		for(int j=0;j<i;j++){
    			if(nums[j]<nums[i]){
    				dp[i]=max(dp[i],dp[j]+1);
    			}
    		}
    		max_length=max(max_length,dp[i]);
    	}
    	return max_length;
    }
};

//binary search
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if(nums.empty())return 0;
        int n=nums.size();

    	vector<int>res;
    	for(int i=0;i<n;i++){
    		auto it=lower_bound(res.begin(),res.end(),nums[i]);
    		if(it==res.end()){
    			res.push_back(nums[i]);
    		}else{
    			*it=nums[i];
    		}
    	}
    	return res.size();
    }
};