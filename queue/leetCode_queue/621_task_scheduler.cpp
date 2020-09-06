//
//  621_task_scheduler.cpp
//  leetCode_queue
//
//  Created by Hadley on 07.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>umap;
        for(auto t:tasks){
            umap[t]++;
        }
        priority_queue<pair<int,char>>q;
        for(auto p:umap){
            q.push({p.second,p.first});
        }
        string op="";
        while(!q.empty()){
            queue<pair<int, char>>tempQ;
            int i=0;
            while(i<=n){
                if(q.empty()){
                    if(!tempQ.empty()){
                    op+="0";
                    }
                    i++;
                }else{
                    op+=q.top().second;
                    auto t=q.top();q.pop();
                    t.first--;
                    if(t.first>0)tempQ.push(t);
                    i++;
                }
            }
            while(!tempQ.empty()){
                q.push(tempQ.front());
                tempQ.pop();
            }
        }
            return op.length();
    }
};
