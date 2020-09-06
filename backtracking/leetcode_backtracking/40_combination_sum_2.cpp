//
//  40_combination_sum_2.cpp
//  leetcode_backtracking
//
//  Created by Hadley on 24.08.20.
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
    void sumCombinations(vector<int>& candidates, vector<int> &subset, int l,int target, int cur){
        if(cur==target){
            res.push_back(subset);
            return;
        }
        if(cur>target){
            return;
        }
        for(int i=l;i<candidates.size();i++){
            if(map[candidates[i]]==0)continue;
            cur+=candidates[i];
            map[candidates[i]]--;
            subset.push_back(candidates[i]);
            sumCombinations(candidates, subset, i, target, cur);
            subset.pop_back();
            map[candidates[i]]++;
            cur-=candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for(auto x:candidates){
            map[x]++;
        }
        sort(candidates.begin(), candidates.end());
        candidates.resize(std::distance(candidates.begin(), std::unique(candidates.begin(), candidates.end())));
        
        
        vector<int>subset;
        sumCombinations(candidates, subset, 0, target, 0);
        return res;
    }
private:
    vector<vector<int>>res;
    unordered_map<int, int>map;
};

class Solution2 {
public:
    //count represent all positions from 0 to count that will be used to store value that accumulate to cur
    void sumCombinations(vector<int>& candidates, vector<vector<int>>&res, int l,int target, int cur, int count){
        if(cur==target){
            vector<int> temp(candidates.begin(), candidates.begin()+count);
            res.push_back(temp);
            return;
        }
        for(int i=l;i<candidates.size();i++){
            if(cur>target)break;
            cur+=candidates[i];
            swap(candidates[i], candidates[count]);
            sumCombinations(candidates, res, i+1, target, cur,count+1);
            swap(candidates[i],candidates[count]);
            cur-=candidates[i];
            while(i<candidates.size()-1&&candidates[i]==candidates[i+1])++i;
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        sumCombinations(candidates, res, 0, target, 0,0);
        return res;
    }
};
