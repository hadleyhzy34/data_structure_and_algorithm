//
//  409_longest_palindrome.cpp
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
    int longestPalindrome(string s) {
        unordered_map<char, int>map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        int count=0;
        int total=0;
        for(auto x:map){
            if(x.second&1){
                total+=x.second-1;
                count=1;
//                count=max(count,x.second);
            }else{
                total+=x.second;
            }
        }
//        cout<<count<<" "<<total<<endl;
        return count+total;
    }
};
