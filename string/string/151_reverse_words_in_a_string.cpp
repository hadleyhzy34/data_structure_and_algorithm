//
//  151_reverse_words_in_a_string.cpp
//  string
//
//  Created by Hadley on 23.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string>res;
        for(int i=0;i<s.length();i++){
            string temp="";
            while(!isspace(s[i])&&i<s.length()){
                temp+=s[i];
                i++;
            }
            if(!temp.empty()){
                res.push_back(temp);
            }
        }
        string output="";
        for(auto it=res.rbegin();it!=res.rend();it++){
            output=output+*it+' ';
        }
        if(!output.empty()){
            output.pop_back();
        }
        return output;
    }
};

class Solution2 {
public:
    string reverseWords(string s) {
        stack<string>res;
        for(int i=0;i<s.length();i++){
            string temp="";
            while(!isspace(s[i])&&i<s.length()){
                temp+=s[i];
                i++;
            }
            if(!temp.empty()){
                res.push(temp);
            }
        }
        string output="";
        while (!res.empty()) {
            output+=res.top()+' ';
            res.pop();
        }

        if(!output.empty()){
            output.pop_back();
        }
        return output;
    }
};
