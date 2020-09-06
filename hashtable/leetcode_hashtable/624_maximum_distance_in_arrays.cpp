//
//  624_maximum_distance_in_arrays.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 15.08.20.
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
    int maxDistance(vector<vector<int>>& arrays) {
        auto m=arrays.size();
        int maxDis=0;
        for(int i=0;i<arrays.size();i++){
            for(int j=0;j<arrays.size();j++){
                if(i==j)continue;
                maxDis=max(maxDis,abs(arrays[i][0]-arrays[j][arrays[j].size()-1]));
            }
        }
        return maxDis;
    }
};

class Solution2 {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<vector<int>> t1=arrays,t2=arrays;
        
        sort(t1.begin(),t1.end(),[](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });
        // cout<<t1[0][0]<<" "<<t2[0][t2[0].size()-1]<<endl;
        sort(t2.begin(),t2.end(),[](vector<int>&a,vector<int>&b){
            return a[a.size()-1]>b[b.size()-1];
        });
        // cout<<t1[0][0]<<" "<<t2[0][t2[0].size()-1]<<endl;
        
        // cout<<t1[0].size()<<" "<<t2[0].size()<<endl;
        
        if(t1[0].size()!=t2[0].size()){
            // cout<<t1[0][0]<<" "<<t2[0][t2[0].size()-1]<<endl;
            return abs(t1[0][0]-t2[0][t2[0].size()-1]);
        }else if(t1[0]==t2[0]){
            // cout<<t1[0][0]<<" "<<t2[0][t2[0].size()-1]<<endl;
            return max(abs(t1[1][0]-t2[0][t2[0].size()-1]),abs(t1[0][0]-t2[1][t2[1].size()-1]));
        }else{
            // cout<<t1[0][0]<<" "<<t2[0][t2[0].size()-1]<<endl;
            return abs(t1[0][0]-t2[0][t2[0].size()-1]);
        }
    }
};


class Solution3 {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_val=arrays[0][0];
        int max_val=arrays[0][arrays[0].size()-1];
        int res=0;
        for(int i=1;i<arrays.size();i++){
            auto n=arrays[i].size();
            res=max(abs(min_val-arrays[i][n-1]),abs(max_val-arrays[i][0]));
            min_val=min(min_val,arrays[i][0]);
            max_val=min(max_val,arrays[i][n-1]);
        }
        return res;
    }
};
