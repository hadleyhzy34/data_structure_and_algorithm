//
//  394_decode_string.cpp
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

class Solution {
public:
    string decodeString(string s) {
stack<char>t;
for(auto it=s.begin();it!=s.end();it++){
    string temp;
    string tem;
    if(*it==']'){
        while(t.top()!='['){
            temp=t.top()+temp;
            t.pop();
        }
        t.pop();
        int index=0;
        int cofl=0;
        while(!t.empty()&&isdigit(t.top())){
            cofl=(int(t.top())-48)*pow(10,index)+cofl;
            index++;
            t.pop();
        }
        if(cofl){
            int count=1;
            string tem=temp;
            while(count<cofl){
                temp+=tem;
                count++;
            }
        }
        for(auto i:temp){
            t.push(i);
        }
        cout<<temp<<endl;
    }else{
        t.push(*it);
    }
}
string output;
while(!t.empty()){
    output=t.top()+output;
    t.pop();
}
return output;
    }
};
