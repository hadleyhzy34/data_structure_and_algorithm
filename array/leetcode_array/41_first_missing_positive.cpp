//hash map
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
        	map[nums[i]]++;
        }
        for(int i=1;i<=INT_MAX;i++){
        	if(map.find(i)==map.end()){
        		return i;
        	}
        }
        return 0;
    }
};

//O(1) space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
        	if(nums[i]<=0){
        		nums[i]=n+1;
        	}
        }

        for(int i=0;i<n;i++){
        	if(abs(nums[i])<=n&&nums[abs(nums[i]) - 1] >0){
        		nums[abs(nums[i])-1]*=-1;
        	}
        }

        for(int i=0;i<n;i++){
        	if(nums[i]>0){
        		return i+1;
        	}
        }

    	return n+1;
    }
};