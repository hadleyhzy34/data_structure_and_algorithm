//
//  77_combinations.cpp
//  leetcode_backtracking
//
//  Created by Hadley on 22.08.20.
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
    void combinations(int l,int r,int k,vector<int>subset){
        if(k==0){
            res.push_back(subset);
        }
        for(int i=l;i<=r;i++){
            subset.push_back(i);
            combinations(l+1, r,k-1,subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        combinations(1, n, k,subset);
        return res;
    }
private:
    vector<vector<int>>res;
    vector<int>subset;
};


class Solution2 {
public:
    void combinations(int l,int r,int k, int cur_index, vector<int>&subset,vector<vector<int>>&res){
        if(k==0){
            res.push_back(subset);
            return;
        }
        for(int i=l;i<=r;i++){
            subset[cur_index]=i;
            combinations(i+1, r,k-1,cur_index+1,subset,res);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>subset(k,0);
        vector<vector<int>>res;
        combinations(1, n, k,0,subset,res);
        return res;
    }
};
