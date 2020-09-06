//
//  88_merge_sorted_array.cpp
//  leetcode_array
//
//  Created by Hadley on 17.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution88 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto ct = nums2.begin();
        for(auto it = nums1.begin(); it!=nums1.end(); it++){
            while(*it<*ct<*(it+1)&&(*it<*ct&&*(it+1)==0)){
                cout<<*it<<" "<<*(it+1)<<" "<<*ct<<endl;
                nums1.insert(it+1, *ct);
                ct++;
            }
        }
    }
};

