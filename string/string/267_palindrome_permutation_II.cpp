class Solution {
public:
    void palindrome(vector<string>&res,string subset,int index, char single){
		if(index==subset.size()-1){
			string temp=subset;
			reverse(temp.begin(),temp.end());
            string r;
            if(isspace(single)){
                r=subset+temp;
            }else{
                r=subset+single+temp;
            }
            // cout<<subset<<" "<<temp<<" "<<r<<endl;
			res.push_back(r);
		}
		for(int i=index;i<subset.size();i++){
			if(subset[i]==subset[index]&&i!=index)continue;
			swap(subset[index],subset[i]);
			palindrome(res,subset,index+1,single);
		}
	}
    vector<string> generatePalindromes(string s) {
        unordered_map<char,int>map;
        string subset;

        for(auto ss:s){
        	map[ss]++;
        	if(map[ss]%2==0){
        		subset+=ss;
        	}
        }
        
        sort(subset.begin(),subset.end());
        
        char single=' ';
        int count=0;
        for(auto x:map){
            if(x.second%2!=0){
                if(count==0){
                    single=x.first;
                    count++;
                }else{
                    return {};
                }
            }
        }
        if(subset.empty()){
            return {string(1,single)};
        }
        // cout<<single<<endl;
        // for(auto &x:subset){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        vector<string>res;
        palindrome(res,subset,0,single);
        return res;
    }
};