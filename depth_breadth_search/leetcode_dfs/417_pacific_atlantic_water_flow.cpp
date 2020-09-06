//
//  417_pacific_atlantic_water_flow.cpp
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
    void checkPacific(vector<vector<int>>& matrix, vector<vector<int>>& pacific, int i, int j){
        if(i<0||j<0||i>=matrix.size()||j>=matrix[i].size())return;
        if(pacific[i][j]!=1){
            // cout<<i<<" "<<j<<" "<<pacific[i][j]<<endl;
            if(i==0||j==0){
                pacific[i][j]=1;
            }else if(matrix[i][j]>=matrix[i-1][j]||matrix[i][j]>=matrix[i][j-1]){
                pacific[i][j]=pacific[i][j-1]||pacific[i-1][j];
                // // cout<<i<<" "<<j<<" "<<pacific[i][j]<<endl;
            }
            if(pacific[i][j]==1){
                checkPacific(matrix, pacific, i-1, j);
                checkPacific(matrix, pacific, i+1, j);
                checkPacific(matrix, pacific, i, j-1);
                checkPacific(matrix, pacific, i, j+1);
            }
        }
    }
    
    void checkAtlantic(vector<vector<int>>& matrix, vector<vector<int>>& pacific, int i, int j){
        if(i<0||j<0||i>=matrix.size()||j>=matrix[i].size())return;
        // if(i==3&&j==3) cout<<i<<" "<<j<<" "<<pacific[i][j]<<endl;
        // if(i==4&&j==3) cout<<i<<" "<<j<<" "<<pacific[i][j]<<endl;
        // if(i==4&&j==4) cout<<i<<" "<<j<<" "<<pacific[i][j]<<endl;
        // if(i==0&&j==4) cout<<i<<" "<<j<<" "<<pacific[i][j]<<endl;
        // if(i==1&&j==4) cout<<i<<" "<<j<<" "<<pacific[i][j]<<endl;
        // if(i==2&&j==4) cout<<i<<" "<<j<<" "<<pacific[i][j]<<endl;
        // if(i==3&&j==4) cout<<i<<" "<<j<<" "<<pacific[i][j]<<endl;
        // cout<<i<<" "<<j<<" "<<pacific[i][j]<<endl;
        if(pacific[i][j]!=1){
            if(i==matrix.size()-1||j==matrix[0].size()-1){
                // cout<<i<<" "<<j<<" "<<pacific[i][j]<<endl;
                pacific[i][j]=1;
            }else if(matrix[i][j]>=matrix[i+1][j]||matrix[i][j]>=matrix[i][j+1]){
                // cout<<i<<" "<<j<<" "<<pacific[i][j]<<endl;
                pacific[i][j]=pacific[i][j+1]||pacific[i+1][j];
            }
            if(pacific[i][j]==1){
                // cout<<i<<" "<<j<<" "<<pacific[i][j]<<endl;
                checkAtlantic(matrix, pacific, i-1, j);
                checkAtlantic(matrix, pacific, i+1, j);
                checkAtlantic(matrix, pacific, i, j-1);
                checkAtlantic(matrix, pacific, i, j+1);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty())return {};
        vector<vector<int>>pacific(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>>atlantic(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(i==0||j==0)checkPacific(matrix, pacific, i, j);
                if(i==matrix.size()-1||j==matrix[i].size()-1)checkAtlantic(matrix, atlantic, i, j);
                
            }
        }
        
        for(auto x:pacific){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        
        vector<vector<int>>res;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(pacific[i][j]==1&&atlantic[i][j]==1)res.push_back({i,j});
            }
        }
        return res;
    }
};

class Solution2 {
public:
    void checkPacific(vector<vector<int>>& matrix, vector<vector<int>>& pacific, int i, int j){
        if(i<0||j<0||i>=matrix.size()||j>=matrix[i].size())return;
        pacific[i][j]=1;
        // cout<<i<<" "<<j<<" "<<pacific[i][j]<<endl;
        if(i-1>=0&&matrix[i][j]<=matrix[i-1][j]&&pacific[i-1][j]!=1){
            checkPacific(matrix, pacific, i-1, j);
        }
        if(j-1>=0&&matrix[i][j]<=matrix[i][j-1]&&pacific[i][j-1]!=1){
            checkPacific(matrix, pacific, i, j-1);
        }
        if(i+1<matrix.size()&&matrix[i][j]<=matrix[i+1][j]&&pacific[i+1][j]!=1){
            checkPacific(matrix, pacific, i+1, j);
        }
        if(j+1<matrix[i].size()&&matrix[i][j]<=matrix[i][j+1]&&pacific[i][j+1]!=1){
            checkPacific(matrix, pacific, i, j+1);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty())return {};
        vector<vector<int>>pacific(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>>atlantic(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(i==0||j==0)checkPacific(matrix, pacific, i, j);
                if(i==matrix.size()-1||j==matrix[i].size()-1)checkPacific(matrix, atlantic, i, j);
            }
        }
        
        // for(auto x:pacific){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<vector<int>>res;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(pacific[i][j]==1&&atlantic[i][j]==1)res.push_back({i,j});
            }
        }
        return res;
    }
};
