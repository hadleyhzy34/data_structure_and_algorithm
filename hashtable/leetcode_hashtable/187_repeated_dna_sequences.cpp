//
//  187_repeated_dna_sequences.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 18.08.20.
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
#include <map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        unordered_map<string, int>map;
        for(int i=0;i<s.length();i++){
            if(i<9){
                continue;
            }else{
                if(map.find(s.substr(i-10+1,10))!=map.end()){
                    if(map[s.substr(i-10+1,10)]==1){
                        res.push_back(s.substr(i-10+1,10));
                    }
                }
                map[s.substr(i-10+1,10)]++;
            }
        }
        return res;
    }
};
