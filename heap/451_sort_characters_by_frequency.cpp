class Solution {
public:
    string frequencySort(string s) {
        string map[128];
        for(int i=0;i<s.length();i++){
            map[s[i]].push_back(s[i]);
            // cout<<i<<" "<<(int)s[i]<<" "<<map[s[i]]<<endl;
        }
        
        auto compare = [](pair<char, string> const & l, pair<char, string> const & r) -> bool {
            return l.second.length()<r.second.length();
        };
        
        
        priority_queue<pair<char,string>,vector<pair<char,string>>,decltype(compare)> Q(compare);
        
        for(int i=0;i<128;i++){
            if(!map[i].empty()){
                Q.emplace(i,map[i]);
                // cout<<i<<" "<<Q.top().first<<" "<<Q.top().second<<endl;
            }
        }
        
        
        string res;
        while(!Q.empty()){
            res.append(Q.top().second);
            Q.pop();
        }
        return res;
    }
};

class Solution2 {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char,int>map;
        priority_queue<pair<int,char>>pq;
        for(auto ss:s){
            map[ss]++;
        }
        for(auto x:map){
            pq.push(make_pair(x.second,x.first));
        }
        while(!pq.empty()){
            res.append(pq.top().first,pq.top().second);
            pq.pop();
        }
        return res;
    }
};