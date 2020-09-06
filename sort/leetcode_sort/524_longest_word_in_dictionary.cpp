//
//  524_longest_word_in_dictionary.cpp
//  leetcode_sort
//
//  Created by Hadley on 22.06.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string longest;
        int cur_long=0;
        for(auto tempd:d){
            auto temp = s;
            bool contained = true;
            for(auto ss:tempd){
                std::size_t found = temp.find(ss);
                if(found!=std::string::npos){
                    temp.erase(temp.begin()+found);
                }else{
                    contained = false;
                    break;
                }
            }
            if(contained&&tempd.length()>cur_long){
                cur_long=tempd.length();
                longest=tempd;
            }else if(contained&&tempd.length()==cur_long){
                if(longest.compare(tempd)>0){
                    longest=tempd;
                }
            }
        }
        return longest;
    }
};

class Solution1 {
public:
    string findLongestWord(string s, vector<string>& d) {
        string longest="";
        int cur_long=0;
        for(auto tempd:d){
            int pos=0;
            for(int i=0;i<s.length();i++){
                if(s[i]==tempd[pos]){
                    pos++;
                }
            }
            if(pos==tempd.length()){
                if(tempd.length()>cur_long){
                    cur_long=tempd.length();
                    longest=tempd;
                }else if(tempd.length()==cur_long){
                    if(longest.compare(tempd)>0){
                        longest=tempd;
                    }
                }
            }
        }
        return longest;
    }
};


class Solution2 {
public:
    string findLongestWord(string s, vector<string>& d) {
        string longest="";
        int cur_long=0;
        
        std::sort(d.begin(),d.end(),[](const string&left, const string&right){
            if(left.length()>right.length()){
                return true;
            }else if(left.length()==right.length()){
                if(left.compare(right)<0){
                    return true;;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        });
        
        
        for(auto tempd:d){
            int pos=0;
            for(int i=0;i<s.length();i++){
                if(s[i]==tempd[pos]){
                    pos++;
                }
            }
            if(pos==tempd.length()){
                if(tempd.length()>cur_long){
                    cur_long=tempd.length();
                    longest=tempd;
                }else if(tempd.length()==cur_long){
                    if(longest.compare(tempd)>0){
                        longest=tempd;
                    }
                }
            }
        }
        return longest;
    }
};
