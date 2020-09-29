//
//  500_keyboard_row.cpp
//  string
//
//  Created by Hadley on 29.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <stack>
#include <cstdlib>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> dict(26);
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        for (int i = 0; i < rows.size(); i++) {
            for (auto c : rows[i]) dict[c-'A'] = i;
        }
        vector<string> res;

        for (auto w : words) {
            bool temp=true;
            for(int i=0;i<w.size()-1;i++){
                if(dict[toupper(w[i])-'A']!=dict[toupper(w[i+1])-'A']){
                    temp=false;
                    break;
                }
            }
            if(temp)res.push_back(w);
        }
        return res;
    }
};
