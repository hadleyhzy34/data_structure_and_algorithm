//
//  36_valid_sudoku.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 18.08.20.
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
#include <map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<unordered_map<int, int>>> block(3,vector<unordered_map<int, int>>(3));
        vector<unordered_map<int, int>> col(9);
        for(int i=0;i<9;i++){
            unordered_map<int, int>row;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(col[j].find(board[i][j]-'0')==col[j].end()){
                        col[j][board[i][j]-'0']++;
                    }else{
                        return false;
                    }
                    if(row.find(board[i][j]-'0')==row.end()){
                        row[board[i][j]-'0']++;
                    }else{
                        return false;
                    }
                    if(block[i/3][j/3].find(board[i][j]-'0')==block[i/3][j/3].end()){
                        block[i/3][j/3][board[i][j]-'0']++;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
