//
//  459_repeated_substring_pattern.cpp
//  string
//
//  Created by Hadley on 24.09.20.
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
    bool repeatedSubstringPattern(string s) {
        int m=s.size();
        for(int i=1;i<=m/2;i++){
            if(m%i==0){
                string temp;
                int n=m/i;
                while(n--){
                    temp+=s.substr(0,i);
                }
                if(temp==s)return true;
            }
        }
        return false;
    }
};

//solution2:https://leetcode.com/problems/repeated-substring-pattern/discuss/826135/C%2B%2B-O(N)-time-or-One-liner-without-KMP-Explained-or-Beats-99
