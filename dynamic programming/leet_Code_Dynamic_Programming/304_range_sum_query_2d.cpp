//
//  304_range_sum_query_2d.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 20.07.20.
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

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix=matrix;
        sum=new int*[matrix.size()];
        
        for(int i=0;i<matrix.size();i++){
            sum[i]=new int[matrix[0].size()];
            memset(sum[i], 0, matrix[0].size()*sizeof(int));
        }
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i==0&&j==0){
                    sum[i][j]=matrix[i][j];
                }else if(i==0&&j!=0){
                    sum[i][j]=sum[i][j-1]+matrix[i][j];
                }else if(i!=0&&j==0){
                    sum[i][j]=sum[i-1][j]+matrix[i][j];
                }else{
                    sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // cout<<sum[row1][col1]<<" "<<sum[row2][col2]<<endl;
        if(row1==0&&col1==0){
            return sum[row2][col2];
        }else if(row1==0&&col1!=0){
            return sum[row2][col2]-sum[row2][col1-1];
        }else if(row1!=0&&col1==0){
            return sum[row2][col2]-sum[row1-1][col2];
        }else{
            // cout<<sum[row2][col2]<<" "<<sum[row1-1][col2]<<" "<<sum[row2][col1-1]<<" "<<sum[row1-1][col1-1]<<endl;
            return sum[row2][col2]-sum[row1-1][col2]-sum[row2][col1-1]+sum[row1-1][col1-1];
        }
    }
private:
    vector<vector<int>> matrix;
    int **sum;
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
