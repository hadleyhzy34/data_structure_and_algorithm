//
//  544_output_contest_matches.cpp
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
    string findContestMatch(int n) {
        vector<string>team(n+1);
        for(int i=1;i<=n;i++){
            team[i]=to_string(i);
        }
        
        for(;n>1;n/=2){
            for(int i=1;i<=n/2;++i){
                team[i]="("+team[i]+","+team[n-i+1]+")";
            }
        }
        return team[1];
    }
};
