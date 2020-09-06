//
//  438_find_all_anagrams_in_a_string.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 20.08.20.
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
    vector<int> findAnagrams(string s, string p) {
        auto l=p.length();
                if(s.empty()||s.length()<p.length())return {};
        //        int mp[26]={0};
        //        int ms[26]={0};
                vector<int>mp(26,0);
                vector<int>ms(26,0);
                vector<int>res;
                for(int i=0;i<p.length();i++){
                    mp[p[i]-'a']++;
                    ms[s[i]-'a']++;
                }
                if(ms==mp)res.push_back(0);
                
                for(int i=1;i+l-1<s.length();i++){
                    ms[s[i-1]-'a']--;
                    ms[s[i+l-1]-'a']++;
                    if(ms==mp)res.push_back(i);
                }
                return res;
    }
};
