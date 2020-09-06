//
//  244_shortest_world_distance_2.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 18.08.20.
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

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        this->words=words;
        for(int i=0;i<words.size();i++){
            dict[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> d1=dict[word1],d2=dict[word2];
        int shortLength=words.size();
        // for(auto x:d1){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto x:d2){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        int i=0,j=0;
        while(i<d1.size()||j<d2.size()){
            if(d1[i]<d2[j]){
                shortLength=min(shortLength,abs(d2[j]-d1[i]));
                // cout<<i<<" "<<j<<" "<<shortLength<<endl;
                if((i+1)<d1.size()){
                    i++;
                }else{
                    break;
                }
            }else{
                shortLength=min(shortLength,abs(d2[j]-d1[i]));
                // cout<<i<<" "<<j<<" "<<shortLength<<endl;
                if((j+1)<d2.size()){
                    j++;
                }else{
                    break;
                }
            }
        }
        return shortLength;
    }
private:
    vector<string> words;
    unordered_map<string, vector<int>>dict;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
