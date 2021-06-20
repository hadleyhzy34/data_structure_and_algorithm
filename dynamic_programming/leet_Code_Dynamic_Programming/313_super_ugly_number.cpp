class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>dp(primes.size(),0);
        int count=1;
        vector<int>res;
        res.push_back(1);
        for(int i=2;i<=n;i++){
        	int candidate=INT_MAX;
        	vector<int>index;
        	for(int j=0;j<dp.size();j++){
        		if(res[dp[j]]*primes[j]<candidate){
        			candidate=res[dp[j]]*primes[j];
        			index={j};
        		}else if(res[dp[j]]*primes[j]==candidate){
        			index.push_back(j);
        		}
        	}
        	for(auto x:index){
        		dp[x]++;
        	}
        	res.push_back(candidate);
        }
        // for(auto r:res){
        //     cout<<r<<" ";
        // }
        return res[res.size()-1];
    }
};