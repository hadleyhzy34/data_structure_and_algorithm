//
//  80_remove_duplicates_from_sorted_array_2.cpp
//  leetcode_array
//
//  Created by Hadley on 04.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/stdc++.h"
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //two pointers
        //int j is to count real numbers of sorted element
        int j=0, cnt=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[j]=nums[i];
                j++;
                cnt=1;
            }else{
                if(cnt==1){
                    cnt++;
                    j++;
                }
            }
        }
        return j;
    }
};
