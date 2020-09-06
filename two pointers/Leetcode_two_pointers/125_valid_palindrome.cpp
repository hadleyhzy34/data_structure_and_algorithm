//
//  125_valid_palindrome.cpp
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
    bool isPalindrome(string s) {
        auto n=s.length();
        int i=0,j=n-1;
        while(i<j){
            if(!isalnum(s[i])){
                i++;
            }
            if(!isalnum(s[j])){
                j--;
            }
            if(isalnum(s[i])&&isalnum(s[j])){
                if(isupper(s[i]))s[i]=tolower(s[i]);
                if(isupper(s[j]))s[j]=tolower(s[j]);
                if(s[i]==s[j]){
                    i++;j--;
                }else{
                    cout<<s[i]<<" "<<s[j]<<endl;
                    return false;
                }
            }
        }
        return true; 
    }
};
