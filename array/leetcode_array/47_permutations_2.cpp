//
//  47_permutations_2.cpp
//  leetcode_array
//
//  Created by Hadley on 03.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/stdc++.h"
using namespace std;

class Solution1 {
public:
       bool check(vector<int>& nums, int i , int begin){
            for(int k = begin; k<i; k++)
                if(nums[i] == nums[k]){
                    for(auto &x:nums){
                        cout<<x<<" ";
                    }
                    cout<<endl<<begin<<" "<<i<<" "<<k<<endl;
                    return false;
                }
            return true;
        }
        
        void permutations(vector<int>& nums, int l){
            for(int i=l;i<nums.size();i++){
                //it's not workign to prevent swap duplicated element since current sequence swapped and it's not sorted
    //            if(i>l&&nums[i]==nums[i-1]){
    //                continue;
    //            }
                if((l==i||nums[l]!=nums[i])&&check(nums,i,l)){
                    swap(nums[l],nums[i]);
                    permutations(nums, l+1);
                    if(l==nums.size()-1){
                        res.push_back(nums);
                    }
                    swap(nums[l],nums[i]);
                }
            }
        }
        
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            permutations(nums, 0);
            return res;
        }
    private:
        vector<vector<int>>res;
};

//abcde
//pass by value at index=0:a->b,b->c,c->d,d->e
//pass by reference at index=0:a->b,a->c,a->d,a->e

//pass by value to prevent cases like:abb, a->b,a->b
//instead, a->b, b->?, since nums[i]==nums[l], continue

class Solution2 {
public:
        void permutations(vector<int> nums, int l){
            for(int i=l;i<nums.size();i++){
                if(i!=l&&nums[i]==nums[l])continue;
                swap(nums[l],nums[i]);
                permutations(nums, l+1);
                if(l==nums.size()-1){
                    res.push_back(nums);
                }
            }
        }
        
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            permutations(nums, 0);
            return res;
        }
private:
        vector<vector<int>>res;
};
