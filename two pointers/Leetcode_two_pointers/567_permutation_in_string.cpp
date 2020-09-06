//
//  567_permutation_in_string.cpp
//  Leetcode_two_pointers
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
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        auto n1=s1.length();auto n2=s2.length();
        if(n1>n2)return false;
        vector<int>m1(26,0);
        for(auto &x:s1){
            m1[x-'a']++;
        }

        for(int j=0;j<=n2-n1;j++){
            int i=0;
            vector<int>m2(26,0);
            while(i<n1){
                m2[s2[j+i]-'a']++;
                i++;
            }
            if(m1==m2){
                return true;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool checkInclusion(string s1, string s2) {
        auto n1=s1.length();auto n2=s2.length();
        if(n1>n2)return false;
        vector<int>m1(26,0);
        for(auto &x:s1){
            m1[x-'a']++;
        }
        
        vector<int>m2(26,0);
        int i=0;
        while(i<n1){
            m2[s2[i]-'a']++;
        }
        
        if(m1==m2)return true;

        for(int j=1;j<=n2-n1;j++){
            m2[s2[j-1]-'a']--;
            m2[s2[j+n1-1]-'a']++;
            if(m1==m2){
                return true;
            }
        }
        return false;
    }
};
