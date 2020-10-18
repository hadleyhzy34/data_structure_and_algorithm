//backtracking
class Solution {
public:
    void sum(vector<vector<int>> &res, vector<int> &subset, vector<int> nums, int index, int cur){
        if(cur==0&&subset.size()==3){
            res.push_back(subset);
            return;
        }else if(cur!=0&&subset.size()==3){
            return;
        }
        if(cur>0){
            return;
        }
        if(index==nums.size()){
            return;
        }
        for(int i=index;i<nums.size();i++){
            int j=i;
            while(i<nums.size()-1&&nums[i]==nums[i+1])i++;
            cur+=nums[i];
            subset.push_back(nums[i]);
            sum(res,subset,nums,j+1,cur);
            subset.pop_back();
            cur-=nums[i];
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>subset;
        sort(nums.begin(),nums.end());
        sum(res,subset,nums,0,0);
        return res;
    }
};


class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int,vector<int>>two;
        unordered_map<int,int>one;
        int n=nums.size();
        for(int i=0;i<n;i++){
            one[nums[i]]=i;
            int temp=i;
            while(nums)
            for(int j=i+1;j<n;j++){
                two[nums[i]+nums[j]]={i,j};
            }
        }

        for(auto &x:two){
            if(one.find(-x.first)!=one.end()){
                if(one[-x.first]!=two[x.first][0]&&one[-x.first]!=two[x.first][1]){
                    vector<int> subset={nums[one[-x.first]],nums[two[x.first][0]],nums[two[x.first][1]]};
                    res.push_back(subset);
                }
            }
        }
        return res;
    }
};

