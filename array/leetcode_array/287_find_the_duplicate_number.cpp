class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    	int n=nums.size();
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
        	map[nums[i]]++;
        	if(map[nums[i]]==2){
        		return nums[i];
        	}
        }
        return 0;
    }
};