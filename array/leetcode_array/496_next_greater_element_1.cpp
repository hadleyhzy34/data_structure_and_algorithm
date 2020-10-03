//
//  496_next_greater_element_1.cpp
//  leetcode_array
//
//  Created by Hadley on 01.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    int k=j;
                    while(k<nums2.size()&&nums2[j]>=nums2[k])k++;
                    res.push_back(k);
                    break;
                }
            }
        }
        return res;
    }
};

//using stack
//Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
//Output: [-1,3,-1]
class Solution2 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int>m;
        for(auto n:nums2){
            while(s.size()&&s.top()<n){
                m[s.top()]=n;
                s.pop();
            }
            s.push(n);
        }
        
        vector<int>res;
        for(auto n:nums1){
            if(m.find(n)!=m.end()){
                res.push_back(m[n]);
            }else{
                res.push_back(-1);
            }
        }
        return res;
        
    }
};
