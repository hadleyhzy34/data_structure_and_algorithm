//
//  flip_game_2.cpp
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
    bool canWin(string s) {
        for(int i=0;i<s.size();i++){
            cout<<i<<" "<<s[i]<<" "<<s[i+1]<<endl;
            if(s[i]==s[i+1]&&s[i]=='+'){
                s[i]=s[i+1]='-';
                if(!canWin(s))return true;
                s[i]=s[i+1]='+';
            }
        }
        return false;
    }
};
