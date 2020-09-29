//
//  186_reverse_words_in_a_string_2.cpp
//  string
//
//  Created by Hadley on 23.09.20.
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
using namespace std;

class Solution {
public:
    void reverseWords(vector<char>& s) {
        stack<vector<char>>res;
        for(int i=0;i<s.size();i++){
            vector<char>temp;
            while(!isspace(s[i])&&i<s.size()){
                temp.push_back(s[i]);
                i++;
            }
            if(!temp.empty()){
                res.push(temp);
            }
        }
        s.clear();
        while(!res.empty()){
            for(auto x:res.top()){
                s.push_back(x);
            }
        }
    }
};
