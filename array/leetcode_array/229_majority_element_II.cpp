class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>map;
        vector<int> res;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
        	map[nums[i]]++;
        	if(map[nums[i]]==n/3+1){
        		res.push_back(nums[i]);
        	}
        }
        return res;
    }
};

//boyer-moore voting algorithm
//note that there at most two majority elements that appear more than n/3 times
//the true theory here is that count1 can be decremented less than half of 2/3 * n times 
//if first candidate has more than n/3 elements
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //count
        int count1=0,count2=0;
        //candidate
        int candidate1=INT_MIN,candidate2=INT_MIN;

        for(int i=0;i<nums.size();i++){
        	if(candidate1!=INT_MIN&&candidate1==nums[i]){
        		count1++;
        	}else if(candidate2!=INT_MIN&&candidate2==nums[i]){
        		count2++;
        	}else if(count1==0){
        		candidate1=nums[i];
        		count1++;
        	}else if(count2==0){
        		candidate2=nums[i];
        		count2++;
        	}else{
        		count1--;
        		count2--;
        	}
        }

        vector<int> res;
        count1=0,count2=0;
        for(int i=0;i<nums.size();i++){
        	if(nums[i]==candidate1)count1++;
        	if(nums[i]==candidate2)count2++;
        }
        if(count1>nums.size()/3)res.push_back(candidate1);
        if(count2>nums.size()/3)res.push_back(candidate2);
        return res;
    }
};