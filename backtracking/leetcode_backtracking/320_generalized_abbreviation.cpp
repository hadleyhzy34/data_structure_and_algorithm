//
//  320_generalized_abbreviation.cpp
//  leetcode_backtracking
//
//  Created by Hadley on 24.08.20.
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
#include <map>
using namespace std;

class Solution {
public:
    void abbreviationsGenerate(string &word, int index, vector<string>&res){
        if(index==word.length()){
            res.push_back(word);
            return;
        }
        for(int i=0;i<=1;i++){
            if(i==0){
                abbreviationsGenerate(word, index+1, res);
            }else{
                char temp=word[index];
                word[index]='1';
                abbreviationsGenerate(word, index+1, res);
                word[index]=temp;
            }
        }
    }
    
    vector<string> generateAbbreviations(string word) {
        vector<string>res1;
        abbreviationsGenerate(word, 0, res1);
        vector<string>res2;
        // for(auto x:res1){
        //     cout<<x<<endl;
        // }
        for(int i=0;i<res1.size();i++){
            string temp;
            for(int j=0;j<res1[i].length();j++){
                int count=0;
                while(isdigit(res1[i][j])){
                    count++;
                    j++;
                }
                if(count>0){
                    temp.append(to_string(count));
                    j--;
                }else{
                    temp.push_back(res1[i][j]);
                }
            }
            cout<<temp<<endl;
            res2.push_back(temp);
        }
        return res2;
    }
};
