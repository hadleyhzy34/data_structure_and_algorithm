class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
        	if(nums[i]==INT_MAX)continue;
        	int start=nums[i],count;
        	while(nums[start]!=INT_MAX){
        		int temp=start;
        		start=nums[start];
        		count++;
        		nums[temp]=INT_MAX;
        	}
        	res=max(res,count);
        }
        return res;
    }
};