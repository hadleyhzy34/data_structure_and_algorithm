//
//  350_intersection_of_two_arrays.cpp
//  leetcode_sort
//
//  Created by Hadley on 08.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>umap;
        vector<int>res;
        for(int i=0;i<nums1.size();i++){
            umap[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
                if(umap[nums2[i]]){
                    res.push_back(nums2[i]);
                    umap[nums2[i]]--;
                }
        }
        return res;
    }
};
