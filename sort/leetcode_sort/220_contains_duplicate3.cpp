//
//  220_contains_duplicate3.cpp
//  leetcode_sort
//
//  Created by Hadley on 22.06.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        #define ll long long
        if(!k)return false;
        for(int i=0;i<nums.size()-1;i++){
            int j=1;
            while((i+j<nums.size())&&j<=k){
                ll A=nums[i];
                ll B=nums[i+j];
                if(abs(A-B)<=t){
                    return true;
                }
                j++;
            }
        }
        return false;
    }
};


class Solution2 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int,int>> temp;
        //its very important to define sz since nums.size() is unsigned type, if input vector is [], then nums.size would be 0, and nums.size()-1 would be 18446744073709551615
        int sz = nums.size();
        for(int i=0;i<nums.size();i++){
            temp.push_back(make_pair(nums[i],i));
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(temp[i].first+t<temp[j].first)
                    break;
                if(abs(temp[j].second-temp[i].second)<=k){
                    return true;
                }
            }
        }
        return false;
    }
};
