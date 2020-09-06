//
//  424_longest_repeating_character_replacement.cpp
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
    int characterReplacement(string s, int k) {
        auto n=s.length();
        int res=0;
        unordered_map<char, int>m;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end()){
                continue;
            }else{
                m[s[i]]++;
            }
            int j=0,l=1,count=0;
            if(s[i]!=s[j])count++;
            if(s[i]!=s[l])count++;
            while(j+1<n&&l<n){
                if(count<k){
                    if(l==n-1){
                        cout<<count<<" "<<i<<" "<<j<<" "<<l<<" "<<l-j+1<<endl;
                        res=max(res,l-j+1);
                        break;
                    }else{
                        l++;
                        if(s[l]!=s[i])count++;
                    }
                }else if(count==k){
                    cout<<count<<" "<<i<<" "<<j<<" "<<l<<" "<<l-j+1<<endl;
                    res=max(res,l-j+1);
                    if(l==n-1||s[i]!=s[l+1]){
                        if(s[i]!=s[j])count--;
                        j++;
                    }else{
                        l++;
                    }
                }else if(count>k){
                    if(s[i]!=s[j])count--;
                    j++;
                }
            }
        }
        return res;
    }
};
