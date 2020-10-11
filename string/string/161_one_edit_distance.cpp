//
//  161_one_edit_distance.cpp
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
    bool isOneEditDistance(string s, string t) {
        if(s==t)return false;
        int m=s.size(),n=t.size();
        if(abs(m-n)>1)return false;
        
        for(int i=0;i<min(m,n);i++){
            if(s[i]!=t[i])return s.substr(i)==t.substr(i+1)||s.substr(i+1)==t.substr(i+1)||s.substr(i+1)==t.substr(i);
        }
        return true;
    }
};















class Solution2 {
public:
    bool isOneEditDistance(string s, string t) {
        if(s==t)return false;
        int m=s.size(),n=t.size();
        if(abs(m-n)>1)return false;
        int dif=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=s[i])return s.substr(i,m-i)==t.substr(i+1,m-i-1)||s.substr(i+1,m-i-1)==t.substr(i+1,m-i-1)||s.substr(i+1,m-i+1)==t.substr(i,m-i);
        }
        return true;
    }
};
