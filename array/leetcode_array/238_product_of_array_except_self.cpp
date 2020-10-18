class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        for(int i=1;i<n;i++){
        	left[i]=left[i-1]*nums[i-1];
        }

        for(int i=n-2;i>=0;i--){
        	right[i]=right[i+1]*nums[i+1];
	    }

	    vector<int>res;

        for(int i=0;i<n;i++){
        	res.push_back(left[i]*right[i]);
        }
        return res;
    }
};


class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();


	    vector<int>res(n,1);

        vector<int>left(n,1);
        vector<int>right(n,1);
        for(int i=1;i<n;i++){
        	res[i]=res[i-1]*nums[i-1];
        }

        int right=1;
        for(int i=n-1;i>=0;i--){
        	right[i]=right[i]*right;
        	right*=nums[i];
	    }

        return res;
    }
};