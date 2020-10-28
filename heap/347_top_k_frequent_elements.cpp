class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int>map1;

        for(int i=0;i<nums.size();i++){
            map1[nums[i]]++;
        }
        
        priority_queue<pair<int, int>,vector<pair<int, int>>,auto(*)(pair<int,int>,pair<int,int>)->bool>pq{
            [](pair<int,int>&a,pair<int,int>&b)->bool{return a.second<b.second;}
        for(auto &x:map1){
            pair<int, int>temp=make_pair(x.second, x.first);
            if(pq.size()<k){
                pq.push(temp);
            }else{
                if(pq.top().first<x.second){
                    pq.pop();
                    pq.push(temp);
                }
            }
        }
        
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};


class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        priority_queue<pair<int,int>>pq;
        for(auto x:nums){
            map[x]++;
        }
        vector<int>res;
        for(auto x:map){
            pq.push(make_pair(x.second,x.first));
            if(pq.size()>map.size()-k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};