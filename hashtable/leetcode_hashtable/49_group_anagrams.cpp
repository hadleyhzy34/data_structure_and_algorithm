//
//  49_group_anagrams.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 18.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<unordered_map<char, int>>dict;
        vector<vector<string>>res;
        for(int i=0;i<strs.size();i++){
            unordered_map<char, int>temp;
            for(int j=0;j<strs[i].length();j++){
                temp[strs[i][j]]++;
            }
            if(dict.empty()){
                dict.push_back(temp);
                res.push_back({strs[i]});
            }else{
                vector<unordered_map<char, int>>::iterator it=find(dict.begin(), dict.end(), temp);
                if(it==dict.end()){
                    dict.push_back(temp);
                    res.push_back({strs[i]});
                }else{
                    res[it-dict.begin()].push_back(strs[i]);
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> dict;
        vector<vector<string>>res;
        for(int i=0;i<strs.size();i++){
            vector<int> temp(26,0);
            for(int j=0;j<strs[i].length();j++){
                temp[strs[i][j]-'0']++;
            }
            if(dict.empty()){
                dict.push_back(temp);
                res.push_back({strs[i]});
            }else{
                vector<vector<int>>::iterator it=find(dict.begin(),dict.end(),temp);
                if(it==dict.end()){
                    dict.push_back(temp);
                    res.push_back({strs[i]});
                }else{
                    res[it-dict.begin()].push_back(strs[i]);
                }
            }
        }
        return res;
    }
};

class Solution3 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string, int>map;

        int count=0;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            if(map.find(temp)==map.end()){
                map[temp]=count;
                res.push_back({strs[i]});
                count++;
            }else{
                res[map[temp]].push_back(strs[i]);
            }
        }
        return res;
    }
};
