//
//  17_letter_combinations_of_a_phone_number.cpp
//  leetcode_backtracking
//
//  Created by Hadley on 20.08.20.
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
    void combineLetter(string digits,int l,string &subsets){
        if(l==digits.length()){
            res.push_back(subsets);
            return;
        }
        for(auto x:ph[digits[l]-'0']){
            subsets.push_back(x);
            combineLetter(digits, l+1, subsets);
            subsets.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        string subsets;
        ph[2]={'a','b','c'};
        ph[3]={'d','e','f'};
        ph[4]={'g','h','i'};
        ph[5]={'j','k','l'};
        ph[6]={'m','n','o'};
        ph[7]={'p','q','r','s'};
        ph[8]={'t','u','v'};
        ph[9]={'w','x','y','z'};
        combineLetter(digits, 0, subsets);
        return res;
    }
private:
    unordered_map<int, vector<char>>ph;
        vector<string>res;
};
