//
//  162_find_peak_element.cpp
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
    int findPeakElement(vector<int>& nums) {
        auto size=nums.size();
        vector<vector<int>> n;
        for(int i=0;i<nums.size();i++){
            n.push_back({nums[i],i});
        }
        
        sort(n.begin(),n.end(),[](vector<int> &a,vector<int> &b){return a[0]>b[0];});
        
        int l=0;
        int r=size-1;
        for(int i=0;i<size;i++){
            if(n[i][1]!=l&&n[i][1]!=r){
                return n[i][1];
            }else if(n[i][1]==l){
                l++;
            }else if(n[i][1]==r){
                r--;
            }
        }
        return -1;
    }
};
