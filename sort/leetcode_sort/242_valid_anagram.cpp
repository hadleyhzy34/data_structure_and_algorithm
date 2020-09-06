//
//  242_valid_anagram.cpp
//  leetcode_sort
//
//  Created by Hadley on 08.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s==t){
            return true;
        }else{
            return false;
        }
    }
};
