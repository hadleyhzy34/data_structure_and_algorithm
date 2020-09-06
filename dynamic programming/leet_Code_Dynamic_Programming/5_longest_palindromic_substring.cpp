//
//  5_longest_palindromic_substring.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 14.07.20.
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
    string longString(string s){
        if(s.size()==1)return s;
        for(auto l=s.size();l>1;l--){
            for(int i=0;i<=s.size()-l;i++){
                string temp=s.substr(i,l);
                string rtemp=temp;
                reverse(rtemp.begin(), rtemp.end());
                if(temp==rtemp)return temp;
            }
        }
        return string(1,s[0]);
    }
    
    string longestPalindrome(string s) {
        if(s.empty())return "";
        return longString(s);
    }
};

class Solution1 {
public:
    string longestPalindrome(string s) {
        if(s.empty())return "";
        bool table[s.size()][s.size()];
        memset(table, false, sizeof(table));
        
        int max_length=1;
        int start_index=0;
        for(int i=0;i<s.size();i++){
            table[i][i]=true;
        }
        
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                table[i][i+1]=true;
                max_length=2;
                start_index=i;
            }
        }
        
        for(int l=3;l<=s.size();l++){
            for(int i=0;i<s.size()-l+1;i++){
                if(table[i+1][i+l-2]&&s[i]==s[i+l-1]){
                    table[i][i+l-1]=true;
                    if(l>max_length){
                        max_length=l;
                        start_index=i;
                    }
                }
            }
        }
        return s.substr(start_index,max_length);
    }
};


