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