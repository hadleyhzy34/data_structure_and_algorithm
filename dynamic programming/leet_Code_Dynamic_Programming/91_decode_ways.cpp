//
//  62_unique_paths.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 14.07.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <queue>
#include <functional>
#include <numeric>
using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int numD[s.size()];
        if(std::stoi(s.substr(0,1))==0){
            return 0;
        }else{
            numD[0]=1;
        }
        
        for(int i=1;i<s.size();i++){
            if(std::stoi(s.substr(i-1,2))<=26&&std::stoi(s.substr(i-1,2))>=10){
                if(std::stoi(s.substr(i,1))==0){
                    if(i>=2&&std::stoi(s.substr(i-2,2))<=26){
                        numD[i]=numD[i-1]-1;
                    }else{
                        numD[i]=numD[i-1];
                    }
                }else{
                    numD[i]=numD[i-1]+1;
                }
            }else if(std::stoi(s.substr(i-1,2))==0){
                return 0;
            }else if(std::stoi(s.substr(i,1))==0){
                return 0;
            }else{
                numD[i]=numD[i-1];
            }
        }
        return numD[s.size()-1];
    }
};



