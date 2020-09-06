//
//  palindrome_permutation_2.cpp
//  leetcode_backtracking
//
//  Created by Hadley on 24.08.20.
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
    void permutation(string h,int l,vector<string>&res){
        if(l==h.length()-1){
            res.push_back(h);
        }else{
            for(int i=l;i<h.length();i++){
                if(i==l||h[i]!=h[l]){
                    swap(h[i],h[l]);
                    permutation(h, l+1, res);
                }
            }
        }
    }
    
    void palindromeGeneration(string h, vector<string>&res, char mid, bool even){
        permutation(h, 0, res);
        if(even){
            for(int i=0;i<res.size();i++){
                string temp=res[i];
                reverse(temp.begin(), temp.end());
                res[i]=res[i]+temp;
            }
        }else{
            for(int i=0;i<res.size();i++){
                string temp=res[i];
                reverse(temp.begin(), temp.end());
                res[i].push_back(mid);
                res[i]+=temp;
            }
        }
    }
    
    vector<string> generatePalindromes(string s) {
        if(s.length()<=1)return {s};
        bool even=((s.length()&1)==0)?true:false;
        
        string half;
        unordered_map<char, int>map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
            if((map[s[i]]&1)==0)half.push_back(s[i]);
        }
        sort(half.begin(),half.end());
        
        char mid=s[s.length()/2];
        int count=0;
        for(auto x:map){
            if(x.second&1){
                count++;
                mid=x.first;
            }
        }
        if(count>1)return {};
        vector<string>res;
        palindromeGeneration(half, res, mid,even);
        return res;
    }
};

