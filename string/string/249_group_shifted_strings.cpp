//
//  group_shifted_strings.cpp
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
#include <cstdlib>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string getShiftedString(const string &s) {
        string shifted;
        
        for(auto c:s){
            shifted.push_back('a'+(c-s[0]+26)%26);
        }
        
        return shifted;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string> > m;
        for(auto &s : strings){
            m[getShiftedString(s)].push_back(s);
        }
        
        vector<vector<string> > result(m.size());
        int i = 0;
        for(auto &p : m){
            result[i++] = p.second;
        }
        
        return result;
    }
};
