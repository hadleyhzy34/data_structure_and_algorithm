//
//  271_encode_and_decode_strings.cpp
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

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        string div(1,(char)257);
        for(int i=0;i<strs.size();i++){
            res+=strs[i];
            res+=div;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string>res;
        string temp;
        for(auto x:s){
            if(x==(char)257){
                res.push_back(temp);
                temp="";
            }else{
                temp+=x;
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
