//
//  360_sort_transformed_array.cpp
//  leetcode_math
//
//  Created by Hadley on 12.08.20.
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
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if(a==0){
            if(b<0){
                reverse(nums.begin(),nums.end());
            }
            for(auto &x:nums){
                x=b*x+c;
            }
            return nums;
        }
        double m=-(double)(b)/(2*(double)(a));
        vector<int> res;
        double p=abs((double)nums[0]-m);
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(p>abs((double)nums[i]-m)){
                p=abs((double)nums[i]-m);
                index=i;
            }
        }
        // cout<<index<<" "<<m<<endl;
        res.push_back(a*nums[index]*nums[index]+b*nums[index]+c);
        int l=index-1;
        int r=index+1;
        while(l>=0||r<nums.size()){
            // cout<<l<<" "<<r<<" ";
            if(l>=0&&r<nums.size()){
                // cout<<(double)nums[r]-m<<" "<<m-(double)nums[l]<<endl;
                if((double)nums[r]-m<m-(double)nums[l]){
                    res.push_back(a*nums[r]*nums[r]+b*nums[r]+c);
                    r++;
                }else{
                    res.push_back(a*nums[l]*nums[l]+b*nums[l]+c);
                    l--;
                }
            }else if(l>=0&&r>=nums.size()){
                res.push_back(a*nums[l]*nums[l]+b*nums[l]+c);
                l--;
            }else if(l<0&&r<nums.size()){
                res.push_back(a*nums[r]*nums[r]+b*nums[r]+c);
                r++;
            }
        }
        
        if(a<0)reverse(res.begin(), res.end());
        return res;
    }
};
