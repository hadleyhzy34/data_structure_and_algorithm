//
//  14_longest_common_prefix.cpp
//  string
//
//  Created by Hadley on 22.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int length=0;
        if(strs.empty())return "";
        for(int i=0;i<strs[0].length();i++){
            for(int j=0;j<strs.size();j++){
                if(i>=strs[j].length()||strs[0][i]!=strs[j][i]){
                    return strs[0].substr(0,length);
                }
            }
            length++;
        }
        return strs[0];
    }
};
