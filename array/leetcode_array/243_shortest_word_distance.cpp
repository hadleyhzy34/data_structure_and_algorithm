//
//  243_shortest_word_distance.cpp
//  leetcode_array
//
//  Created by Hadley on 27.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int i=-1,j=-1;
        int dis=words.size()-1;
        for(int z=0;z<words.size();z++){
            if(words[z]==word1){
                i=z;
                if(i!=-1&&j!=-1){
                    dis=min(dis,abs(i-j));
                }
            }else if(words[z]==word2){
                j=z;
                if(i!=-1&&j!=-1){
                    dis=min(dis,abs(i-j));
                }
            }else{
                continue;
            }
        }
        return dis;
    }
};
