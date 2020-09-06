//
//  211_design_add_and_search_words_data_structure.cpp
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

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        auto n=dict.size();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        dict.push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(find(dict.begin(), dict.end(), word)!=dict.end()){
            return true;
        }else{
            if(find(word.begin(),word.end(),'.')!=word.end()){
                for(auto x:dict){
                    string temp=word;
                    for(int i=0;i<word.length();i++){
                        if(temp[i]=='.')temp[i]=x[i];
                    }
                    if(temp==x)return true;
                }
                return false;
            }else{
                return false;
            }
        }
    }
private:
    vector<string>dict;
    vector<string>test;
    int n;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
