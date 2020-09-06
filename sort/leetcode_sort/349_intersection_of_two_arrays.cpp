//
//  349_intersection_of_two_arrays.cpp
//  leetcode_sort
//
//  Created by Hadley on 08.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        nums1.erase(unique(nums1.begin(), nums1.end()),nums1.end());
        nums2.erase(unique(nums2.begin(), nums2.end()),nums2.end());
        vector<int>output;
        for(auto it=nums1.begin();it!=nums1.end();it++){
            auto t=find(nums2.begin(),nums2.end(),*it);
            if(t!=nums2.end()){
                output.push_back(*it);
            }
        }
        return output;
    }
};
