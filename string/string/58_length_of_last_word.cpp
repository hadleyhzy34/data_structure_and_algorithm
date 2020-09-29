//
//  58_length_of_last_word.cpp
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
    int lengthOfLastWord(string s) {
        string res="";
        for (int j=s.length()-1; j>=0; j--) {
            if(isspace(s[j])){
                if(res.length()!=0){
                    return res.length();
                }else{
                    continue;
                }
            }else{
                res.push_back(s[j]);
            }
        }
        return res.length();
    }
};
