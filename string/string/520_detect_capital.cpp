//
//  520_detect_capital.cpp
//  string
//
//  Created by Hadley on 24.09.20.
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
    bool detectCapitalUse(string word) {
        int sign=0;
        for(int i=word.size()-1;i>=0;i--){
            if(i==word.size()-1){
                if(isupper(word[i])){
                    sign=1;
                }else{
                    sign=0;
                }
            }else{
                if(sign==1&&islower(word[i])){
                    return false;
                }else if(sign==0&&isupper(word[i])){
                    if(i!=0)return false;
                }
            }
        }
        return true;
    }
};
