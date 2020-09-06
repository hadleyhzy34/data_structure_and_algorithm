//
//  402_remove_k_digits.cpp
//  LeetCode_stack
//
//  Created by Hadley on 30.04.20.
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

class Solution402 {
public:
    string removeKdigits(string num, int k) {
        stack<char>n;
        int count=1;
        for(auto it=num.begin();it!=num.end();it++){
            if(n.empty()){
                n.push(*it);
            }else{
                    while(!n.empty()&&int(*it)<int(n.top())&&count<=k){
                        n.pop();
                        count++;
                    }
                    n.push(*it);
            }
        }
        string t;
        while(!n.empty()){
            if(count<=k){
                n.pop();
                count++;
                continue;
            }
            t+=n.top();
            n.pop();
        }
        if(t.empty()){
            t="0";
        }
        reverse(t.begin(), t.end());
        //erase leading zeros
        int i=0;
        while(t[i]=='0'){
            i++;
        }
        t.erase(0,i);
        if(t.empty()){
            return "0";
        }
        return t;
    }
};
