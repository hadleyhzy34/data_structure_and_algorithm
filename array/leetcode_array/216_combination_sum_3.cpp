#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void sumCheck(std::vector<std::vector<int>> &res, std::vector<int> &subset, int k, int sum, int cur){
        if(k==0&&sum==0){
            // for(auto x:subset){
            //     cout<<x<<" ";
            // }
            // cout<<cur<<endl;
            res.push_back(subset);
            return;
        }
        if((k==0&&sum!=0)||cur>9||sum<0){
            return;
        }
        for(int i=cur;i<=9;i++){
            subset.push_back(i);
            sumCheck(res,subset,k-1,sum-i,i+1);
            subset.pop_back();
        }
    }
    std::vector<std::vector<int>> combinationSum3(int k,int n){
        std::vector<vector<int>> res;
        vector<int>subset;
        sumCheck(res,subset,k,n,1);
        return res;
    }
};