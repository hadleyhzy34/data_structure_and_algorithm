class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.empty())return 0;
        vector<unordered_set<char>>map(words.size());
        for(int i=0;i<words.size();i++){
        	for(int j=0;j<words[i].size();j++){
        		if(map[i].find(words[i][j])==map[i].end()){
        			map[i].insert(words[i][j]);
        		}
        	}
        }
        int maxLength=0;
        for(int i=0;i<words.size()-1;i++){
        	for(int j=i+1;j<words.size();j++){
        		int temp=1;
                // for(auto it=map[i].begin();it!=map[i].end();it++){
                //     if(map[j].find(*it)!=map[j].end()){
                //         temp=0;
                //     }
                // }
                for(auto &m:map[i]){
                    if(map[j].find(m)!=map[j].end()){
                        temp=0;
                    }
                }
        		if(temp==1){
                    temp=words[i].size()*words[j].size();
                    // cout<<temp<<" "<<i<<" "<<j<<endl;
                }
        		maxLength=max(maxLength,temp);
        	}
        }

        return maxLength;
    }
};

//how to fast compare two strings->try to compare using only O(1) time
//try to convert strign to int and use bit mask and operator
//bit manipulation using bit mask
class Solution2 {
public:
    int maxProduct(vector<string>& words) {
        if(words.empty())return 0;
        vector<int>bitmask(words.size(),0);

        for(int i=0;i<words.size();i++){
        	for(int j=0;j<words[i].size();j++){
                // cout<<words[i][j]<<words[i][j]-'a'<<endl;
                if((bitmask[i]&(1<<words[i][j]-'a'))==0){
                    bitmask[i]+=1<<(words[i][j]-'a');
                }
        	}
        }
        int maxLength=0;
        for(int i=0;i<words.size()-1;i++){
        	for(int j=i+1;j<words.size();j++){
       			if((bitmask[i]&bitmask[j])==0){
       				maxLength=max(maxLength,int(words[i].size()*words[j].size()));
       			}
        	}
        }

        return maxLength;
    }
};