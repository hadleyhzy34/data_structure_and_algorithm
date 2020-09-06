//
//  46_permutations.cpp
//  leetcode_backtracking
//
//  Created by Hadley on 20.08.20.
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
    void permu(vector<int>& nums, vector<int> &p){
        if(nums.size()==0){
            res.push_back(p);
        }
        for(int i=0;i<nums.size();i++){
            vector<int>ntemp=nums;
            vector<int>temp=p;
            temp.push_back(nums[i]);
            ntemp.erase(ntemp.begin()+i);
            permu(ntemp, temp);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp=nums;
        vector<int> ptemp;
        permu(temp, ptemp);
        // for(auto x:res){
        //     for(auto s:x){
        //         cout<<s<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<res.size()<<endl;
        return res;
    }
    private:
    vector<vector<int>>res;
};

class Solution2 {
public:
    void permu(vector<int>& nums, vector<int> &p){
        if(p.size()==nums.size()){
            res.push_back(p);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==INT_MAX)continue;

            p.push_back(nums[i]);
            int temp=nums[i];
            nums[i]=INT_MAX;
            permu(nums, p);
            nums[i]=temp;
            p.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>cur={};
        permu(nums,cur);
        return res;
    }
private:
    vector<vector<int>>res;
};

class Solution3 {
public:
    void permu(vector<int>& nums, vector<bool> &p){
        if(subset.size()==nums.size()){
            res.push_back(subset);
        }
        for(int i=0;i<nums.size();i++){
            if(p[i]==false)continue;

            subset.push_back(nums[i]);
            p[i]=false;
            permu(nums, p);
            p[i]=true;
            subset.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>cur(nums.size(),true);
        permu(nums,cur);
        return res;
    }
private:
    vector<vector<int>>res;
    vector<int>subset;
};

class Solution4 {
public:
    void permu(vector<int>& nums,int l, int r){
        if(l==r){
            res.push_back(nums);
        }
        for(int i=l;i<=r;i++){
            swap(nums[l], nums[i]);
            permu(nums, l+1, r);
            swap(nums[i], nums[l]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permu(nums,0,nums.size()-1);
        return res;
    }
private:
    vector<vector<int>>res;
};

