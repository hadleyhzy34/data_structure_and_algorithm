//
//  436_find_right_interval.cpp
//  binary_search
//
//  Created by Hadley on 11.08.20.
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
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        auto n=intervals.size();
        vector<int> res(n,-1);
        int temp=intervals[0][0];
        for(int i=0;i<n;i++){
            temp=max(temp,intervals[i][0]);
        }
        
        for(int i=0;i<n;i++){
            int t=temp;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(intervals[i][1]<=intervals[j][0]){
                    if(t>=intervals[j][0]){
                        t=intervals[j][0];
                        res[i]=j;
                    }
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        auto n=intervals.size();
        vector<int> res(n,-1);
        vector<vector<int>> inter=intervals;
        for(int i=0;i<intervals.size();i++){
            inter[i][1]=i;
        }
        
        sort(inter.begin(), inter.end(), [](vector<int>&a,vector<int>&b){return a[0]<b[0];});
        
        for(int i=0;i<n;i++){
            int l=0;
            int r=n-1;
            while(l<=r){
                int m=l+(r-l)/2;
                if(intervals[i][1]==inter[m][0]){
                    res[i]=inter[m][1];
                    break;
                }else if(intervals[i][1]<inter[m][0]){
                    if(m==0||intervals[i][1]>inter[m-1][0]){
                        res[i]=inter[m][1];
                        break;
                    }else{
                        r=m-1;
                    }
                }else{
                    l=m+1;
                }
            }
        }
        return res;
    }
};
