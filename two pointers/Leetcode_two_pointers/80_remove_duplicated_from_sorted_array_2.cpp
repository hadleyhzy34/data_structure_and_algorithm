//
//  80_remove_duplicated_from_sorted_array_2.cpp
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
    int removeDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int count=0;
            while(j<nums.size()&&nums[j]==nums[i]){
                count++;
                if(count>1){
                    nums.erase(nums.begin()+j);
                }else{
                    j++;
                }
            }
            i=j-1;
        }
        return nums.size();
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())return 0;
        int j = 1, count = 1;
        
        //
        // Start from the second element of the array and process
        // elements one by one.
        //
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                
                count++;
                
            } else {
                count = 1;
            }
            
            if (count <= 2) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
