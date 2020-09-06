//
//  13_roman_to_integer.cpp
//  leetcode_math
//
//  Created by Hadley on 11.08.20.
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
    int romanToInt(string s) {
        int output=0;
        
        unordered_map<string, int>dict;
        dict["IV"]=4;
        dict["IX"]=9;
        dict["XL"]=40;
        dict["XC"]=90;
        dict["CD"]=400;
        dict["CM"]=900;
        
        unordered_map<char, int>dic;
        dic['I']=1;
        dic['V']=5;
        dic['X']=10;
        dic['L']=50;
        dic['C']=100;
        dic['D']=500;
        dic['M']=1000;
        
        for(int i=0;i<s.length();i++){
            if(i!=s.length()-1&&dict.find(s.substr(i,2))!=dict.end()){
                output+=dict[s.substr(i,2)];
                i++;
            }else if(dic.find(s[i])!=dic.end()){
                output+=dic[s[i]];
            }
        }
        return output;
    }
};
