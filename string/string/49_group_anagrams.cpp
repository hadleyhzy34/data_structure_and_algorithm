//
//  49_group_anagrams.cpp
//  string
//
//  Created by Hadley on 02.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>m;
        for(auto &s:strs){
            string temp=s;
            sort(s.begin(),s.end());
            m[s].push_back(temp);
        }
        vector<vector<string>>res;
        for(auto &x:m){
            res.push_back(x.second);
        }
        return res;
    }
};
