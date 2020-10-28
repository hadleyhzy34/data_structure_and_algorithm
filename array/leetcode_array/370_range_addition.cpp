class Solution3 {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int>res(length,0);
        for(auto x:updates){
        	res[x[0]]+=x[3];
        	if(x[1]+1<length)res[x[1]+1]-=x[3];
        }

        for(int i=1;i<length;i++){
        	res[i]+=res[i-1];
        }
        return res;
    }
};