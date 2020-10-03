//
//  11_container_with_most_water.cpp
//  leetcode_array
//
//  Created by Hadley on 02.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int l=0,r=height.size()-1;
        while(l<r){
            maxArea=max(maxArea,min(height[l],height[r])*(r-l));
            if(height[l]<height[r]){
                //maxArea[l,r] is always larger than maxArea[l,r--], only change l could lead maxarea to be larger than current maxArea[l,r]Arr
                l++;
            }else{
                //maxArea[l,r] is always larger than maxArea[l++,r];
                r--;
            }
        }
        return maxArea;
    }
};
