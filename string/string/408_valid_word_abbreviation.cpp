//
//  408_valid_word_abbreviation.cpp
//  string
//
//  Created by Hadley on 24.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <stack>
#include <cstdlib>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i=0,j=0;
        while(i<word.size()&&j<abbr.size()){
            int n=0;
            if(abbr[j]=='0')return false;
            while(j<abbr.size()&&isdigit(abbr[j])){
                n=n*10+abbr[j]-'0';
                j++;
            }
            if(n!=0){
                i=i+n;
            }else{
                if(word[i]!=abbr[j]){
                    cout<<word[i]<<" "<<abbr[j]<<endl;
                    return false;
                }else{
                    i++;
                    j++;
                }
            }
        }
        cout<<i<<" "<<j<<endl;
        return i==word.size()&&j==abbr.size();
    }
};


class Solution_2 {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int j=0;
        for(int i=0;i<abbr.size();i++){
            if(isalpha(abbr[i])){
                if(abbr[i]!=word[j]){
                    return false;
                }else{
                    j++;
                }
            }else{
                int cnt=0;
                while(isdigit(abbr[i])){
                    cnt=cnt*10+abbr[i]-'0';
                    i++;
                }
                i--;
                j+=cnt;
                if(j>=word.size())return false;
            }
        }
        return true;
    }
};
