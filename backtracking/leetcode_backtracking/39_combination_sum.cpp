//
//  39_combination_sum.cpp
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
            cur+=candidates[i];
            subset.push_back(candidates[i]);
            sumCombinations(candidates, subset, i, target, cur);
            subset.pop_back();
            cur-=candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>subset;
        sumCombinations(candidates, subset, 0, target, 0);
        return res;
    }
private:
    vector<vector<int>>res;
};
