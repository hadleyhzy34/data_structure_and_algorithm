//
//  20_valid_parentheses.cpp
//  LeetCode_stack
//
//  Created by Hadley on 21.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char>ch={{'(',')'},{'[',']'},{'{','}'}};
        stack<char> stc;
        for(auto it=s.begin();it!=s.end();it++){
            if(stc.empty()||*it!=ch[stc.top()]){
                stc.push(*it);
            }else{
                stc.pop();
            }
        }
        if(stc.empty()){
            return true;
        }
        return false;
    }
};
