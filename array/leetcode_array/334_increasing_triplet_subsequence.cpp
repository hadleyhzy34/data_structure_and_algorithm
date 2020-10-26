//linear scan, set three different variables to inspect states
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int first=INT_MAX,second=INT_MAX;
        for(int i=0;i<nums.size();i++){
        	if(nums[i]<=first){
        		first=nums[i];
        	}else if(nums[i]<=second){
        		second=nums[i];
        	}else{
        		return true;
        	}
        }
        return false;
    }
};