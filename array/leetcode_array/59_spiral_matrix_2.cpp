//
//  59_spiral_matrix_2.cpp
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        if(n==0)return{};
        int top=0,bottom=matrix.size()-1,left=0,right=matrix[0].size()-1;
        int dir=1;
        int cnt=1;
        while(top<=bottom&&left<=right){
            if(dir==1){
                for(int i=left;i<=right;i++){
                    matrix[top][i]=cnt;
                    cnt++;
                }
                dir=2;
                top++;
            }
            else if(dir==2){
                for(int i=top;i<=bottom;i++){
                    matrix[i][right]=cnt;
                    cnt++;
                }
                dir=3;
                right--;
            }
            else if(dir==3){
                for(int i=right;i>=left;i--){
                    matrix[bottom][i]=cnt;
                    cnt++;
                }
                dir=4;
                bottom--;
            }
            else if(dir==4){
                for(int i=bottom;i>=top;i--){
                    matrix[i][left]=cnt;
                    cnt++;
                }
                left++;
                dir=1;
            }
        }
        return matrix;
    }
};
