//
//  347_top_k_frequent_elements.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 19.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <queue>
#include <functional>
#include <numeric>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int>map1;

        for(int i=0;i<nums.size();i++){
            map1[nums[i]]++;
        }
        unordered_map<int, vector<int>>map2;
        for(auto &x:map1){
            map2[x.second].push_back(x.first);
        }
        
        int count=0;
        for(int i=nums.size();i>0&&count<k;i--){
            if(!map2[i].empty()){
                res.insert(res.end(), map2[i].begin(),map2[i].end());
                auto n=map2[i].size();
                count+=n;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int>map1;

        for(int i=0;i<nums.size();i++){
            map1[nums[i]]++;
        }
        
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &x:map1){
            if(pq.size()<k){
                pq.push(x.second);
            }else{
                if(pq.top()<x.second){
                    pq.pop();
                    pq.push(x.second);
                }
            }
        }
        
        for(auto x:map1){
            if(x.second>=pq.top()){
                res.push_back(x.first);
            }
        }
        return res;
    }
};

class Solution3 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int>map1;

        for(int i=0;i<nums.size();i++){
            map1[nums[i]]++;
        }
        
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>pq;
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
