//
//  3_longest_substring_without_repeating_characters.cpp
//  string
//
//  Created by Hadley on 02.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;


//slicing window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>m;
        int maxLength=0;
        int j=0;
        int curLength=0;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()||m[s[i]]<j){
                curLength=i-j+1;
                //current position where it is stored
                m[s[i]]=i;
                maxLength=max(maxLength,curLength);
            }else{
                j=m[s[i]]+1;
                m[s[i]]=i;
            }
        }
        return maxLength;
    }
};
