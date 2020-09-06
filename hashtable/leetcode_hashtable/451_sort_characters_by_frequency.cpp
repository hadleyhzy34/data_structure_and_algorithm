//
//  451_sort_characters_by_frequency.cpp
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
    string frequencySort(string s) {
        unordered_map<char, string>map;
        for(int i=0;i<s.length();i++){
            map[s[i]].push_back(s[i]);
        }
        unordered_map<int, string>m;
        for(auto x:map){
            m[x.second.length()].append(x.second);
        }
        string res;
        for(int i=1;i<s.length();i++){
            if(m.find(i)!=m.end()){
                res.append(m[i]);
            }
        }
        return res;
};

class Solution2 {
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
