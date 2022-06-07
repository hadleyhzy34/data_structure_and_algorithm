//
//  345_reverse_vowels_of_a_string.cpp
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
    bool checkVowels(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
            return true;
        }else{
            return false;
        }
    }
    string reverseVowels(string s) {
        auto n=s.size();
        int l=0,r=n-1;
        while(l<r){
            if(!checkVowels(s[l])){
                l++;
            }
            if(!checkVowels(s[r])){
                r--;
            }
            if(checkVowels(s[l])&&checkVowels(s[r])){
                char temp=s[l];
                s[l]=s[r];
                s[r]=temp;
                l++;r--;
            }
        }
        return s;
    }
};
