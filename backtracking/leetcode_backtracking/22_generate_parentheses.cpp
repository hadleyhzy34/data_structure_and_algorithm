//
//  22_generate_parentheses.cpp
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
    void parenthesisGenerate(string &subset, int l, int r){
        if(l<r||l>count||r>count)return;
        if(l==r&&l==count){
            res.push_back(subset);
            return;
        }
        for(int i=0;i<2;i++){
            if(i==0){
                subset.push_back('(');
                parenthesisGenerate(subset, l+1, r);
                subset.pop_back();
            }else{
                subset.push_back(')');
                parenthesisGenerate(subset, l, r+1);
                subset.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        count=n;
        string subset;
        parenthesisGenerate(subset, 0, 0);
        return res;
    }
private:
    vector<string>res;
    int count;
};
