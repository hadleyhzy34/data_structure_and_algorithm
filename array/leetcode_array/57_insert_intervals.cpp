//
//  57_insert_intervals.cpp
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>>res;
        
        //insert interval and sort interval
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });
        
        //create a new vector to merge interval
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

class Solution2 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>>res;
        int index=0;
        int n=intervals.size();
        
        while(index<n&&newInterval[0]>intervals[index][1]){
            res.push_back(intervals[index++]);
        }
        
        while(index<n&&newInterval[1]>=intervals[index][0]){
            newInterval[0]=min(newInterval[0],intervals[index][0]);
            newInterval[1]=max(newInterval[1],intervals[index][1]);
            index++;
        }
        res.push_back(newInterval);
        while(index<n){
            res.push_back(intervals[index++]);
        }
        
        return res;
    }
};
