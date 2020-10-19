class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)return 0;

    	int n=nums.size();

    	sort(nums.begin(),nums.end());
        int res=nums[0]+nums[1]+nums[2];

    	for(int z=0;z+2<n;z++){
    		int i=z+1,j=n-1;
    		while(i<j){
    			if(abs(nums[z]+nums[i]+nums[j]-target)<abs(res-target)){
    				res=nums[z]+nums[i]+nums[j];
                    cout<<nums[z]<<" "<<nums[i]<<" "<<nums[j]<<endl;
    				if(res==target){
    					return res;
    				}
    			}
    			if(nums[z]+nums[i]+nums[j]-target>0){
    				j--;
    			}else{
    				i++;
    			}
    		}
    	}
    	return res;
    }
};