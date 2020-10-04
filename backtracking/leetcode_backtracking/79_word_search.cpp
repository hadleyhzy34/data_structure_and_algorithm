//
//  79_word_search.cpp
//  leetcode_backtracking
//
//  Created by Hadley on 24.08.20.
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
    bool checkExistence(vector<vector<char>>& board, int x, int y, int l, string word){
        if(l==word.length()){
            return true;
        }
        if(board[x][y]!=word[l]){
            return false;
        }else{
            char temp=board[x][y];
            board[x][y]='1';
            // cout<<x<<" "<<y<<" "<<board[x][y]<<endl;
            if(l==word.length()-1)return true;
            bool a,b,c,d;
            if(x>0&&board[x-1][y]!='1'){
                // char ta=board[x-1][y];
                // board[x-1][y]='1';
                a=checkExistence(board, x-1, y, l+1, word);
                // board[x-1][y]=ta;
            }else{
                a=false;
            }
            if(y>0&&board[x][y-1]!='1'){
                // char tb=board[x][y-1];
                // board[x][y-1]='1';
                b=checkExistence(board, x, y-1, l+1, word);
                // board[x][y-1]=tb;
            }else{
                b=false;
            }
            if(x>=0&&x<board.size()-1&&board[x+1][y]!='1'){
                // char tc=board[x+1][y];
                // board[x+1][y]='1';
                c=checkExistence(board, x+1, y, l+1, word);
                // board[x+1][y]=tc;
            }else{
                c=false;
            }
            if(y>=0&&y<board[x].size()-1&&board[x][y+1]!='1'){
                // char td=board[x][y+1];
                // board[x][y+1]='1';
                d=checkExistence(board, x, y+1, l+1, word);
                // board[x][y+1]=td;
            }else{
                d=false;
            }
            board[x][y]=temp;
            return a||b||c||d;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(checkExistence(board, i, j, 0, word)){
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool checkExistence(vector<vector<char>>& board, int x, int y, int l, string word){
        if(l==word.length()){
            return true;
        }
        if(x<0||y<0||x>=board.size()||y>=board[x].size()||board[x][y]!=word[l]){
            return false;
        }else{
            char temp=board[x][y];
            board[x][y]='1';
            bool check= checkExistence(board, x-1, y, l+1, word)||checkExistence(board, x, y-1, l+1, word)||checkExistence(board, x+1, y, l+1, word)||checkExistence(board, x, y+1, l+1, word);
            board[x][y]=temp;
            return check;
        }
    }
        
            


    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]&&checkExistence(board, i, j, 0, word))return true;
            }
        }
        return false;
    }
};

class Solution3 {
public:
    vector<vector<char>>b;
    string w;
    bool checkExistence(int x, int y, int l){
        if(l==w.length()){
            return true;
        }
        if(x<0||y<0||x>=b.size()||y>=b[x].size()||b[x][y]!=w[l]){
            return false;
        }else{
            char temp=b[x][y];
            b[x][y]='1';
            bool check= checkExistence(x-1, y, l+1)||checkExistence(x, y-1, l+1)||checkExistence(x+1, y, l+1)||checkExistence(x, y+1, l+1);
            b[x][y]=temp;
            return check;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        b=board;
        w=word;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]&&checkExistence(i, j, 0))return true;
            }
        }
        return false;
    }
};













class Solution4 {
public:
    bool checkBoard(vector<vector<char>>& board, string word, int index,int i, int j){
        if(i<0||j<0||i>=board.size()||j>=board[i].size()||word[index]!=board[i][j])return false;

        if(index==word.size()-1)return true;
        
    char temp=board[i][j];
    board[i][j]='1';
        
        bool res=checkBoard(board, word, index+1, i-1, j)||checkBoard(board, word, index+1, i+1, j)||checkBoard(board, word, index+1, i, j-1)||checkBoard(board, word, index+1, i, j+1);
    board[i][j]=temp;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(word[0]==board[i][j]){
                    if(checkBoard(board, word, 0, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

