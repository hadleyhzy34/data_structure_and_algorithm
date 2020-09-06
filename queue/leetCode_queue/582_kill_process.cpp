//
//  933_number_of_recent_calls.cpp
//  leetCode_queue
//
//  Created by Hadley on 06.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>>umap;
        for(int i=0;i<ppid.size();i++){
            umap[ppid[i]].push_back(pid[i]);
        }
        queue<int>T{{kill}};
        vector<int>output;
        while(!T.empty()){
            int temp=T.front();
            output.push_back(temp);
            T.pop();
            for(auto t:umap[temp]){
                T.push(t);
            }
        }
        return output;
    }
};
