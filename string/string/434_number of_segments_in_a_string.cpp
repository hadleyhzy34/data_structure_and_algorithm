//
//  434_number of_segments_in_a_string.cpp
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
    int countSegments(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            if(!isspace(s[i])){
                count++;
                while (!isspace(s[i])) {
                    i++;
                }
            }
        }
        return count;
    }
};
