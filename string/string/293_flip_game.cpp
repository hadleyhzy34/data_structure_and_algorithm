//
//  293_flip_game.cpp
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
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                if(s[i]=='+'){
                    string temp=s;
                    temp[i]='-';
                    temp[i+1]='-';
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
