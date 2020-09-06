//
//  216_combination_sum_3.cpp
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
void combine(int k, int n,int l,vector<int>&subset,vector<vector<int>>&res){
    if(n==0&&k==0){
        // cout<<l<<" "<<endl;
        res.push_back(subset);
        return;
    }
    if(k<=0||n<=0||l>9)return;
    for(int i=l;i<=9;i++){
        if(n-i<0)continue;
        subset.push_back(i);
        // cout<<k<<" "<<n<<" "<<i<<" "<<l<<endl;
        combine(k-1, n-i, i+1, subset,res);
        subset.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int>subset;
    vector<vector<int>>res;
    combine(k, n, 1, subset, res);
    return res;
}
};
