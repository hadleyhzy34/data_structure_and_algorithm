//
//  541_reverse_string_2.cpp
//  string
//
//  Created by Hadley on 24.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <stack>
#include <cstdlib>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int cnt=0;
        while(2*cnt*k<s.size()){
            if(2*cnt*k+k>s.size()-1){
                reverse(s.begin()+2*cnt*k, s.end());
            }else{
                reverse(s.begin()+2*cnt*k, s.begin()+2*cnt*k+k);
            }
            cnt++;
        }
        return s;
    }
};

class Solution2 {
public:
    string reverseStr(string s, int k) {
        int cnt=0;
        for(;2*cnt*k<s.size();cnt++){
            if(2*cnt*k+k<s.size()){
               reverse(s.begin()+2*cnt*k,s.begin()+2*cnt*k+k);
            }else{
               reverse(s.begin()+2*cnt*k,s.end());
            }
        }
        return s;
    }
};
