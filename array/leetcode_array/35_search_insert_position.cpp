//
//  35_search_insert_position.cpp
//  leetcode_array
//
//  Created by Hadley on 16.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution35 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        //be very careful to put condition i<nums.size() in fron of the condition otherwise subscript index would be exceeded
        while(i<nums.size()&&nums[i]<target){
            cout<<i<<" "<<nums[i]<<endl;
            i++;
        }
        return i;
    }
};
