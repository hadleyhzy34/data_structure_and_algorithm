//
//  383_ransom_note.cpp
//  string
//
//  Created by Hadley on 24.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
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
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>dict;
        for(auto &x:magazine){
            dict[x]++;
        }
        for(auto &x:ransomNote){
            if(dict[x]<=0)return false;
            dict[x]--;
        }
        return true;
    }
};
