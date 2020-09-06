//
//  418_sentence_screen_fitting.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 22.07.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <queue>
#include <functional>
#include <numeric>
using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int c=0;
        auto n=sentence.size();
        
        int curIndex=0;
        for(int i=1;i<rows;i++){
            int cur_length=cols;
            //remember length() returns unsigned value and cannot be used to compare with integers
            while(cur_length>=sentence[curIndex].length()){
                cur_length=cur_length-sentence[curIndex].length()-1;
                curIndex++;
                if(curIndex==n){
                    curIndex=0;
                    c++;
                }
            }
        }
        return c;
    }
};
