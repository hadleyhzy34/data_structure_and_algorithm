//
//  74_search_2d_matrix.cpp
//  binary_search
//
//  Created by Hadley on 08.08.20.
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty()||target<matrix[0][0]||target>matrix[matrix.size()-1][matrix[0].size()-1])return false;
        int m=matrix.size();
        int n=matrix[0].size();
        int row_up=0;
        int row_down=matrix.size()-1;
        int row_res;
        while(row_up<=row_down){
            int row_mid=row_up+(row_down-row_up)/2;
            if(target>=matrix[row_mid][0]&&target<=matrix[row_mid][n-1]){
                row_res=row_mid;
                break;
            }else if(target<matrix[row_mid][0]){
                row_down=row_mid-1;
            }else{
                row_up=row_mid+1;
            }
            // cout<<row_mid<<endl;
        }
        
        
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(matrix[row_res][mid]==target){
                return true;
            }else if(matrix[row_res][mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return false;
    }
};
