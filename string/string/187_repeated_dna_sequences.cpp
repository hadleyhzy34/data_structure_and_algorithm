class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        unordered_map<string, int>map;
        for(int i=0;i<s.length();i++){
            if(i<9){
                continue;
            }else{
                if(map.find(s.substr(i-10+1,10))!=map.end()){
                    if(map[s.substr(i-10+1,10)]==1){
                        res.push_back(s.substr(i-10+1,10));
                    }
                }
                map[s.substr(i-10+1,10)]++;
            }
        }
        return res;
    }
};


class Solution2 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>map;
        vector<string> res;
        for(int i=0;i+9<s.size();i++){
            if(map.find(s.substr(i,10))!=map.end()&&map[s.substr(i,10)]==1){
                map[s.substr(i,10)]++;
                res.push_back(s.substr(i,10));
            }else{
                map[s.substr(i,10)]++;;
            }
        }
        return res;
    }
};







