//sort then reorder
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());

        bool s=true;
        int count=0;
        for(int i=0;i<nums.size();i++){
        	if(s){
        		nums[i]=temp[count];
        		s=false;
        	}else{
        		nums[i]=temp[nums.size()-1-count];
        		s=true;
        		count++;
        	}

        }
    }
};

//greedy
class Solution2 {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()<=1)return;
        bool less=true;
        for(int i=0;i<nums.size()-1;i++){
        	if(less){
        		if(nums[i]>nums[i+1]){
        			swap(nums[i],nums[i+1]);
        		}
        	}else{
        		if(nums[i]<nums[i+1]){
        			swap(nums[i],nums[i+1]);
        		}
        	}
        	less=!less;
        }
    }
};