//
//  88_merge_sorted_array.cpp
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin()+m,nums1.begin()+m+n-1);
        nums1.insert(nums1.end(), nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
    }
};

class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        int i=0,j=0;
        while(i<m||j<n){
            cout<<i<<" "<<j<<endl;
            if(i>=m){
                nums3.push_back(nums2[j]);
                j++;
            }else if(j>=n){
                nums3.push_back(nums1[i]);
                i++;
            }else if(nums1[i]<nums2[j]){
                nums3.push_back(nums1[i]);
                i++;
            }else{
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        nums1=nums3;
    }
};
