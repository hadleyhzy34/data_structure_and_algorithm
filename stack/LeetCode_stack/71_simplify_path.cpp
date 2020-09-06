//
//  71_simplify_path.cpp
//  LeetCode_stack
//
//  Created by Hadley on 24.04.20.
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


class Solution71 {
public:
    string simplifyPath(string path) {
        stack<string>s;
        auto it=path.begin();
        while(it!=path.end()){
            // cout<<*it<<endl;
            if(*it=='/'){
                if(it==path.end()-1){
                    break;
                }
                string t="";
                it++;
                while(it!=path.end()&&*it!='/'){
                    t.push_back(*it);
                    it++;
                }
                cout<<t<<endl;
                if(t==".."){
                    if(!s.empty()){
                        s.pop();
                    }
                    continue;
                }else if(t=="."||t==""){
                    continue;
                }else{
                    s.push(t);
                    continue;
                }
            }
            it++;
        }
        string route="";
        while(!s.empty()){
            route='/'+s.top()+route;
            s.pop();
        }
        if(route.empty()){
            route='/';
        }
        return route;
    }
};
