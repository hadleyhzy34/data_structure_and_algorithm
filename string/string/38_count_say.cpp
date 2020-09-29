//
//  38_count_say.cpp
//  string
//
//  Created by Hadley on 22.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<string>res(n+1);
        for(int i=1;i<=n;i++){
            if(i==1){
                res[i]+="1";
            }else{
                for(int j=0;j<res[i-1].length();j++){
                    int count=1;
                    while(j!=res[i-1].length()-1&&res[i-1][j]==res[i-1][j+1]){
                        count++;j++;
                    }
                    res[i]+=to_string(count);
                    res[i].push_back(res[i-1][j]);
                }
            }
        }
        return res[n];
    }
};
