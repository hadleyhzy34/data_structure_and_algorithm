//
//  844_backspace_string_compare.cpp
//  LeetCode_stack
//
//  Created by Hadley on 23.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char>ss;
        stack<char>tt;
        for(auto s:S){
            if(s=='#'&&!ss.empty()){
                ss.pop();
                continue;
            }
            if(s=='#'&&ss.empty()){
                continue;
            }
            ss.push(s);
        }
        for(auto t:T){
            if(t=='#'&&!tt.empty()){
                tt.pop();
                continue;
            }
            if(t=='#'&&tt.empty()){
                continue;
            }
            tt.push(t);
        }
        while(!ss.empty()&&!tt.empty()){
            if(ss.top()!=tt.top()){
                return false;
            }
            ss.pop();
            tt.pop();
        }
        if(ss.empty()^tt.empty()){
               return false;
        }
        return true;
    }
};
