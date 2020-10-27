class NumArray {
public:
    NumArray(vector<int>& nums) {
        this->nums=nums;
    }
    
    void update(int i, int val) {
        this->nums[i]=val;
    }
    
    int sumRange(int i, int j) {
    	int sum=0;
        for(int x=i;x<=j;x++){
            // cout<<nums[x]<<" ";
        	sum+=nums[x];
        }
        return sum;
    }
private:
	vector<int> nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */


class NumArray2 {
public:
    NumArray(vector<int>& nums) {
        this->nums=nums;
        sums.resize(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i==0){
                sums[i]=nums[i];
            }else{
                sums[i]=sums[i-1]+nums[i];
            }
        }
    }
    
    void update(int i, int val) {
        int diff=val-nums[i];
        nums[i]=val;
        // cout<<diff<<" "<<sums[i]<<" "<<i<<endl;
        for(int j=i;j<nums.size();j++){
            sums[j]+=diff;
            // cout<<j<<" "<<sums[j]<<" "<<val<<" "<<diff<<endl;
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j]-sums[i]+nums[i];
    }
private:
    vector<int> nums;
    vector<int> sums;
};