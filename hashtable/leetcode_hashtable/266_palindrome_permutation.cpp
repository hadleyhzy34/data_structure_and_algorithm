//
//  266_palindrome_permutation.cpp
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
    bool canPermutePalindrome(string s) {
        unordered_map<char, int>map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        int count=0;
        for(auto x:map){
            if(x.second&1)count++;
            if(count>1)return false;
        }
        return true;
    }
};
