//
//  139_word_break.cpp
//  string
//
//  Created by Hadley on 06.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty())return false;
        
        int l=int(s.length());
        vector<bool>wordMatch(l,false);
        for(int i=0;i<l;i++){
            for(auto &x:wordDict){
                if(x.length()-1<=i&&x==s.substr(i-x.length()+1,x.length())&&(i-x.length()==-1||wordMatch[i-x.length()]==true)){
                    wordMatch[i]=true;
                    break;
                }
            }
        }
        return wordMatch[l-1];
    }
};
