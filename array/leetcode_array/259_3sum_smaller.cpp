//O(n^3)
class Solution {
public:
    void sum(vector<vector<int>>&res, vector<int> &subset, vector<int> nums, int index, int target){
        if(subset.size()==3){
            if(target>0){
                res.push_back(subset);
                // for(auto &x:subset){
                //     cout<<x<<" ";
                // }
                // cout<<endl;
                return;
            }else{
                return;
            }
			
		}
        
        if(index>=nums.size()){
            return;
        }
	

		for(int i=index;i<nums.size();i++){
            // cout<<target<<" "<<nums[i]<<" "<<subset.size()<<endl;
			subset.push_back(nums[i]);
			target-=nums[i];
			sum(res,subset,nums,i+1,target);
			target+=nums[i];
			subset.pop_back();
		}
	}
    int threeSumSmaller(vector<int>& nums, int target) {
    	if(nums.size()<3)return 0;
        vector<vector<int>>res;
        vector<int>subset;
        sum(res,subset,nums,0,target);
        return res.size();
    }
};



//two pointers O(n^2)
class Solution2 {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
    	if(nums.size()<3)return 0;

    	int n=nums.size();

    	sort(nums.begin(),nums.end());
    	int count=0;
    	for(int z=0;z+2<n;z++){
    		int i=z+1,j=n-1;
    		while(i<j){
    			if(nums[z]+nums[i]+nums[j]<target){
    				count+=j-i;
    				i++;
    			}else{
    				j--;
    			}
    		}
    	}
    	return count;
    }
};