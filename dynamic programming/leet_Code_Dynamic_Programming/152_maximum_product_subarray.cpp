//
//  152_maximum_product_subarray.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 15.07.20.
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
    int maxProduct(vector<int>& nums) {
        if(nums.empty())return 0;
        if(nums.size()==1)return nums[0];
        auto n=nums.size();
        
        vector<int> large(n,0);
        vector<vector<int>> largeValue(n,large);
        
        int largest=nums[0];
        for(int i=0;i<n;i++){
            largeValue[i][i]=nums[i];
            if(largest<largeValue[i][i])largest=largeValue[i][i];
        }
        
        for(int l=2;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                largeValue[i][i+l-1]=largeValue[i][i+l-2]*largeValue[i+l-1][i+l-1];
                if(largest<largeValue[i][i+l-1])largest=largeValue[i][i+l-1];
            }
        }
        return largest;
    }
};

//Solution2:
//if(nums.empty()) return 0;
//int currmax=nums[0],currmin=nums[0],finalAns=nums[0];
//for(int i=1;i<nums.size();i++){
//    int temp=currmax;
//    currmax=max({temp*nums[i],currmin*nums[i],nums[i]});
//    currmin=min({temp*nums[i],currmin*nums[i],nums[i]});
//    finalAns=max(currmax,finalAns);
//
//}
//return finalAns;
