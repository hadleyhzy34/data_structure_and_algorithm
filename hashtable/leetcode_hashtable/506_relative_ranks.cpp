//
//  506_relative_ranks.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 01.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end(),greater<int>());
        unordered_map<int,int>map;
        for(int i=0;i<temp.size();i++){
            map[temp[i]]=i+1;
        }
        
        vector<string>res;
        
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]]==1){
                res.push_back("Gold Medal");
            }else if(map[nums[i]]==2){
                res.push_back("Silver Medal");
            }else if(map[nums[i]]==3){
                res.push_back("Bronze Medal");
            }else{
                res.push_back(to_string(map[nums[i]]));
            }
        }
        
        return res;
    }
};
