//
//  130_surrounded_regions.cpp
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
    bool checkO(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j){
        if(visited[i][j]==true){
            return true;
        }
        if(board[i][j]=='O'){
            if(i==0||j==0||i==board.size()-1||j==board[i].size()-1){
                return false;
            }else{
                visited[i][j]=true;
                bool b= checkO(board, visited,i+1, j)&&checkO(board, visited, i-1, j)&&checkO(board, visited, i, j-1)&&checkO(board, visited, i, j+1);
                visited[i][j]=false;
                return b;
            }
        }else{
            return true;
        }
        
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty())return;
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=1;i<board.size()-1;i++){
            for(int j=1;j<board[i].size()-1;j++){
                if(board[i][j]=='X')continue;
                if(checkO(board, visited, i, j)){
                    board[i][j]='X';
                }
            }
        }
    }
};

class Solution2 {
public:
//    bool checkO(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j){
//        if(visited[i][j]==true){
//            return true;
//        }
//        if(board[i][j]=='O'){
//            if(i==0||j==0||i==board.size()-1||j==board[i].size()-1){
//                return false;
//            }else{
//                visited[i][j]=true;
//                bool b= checkO(board, visited,i+1, j)&&checkO(board, visited, i-1, j)&&checkO(board, visited, i, j-1)&&checkO(board, visited, i, j+1);
//                visited[i][j]=false;
//                return b;
//            }
//        }else{
//            return true;
//        }
//
//    }
    
    void dfs(vector<vector<char>>&board, int i,int j){
        if(i<0||j<0||i>board.size()-1||j>board[i].size()-1){
            return;
        }else{
            if(board[i][j]=='O'){
                board[i][j]='1';
                dfs(board, i-1, j);
                dfs(board,i,j-1);
                dfs(board,i+1,j);
                dfs(board,i,j+1);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.empty())return;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(i==0||j==0||i==board.size()-1||j==board[i].size()-1){
                    dfs(board, i, j);
                }else{
                    continue;
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='1'){
                    board[i][j]='O';
                }else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
