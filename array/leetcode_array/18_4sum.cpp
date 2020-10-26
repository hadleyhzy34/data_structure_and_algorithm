class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<vector<int>> res;
        sort(nums.begin(),nums.end());

        int i=0,j=nums.size()-1;
        while(i+2<j){
        	int m=i+1,n=i+2;
        	while(m<j&&n<j){
        		if(nums[i]+nums[m]+nums[n]+nums[j]==target){
        			res.push_bacl({nums[i],nums[m],nums[n],nums[j]});
        		}else{
        			
        		}
        	}
        }
        return res;
    }
};