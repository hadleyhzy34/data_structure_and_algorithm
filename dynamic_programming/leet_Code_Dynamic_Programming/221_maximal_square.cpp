//
//  221_maximal_square.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 15.07.20.
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

//class Solution {
//public:
//    int maximalSquare(vector<vector<char>>& matrix) {
//        if(matrix.empty())return 0;
//        vector<pair<int,int>> ones;
//        int maxArea=0;
//        auto width=min(matrix.size(),matrix[0].size());
//        for(int i=0;i<matrix.size();i++){
//            for(int j=0;j<matrix[0].size();j++){
//                if(matrix[i][j]=='1'){
//                    ones.push_back(make_pair(i, j));
//                }
//            }
//        }
//
//        if(ones.empty()){
//            return 0;
//        }else{
//            maxArea=1;
//        }
//
//        for(auto &x:ones){
//            for(int i=x.first;i-x.first<width-1;i++){
//                for(int j=x.second;j-x.first<)
//            }
//        }
//    }
//};

//class Solution {
//public:
//    int maximalSquare(vector<vector<char>>& matrix) {
//        if(matrix.empty())return 0;
//        vector<vector<int>> rowOnes;
//
//        for(int i=0;i<matrix.size();i++){
//            if(matrix[i][0]=='1'){
//                rowOnes[i][0]=1;
//            }else{
//                rowOnes[i][0]=0;
//            }
//        }
//        for(int i=0;i<matrix.size();i++){
//            for(int j=1;j<matrix[0].size();j++){
//                if(matrix[i][j]=='1'){
//                    rowOnes[i][j]=rowOnes[i][j-1]+1;
//                }else{
//                    rowOnes[i][j]=0;
//                }
//            }
//        }
//
//        for(int j=0;j<matrix[0].size();j++){
//
//        }
//
//    }
//};

class Solution2 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())return 0;
        
        auto row=matrix.size();
        auto col=matrix[0].size();
        int matrix_size[row][col];
        memset(matrix_size,0,sizeof(matrix_size));
        
        int maxArea=0;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i==0||j==0){
                    matrix_size[i][j]=matrix[i][j]-'0';
                }else{
                    if(matrix[i][j]=='1'
                       &&matrix[i][j]==matrix[i-1][j]
                       &&matrix[i-1][j]==matrix[i][j-1]
                       &&matrix[i][j-1]==matrix[i-1][j-1]){
                        int temp=min(matrix_size[i-1][j],matrix_size[i][j-1]);
                        matrix_size[i][j]=min(temp, matrix_size[i-1][j-1])+1;
                    }else{
                        matrix_size[i][j]=matrix[i][j]-'0';
                    }
                }
                maxArea=max(maxArea,matrix_size[i][j]);
            }
        }
        return maxArea*maxArea;
    }
};
