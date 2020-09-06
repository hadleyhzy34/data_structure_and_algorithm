//
//  28_implement_strstr.cpp
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
    int strStr(string haystack, string needle) {
        if(needle.empty())return 0;
        auto n=needle.size();
        for(int i=0;i+n<=haystack.size();i++){
            // cout<<haystack.substr(i,n)<<" "<<needle<<endl;
            if(haystack.substr(i,n)==needle)return i;
        }
        return -1;
    }
};

class Solution2 {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())return 0;
        auto n=needle.size();
        int i=0,j=0;
        while(i<haystack.size()&&j<n){
            if(haystack[i]==needle[j]){
                j++;i++;
            }else if(j==0){
                i++;
            }else{
                i=i-j+1;
                j=0;
            }
        }
        if(j==n){
            return i-n+1;
        }else{
            return -1;
        }
    }
};
