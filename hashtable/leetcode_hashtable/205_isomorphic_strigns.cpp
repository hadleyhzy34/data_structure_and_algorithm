//
//  205_isomorphic_strigns.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 15.08.20.
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
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>map;
        auto n1=s.length(),n2=s.length();
        if(n1!=n2)return false;
        for(int i=0;i<n2;i++){
            if(map.find(t[i])!=map.end()){
                if(map[t[i]]!=s[i])return false;
            }else{
                for(auto &x:map){
                    if(x.second==s[i])return false;
                }
                map[t[i]]=s[i];
            }
        }
        return true;
    }
};
