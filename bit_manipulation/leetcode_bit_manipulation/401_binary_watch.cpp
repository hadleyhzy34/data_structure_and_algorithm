//
//  401_binary_watch.cpp
//  leetcode_bit_manipulation
//
//  Created by Hadley on 07.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        if(!num){
            return vector<string>{"0:00"};
        }
        vector<string>output;
        for(int i=0;i<11;i++){
            int c=0,ci=0;
            while(c<4){
                if(i&1<<c)ci++;
                c++;
            }
            for(int j=0;j<59;j++){
                int s=0,sj=0;
                while(s<6){
                    if(j&1<<s)sj++;
                    s++;
                }
                if(num==ci+sj){
                    string temp=to_string(i)+":"+to_string(j);
                    output.push_back(temp);
                }
            }
        }
        return output;
    }
};
