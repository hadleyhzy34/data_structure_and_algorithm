//
//  11_container_with_most_water.cpp
//  Leetcode_two_pointers
//
//  Created by Hadley on 14.08.20.
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
    int maxArea(vector<int>& height) {
        auto n=height.size();
        int i=0,j=0;
        int maxWater=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                maxWater=max(maxWater,min(height[i],height[j])*(j-i));
            }
        }
        return maxWater;
    }
};

class Solution2 {
public:
    int maxArea(vector<int>& height) {
        auto n=height.size();
        vector<vector<int>> L(n,vector<int>(n,0));
        for(int l=1;l<n;l++){
            for(int i=0;i+l<n;i++){
                if(height[i]<height[i+l]){
                    L[i][i+l]=max(L[i+1][i+l],height[i]*l);
                }else if(height[i]>height[i+l]){
                    L[i][i+l]=max(L[i][i+l-1],height[i+l]*l);
                }else{
                    L[i][i+l]=max(max(L[i][i+l-1],L[i+1][i+l]),height[i]*l);
                }
//                L[i][i+l]=max(max(L[i][i+l-1],L[i+1][i+l]),min(height[i],height[i+l])*(l));
//                cout<<i<<" "<<i+l<<" "<<L[i][i+l]<<endl;
            }
        }
        return L[0][n-1];
    }
};

class Solution3 {
public:
    int maxArea(vector<int>& height) {
        auto n=height.size();
        int l=0,r=n-1;
        int maxArea=0;
        while(l<r){
            maxArea=max(maxArea,min(height[l],height[r])*(r-l));
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxArea;
    }
};

