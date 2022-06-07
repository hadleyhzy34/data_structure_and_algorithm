//
//  3_longest_substring_without_repeating_characters.cpp
//  Leetcode_two_pointers
//
//  Created by Hadley on 14.08.20.
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
    int lengthOfLongestSubstring(string s) {
        if(s.empty())return 0;
        auto n=s.length();
        int max_length=0;
        for(int i=0;i+max_length<n;i++){
            int j=i;
            int l=0;
            unordered_map<char, int>dict;
            while(j<n){
                if(dict.find(s[j])==dict.end()){
                    dict[s[j]]++;
                    j++;
                    l++;
                }else{
                    break;
                }
            }
            max_length=max(max_length,l);
        }
        return max_length;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())return 0;
        auto n=s.length();
        int max_length=0;
        unordered_map<char, int>dict;
        int i=0,j=0;
        while(i<n&&j<n){
            if(dict.find(s[j])==dict.end()){
                max_length=max(max_length,j-i+1);
                dict[s[j]]++;
                j++;
            }else{
                dict.erase(s[i++]);
            }
        }
        return max_length;
    }
};

class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())return 0;
        auto n=s.length();
        int max_length=0;
        unordered_map<char, int>dict;
        int i=0,j=0;
        while(i<n&&j<n){
            if(dict.find(s[j])!=dict.end()){
                i=max(dict[s[j]]+1,i);}
                // dict[s[j]]=j;
                // cout<<"not found "<<i<<" "<<j-1<<" "<<s[j-1]<<dict[s[j-1]]<<endl;;
            // }else{
            //     // dict[s[j]]=j;
            //     // cout<<"found "<<i<<" "<<j<<endl;
            // }
            dict[s[j]]=j;
            max_length=max(max_length,j-i+1);
            j++;
        }
        return max_length;
    }
};
