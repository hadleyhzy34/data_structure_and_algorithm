//
//  557_reverse_words_in_a_string_3.cpp
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
    string reverseWords(string s) {
        string res;
        vector<string>r;
        for(int i=0;i<s.length();i++){
            string temp;
            while (!isspace(s[i])) {
                temp.push_back(s[i]);
                i++;
            }
            if(!temp.empty()){
                r.push_back(temp);
            }
        }
        for(auto &x:r){
            res=res+x;
            res=res+' ';
        }
        res.pop_back();
        return res;
    }
};

class Solution2 {
public:
    string reverseWords(string s) {
        string res;
        for(int i=0;i<s.length();i++){
            int j=i;
            while (i<s.length()&&!isspace(s[i]))i++;
            if(j<i){
                string temp=s.substr(j,i-j);
                reverse(temp.begin(), temp.end());
                s.replace(j, i-j, temp);
                i--;
            }
        }
        return s;
    }
};

class solution3{
public:
    string reverseWords(string s){
        for(int i=0;i<s.size();i++){
            int j=i;
            while(i<s.size()&&!isspace(s[i]))i++;
            if(j<i){
                string temp=s.substr(i,i-1-j+1);
                reverse(temp.begin(), temp.end());
                s.replace(j, i-j, temp);
                i--;
            }
        }
        return s;
    }
};
