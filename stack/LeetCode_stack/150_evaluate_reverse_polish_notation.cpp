//
//  150_evaluate_reverse_polish_notation.cpp
//  LeetCode_stack
//
//  Created by Hadley on 29.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>buff;
        unordered_map<string, int>RPN;
        RPN["+"]=1;
        RPN["-"]=2;
        RPN["*"]=3;
        RPN["/"]=4;
        for(auto it=tokens.begin();it!=tokens.end();it++){
            if(!RPN.count(*it)){
                buff.push(*it);
            }else{
                switch (RPN[*it]) {
                    case 1:
                    {
                        int a=std::stoi(buff.top());
                        buff.pop();
                        int b=std::stoi(buff.top());
                        buff.pop();
                        buff.push(to_string(a+b));
                        break;
                    }
                    
                    case 2:
                    {
                        int c=std::stoi(buff.top());
                        buff.pop();
                        int d=std::stoi(buff.top());
                        buff.pop();
                        buff.push(to_string(d-c));
                        break;
                    }
                    
                    case 3:
                    {
                        int e=std::stoi(buff.top());
                        buff.pop();
                        int f=std::stoi(buff.top());
                        buff.pop();
                        buff.push(to_string(f*e));
                        break;
                    }
                    
                    case 4:
                    {
                        int g=std::stoi(buff.top());
                        buff.pop();
                        int h=std::stoi(buff.top());
                        buff.pop();
                        buff.push(to_string(g/h));
                        break;
                    }
                        
                    default:
                        break;
                }
            }
        }
        return std::stoi(buff.top());
    }
};
