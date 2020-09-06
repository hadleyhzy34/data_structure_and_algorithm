//
//  542_01_matrix.cpp
//  leetcode_dfs
//
//  Created by Hadley on 26.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include <fstream>
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
#include <map>
#include <filesystem>
#include <dirent.h>
using namespace std;

class Solution {
public:
    int matrixUpdate(vector<vector<int>>&matrix, vector<vector<bool>> &visited, int i, int j){
        if(i<0||j<0||i>=matrix.size()||j>=matrix[i].size()||visited[i][j]==true)return INT_MAX;
        if(matrix[i][j]==0){
            return 0;
        }else{
            visited[i][j]=true;
            int a=min(matrixUpdate(matrix, visited, i-1, j),matrixUpdate(matrix, visited, i+1, j));
            int b=min(matrixUpdate(matrix, visited, i, j-1),matrixUpdate(matrix, visited, i, j+1));
            visited[i][j]=false;
            return min(a,b)+1;
            
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>>res(matrix.size(),vector<int>(matrix[0].size()));
        vector<vector<bool>>t(matrix.size(),vector<bool>(matrix[0].size(),false));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    res[i][j]=0;
                }else{
                    res[i][j]=matrixUpdate(matrix, t, i, j);
                }
            }
        }
        return res;
    }
private:
vector<vector<int>>res;
};

class Solution2 {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
    {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX - 100000));

        //First pass: check for left and top
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0)
                    dist[i][j] = 0;
                else {
                    if (i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        //Second pass: check for bottom and right
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < cols - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }

        return dist;
    }
};
