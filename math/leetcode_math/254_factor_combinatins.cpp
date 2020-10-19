class Solution {
public:
	void factor(vector<vector<int>>& res, vector<int> &subset, vector<int> factors, int index, int target){
		if(target==1){
			res.push_back(subset);
			return;
		}

		for(int i=index;i<factors.size();i++){
			if(target%factors[i]!=0)continue;
			target/=factors[i];
			subset.push_back(factors[i]);
			factor(res,subset,factors,i,target);
			subset.pop_back();
			target*=factors[i];
		}
	}

    vector<vector<int>> getFactors(int n) {
        if(n<=1)return {};
    	vector<int> factors;
    	for(int i=2;i<n;i++){
    		if(n%i==0){
    			factors.push_back(i);
    		}
    	}
        vector<vector<int>>res;
        vector<int>subset;
        factor(res,subset,factors,0,n);
        return res;
    }
};