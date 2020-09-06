//
//  131_palindrome_partitioning.cpp
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
    bool checkPalindrome(string s){
        if( equal(s.begin(), s.begin() + s.size()/2, s.rbegin()) )
            return true;
        else
            return false;
    }
    void checkPartition(string s,vector<string> &substring, vector<vector<string>>&res, int cur){
        if(cur==s.length()){
            res.push_back(substring);
            return;
        }
        for(int l=1;cur+l-1<s.length();l++){
            if(checkPalindrome(s.substr(cur,l))){
                substring.push_back(s.substr(cur,l));
                checkPartition(s, substring,res,cur+l);
                substring.pop_back();
            }else{
                continue;
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>substring;
        checkPartition(s, substring, res, 0);
        return res;
    }
};


class Solution2 {
public:
    void checkPalindrome(string s, vector<vector<int>>&dp){
        for(int i=0;i<s.length();i++){
            dp[i][i]=1;
            if(i<s.length()-1&&s[i]==s[i+1]){
                dp[i][i+1]=1;
            }
        }
        for(int l=3;l<=s.length();l++){
            for(int i=0;i+l-1<s.length();i++){
                if(s[i]==s[i+l-1]&&dp[i+1][i+l-2]==1){
                    dp[i][i+l-1]=1;
                }
            }
        }
    }

    void checkPartition(string s,vector<string> &substring, vector<vector<string>>&res, int cur, vector<vector<int>>dp){
            if(cur==s.length()){
                res.push_back(substring);
                return;
            }
            for(int l=1;cur+l-1<s.length();l++){
                if(dp[cur][cur+l-1]==1){
                    substring.push_back(s.substr(cur,l));
                    checkPartition(s, substring,res,cur+l,dp);
                    substring.pop_back();
                }else{
                    continue;
                }
            }
        }

    vector<vector<string>> partition(string s) {
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),0));
        vector<vector<string>>res;
        vector<string>substring;
        checkPartition(s, substring, res, 0, dp);
        return res;
    }
};
