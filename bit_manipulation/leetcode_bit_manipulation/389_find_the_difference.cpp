//
//  389_find_the_difference.cpp
//  leetcode_bit_manipulation
//
//  Created by Hadley on 07.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int>umap;
        for(auto st:t){
            umap[st]++;
        }
        for(auto st:s){
            umap[st]--;
        }
        for(auto it=umap.begin();it!=umap.end();it++){
            if(it->second==1){
                return it->first;
            }
        }
        return umap.begin()->first;
    }
};

class Solution2 {
public:
    char findTheDifference(string s, string t) {
        int result=0;
        for(int i=0;i<s.size();i++){
            int a=int(s[i])-48;
            int b=int(t[i])-48;
            result^=(a^b);
        }
        result^=(int(t[t.size()-1])-48);
        return result+48;
    }
};
