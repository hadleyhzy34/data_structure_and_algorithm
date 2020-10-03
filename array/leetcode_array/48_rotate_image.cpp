//
//  48_rotate_image.cpp
//  leetcode_array
//
//  Created by Hadley on 02.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose matrix
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix[i].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse every row of transpose matrix
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
