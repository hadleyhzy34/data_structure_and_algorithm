//
//  159_longest_substring_with_at_most_distinct_characters.cpp
//  string
//
//  Created by Hadley on 08.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty())return 0;
        //two pointers that locate the most recent appearance
        int one=0, two=-1, res=1, max_length=1;
        for(int i=1;i<s.size();i++){
            if(s[one]!=s[i]&&(two!=-1&&s[two]!=s[i])){
                res=i-min(one,two);
                one=max(one,two);
                two=i;
            }else if(s[one]==s[i]){
                one=i;
                res++;
            }else if(two==-1){
                two=i;
                res++;
            }else if(s[two]==s[i]){
                two=i;
                res++;
            }
            // cout<<i<<" "<<s[i]<<" "<<one<<" "<<two<<" "<<res<<endl;
            max_length=max(max_length,res);
        }
        return max_length;
    }
};
