//
//  139_word_break.cpp
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
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty())return false;
        auto l=s.length();
        bool wordMatch[l+1];
        memset(wordMatch, 0, sizeof(wordMatch));
        
        wordMatch[0]=true;
        for(int i=0;i<l;i++){
            if(wordMatch[i]==false)continue;
            for(auto &x:wordDict){
                if(s.compare(i,x.length(),x)==0){
                    wordMatch[i+x.length()]=true;
                }
            }
        }
        return wordMatch[l];
    }
};
