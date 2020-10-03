//
//  54_spiral_matrix.cpp
//  leetcode_array
//
//  Created by Hadley on 03.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0,bottom=matrix.size()-1,left=0,right=matrix[0].size()-1;
        int dir=1;
        vector<int>res;
        while(top<bottom&&left<right){
            if(dir==1){
                for(int i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                dir=2;
            }
            if(dir==2){
                for(int i=top+1;i<=bottom;i++){
                    res.push_back(matrix[i][right]);
                }
                dir=3;
            }
            if(dir==3){
                for(int i=right-1;i>=left;i--){
                    res.push_back(matrix[bottom][i]);
                }
                dir=4;
            }
            if(dir==4){
                for(int i=bottom-1;i>=top+1;i--){
                    res.push_back(matrix[i][left]);
                }
                dir=1;
            }
            top=top+1;
            bottom=bottom-1;
            left=left+1;
            right=right-1;
        }
        return res;
    }
};
