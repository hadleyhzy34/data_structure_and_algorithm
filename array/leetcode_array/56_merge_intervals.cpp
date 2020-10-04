//
//  56_merge_intervals.cpp
//  leetcode_array
//
//  Created by Hadley on 03.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//


#include <stdio.h>
#include "/usr/local/include/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });
        vector<vector<int>>res;
        for(int i=0;i<intervals.size();i++){
            if(i==0){
                res.push_back(intervals[0]);
            }else{
                if(intervals[i][0]<=res[res.size()-1][1]){
                    if(intervals[i][1]<=res[res.size()-1][1]){
                        continue;
                    }else{
                        res[res.size()-1][1]=intervals[i][1];
                    }
                }else{
                    res.push_back(intervals[i]);
                }
            }
        }
        return res;
    }
};

