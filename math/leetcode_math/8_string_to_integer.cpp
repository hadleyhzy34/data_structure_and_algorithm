//
//  8_string_to_integer.cpp
//  leetcode_math
//
//  Created by Hadley on 12.08.20.
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
    int myAtoi(string str) {
        int res=0;
        bool positive=true;
        
        for(int i=0;i<str.length();i++){
            if(isspace(str[i])){
                continue;
            }else if(isdigit(str[i])){
                if(res<=(INT_MAX-(int)(str[i]-'0'))/10){
                    res=res*10+(int)(str[i]-'0');
                    // cout<<(int)(str[i]-'0')<<" "<<res<<endl;
                }else{
                    return (positive==true)?INT_MAX:INT_MIN;
                }
                if(i<str.length()-1&&!isdigit(str[i+1])){
                    if(isspace(str[i+1])){
                        break;
                    }else{
                        return (positive==true)?res:-res;
                    }
                }
            }else if(str[i]=='+'){
                positive=true;
                if(i==str.length()-1||!isdigit(str[i+1]))break;
            }else if(str[i]=='-'){
                positive=false;
                if(i==str.length()-1||!isdigit(str[i+1]))break;
            }else{break;}
        }
                   
        return (positive==true)?res:-res;
    }
};
