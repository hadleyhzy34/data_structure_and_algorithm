//
//  290_word_pattern.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 19.08.20.
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
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string>map;
        unordered_map<string, char>m;
        int p=0,space=-1;
        for(int i=0;i<str.length();i++){
            if(i==str.length()-1||isspace(str[i+1])){
                string temp=str.substr(space+1,i-space);
                if(map.find(pattern[p])!=map.end()){
                    if(map[pattern[p]]!=temp){
                        // cout<<p<<" "<<pattern[p]<<" "<<map[pattern[p]].length()<<" "<<temp.length()<<" "<<space<<" "<<i<<endl;
                        return false;
                    }
                }else{
                    map[pattern[p]]=temp;
                }
                if(m.find(temp)!=m.end()){
                    if(m[temp]!=pattern[p])return false;
                }else{
                    m[temp]=pattern[p];
                }
                p++;
                space=i+1;
            }
        }
        p=p-1;
        if(p==pattern.length()-1){
            return true;
        }else{
            return false;
        }
    }
};
