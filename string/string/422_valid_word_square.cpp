//
//  422_valid_word_square.cpp
//  string
//
//  Created by Hadley on 29.09.20.
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
    bool validWordSquare(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            // if(words[0].size()!=words[i].size())return false;
            for(int j=0;j<words[i].size();j++){
                if(j<words.size()&&i<words[j].size()){
                    if(words[i][j]!=words[j][i]){
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
