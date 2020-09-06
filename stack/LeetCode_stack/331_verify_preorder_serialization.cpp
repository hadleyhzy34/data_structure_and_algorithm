//
//  331_verify_preorder_serialization.cpp
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

class Solution331 {
public:
    bool isValidSerialization(string preorder) {
        stack<string>bt;
        for(auto it=preorder.begin();it!=preorder.end();it++){
            if(*it==',')continue;
            string t;
            while(it!=preorder.end()&&*it!=','){
                t+=*it;
                it++;
            }
            it--;
            if(t=="#"){
                if(bt.empty()){
                    bt.push(t);
                    continue;
                }
                
                if(bt.top()!="#"){
                    bt.push("#");
                }else{
                    if(bt.size()<2){
                        return false;
                    }
                    bt.pop();
                    bt.pop();
                    while(bt.size()>2&&bt.top()=="#"){
                        bt.pop();
                        bt.pop();
                    }
                    bt.push("#");
                }
            }else{
                bt.push(t);
            }
        }
        if(bt.size()==1&&bt.top()=="#"){
            return true;
        }else{
            return false;
        }
    }
};
