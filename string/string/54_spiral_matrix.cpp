//
//  54_spiral_matrix.cpp
//  string
//
//  Created by Hadley on 02.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//


#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dir=1;
        vector<int>res;
        int top=0, bottom=matrix.size()-1,left=0,right=matrix[0].size()-1;
        while(top<=bottom&&left<=right){
            if(dir==1){
                for(int i=left;i<=right;i++){
                    res.push_back(<#const_reference __x#>)
                }
            }
        }
    }
};
