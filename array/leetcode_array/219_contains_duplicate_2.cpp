//
//  219_contains_duplicate_2.cpp
//  leetcode_array
//
//  Created by Hadley on 18.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;



//using hashtable
class Solution219_1 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k<=0||nums.size()<=1){return false;}
        unordered_map<int, int>dist;
        unordered_map<int, int>prev;
        for(int i=0;i<nums.size();i++){
            if(!prev.count(nums[i])){prev[nums[i]]=i;}else{
                dist[nums[i]]=i-prev[nums[i]];
                prev[nums[i]]=i;
                if(dist[nums[i]]<=k){
                    return true;
                }
            }
        }
        return false;
    }
};


