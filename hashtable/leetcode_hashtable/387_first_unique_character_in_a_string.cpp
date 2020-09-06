//
//  387_first_unique_character_in_a_string.cpp
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
    int firstUniqChar(string s) {
        unordered_map<char,int>map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(map[s[i]]==1)return i;
        }
        return -1;
    }
};
