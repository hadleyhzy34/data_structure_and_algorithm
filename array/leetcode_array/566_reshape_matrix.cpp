//
//  566_reshape_matrix.cpp
//  leetcode_array
//
//  Created by Hadley on 20.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int col = static_cast<int>(nums[0].size());
        int row = static_cast<int>(nums.size());
        if(row*col!=r*c){
            return nums;
        }
        vector<int> total;
        for(int row_num=0;row_num<row;row_num++){
            for(int col_num=0;col_num<col;col_num++){
                total.push_back(nums[row_num][col_num]);
            }
        }
        
        vector<vector<int>> reshape(r,vector<int>(c));
        int index=0;
        for(int row_num=0;row_num<r;row_num++){
            for(int col_num=0;col_num<c;col_num++){
                reshape[row_num][col_num] = total[index++];
            }
        }
        return reshape;
    }
};
