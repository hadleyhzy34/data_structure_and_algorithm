//
//  464_can_i_win.cpp
//  Minimax
//
//  Created by Hadley on 04.08.20.
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
    bool checkWin(vector<int> ing, int maxTotal, int desiredTotal){
        int total=0;
        for(auto &x:ing){
            total+=x;
        }
        if(maxTotal-total>=desiredTotal)return true;
        bool temp=true;;
        for(int i=0;i<ing.size();i++){
            vector<int>t=ing;
            t.erase(t.begin()+i);
            temp=temp&&checkWin(t, maxTotal, desiredTotal);
        }
        return !temp;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        vector<int>v;
        int total=0;
        for(int i=1;i<=maxChoosableInteger;i++){
            v.push_back(i);
            total+=i;
        }
        return checkWin(v, total, desiredTotal);
    }
};

class Solution2 {
public:
    bool checkWin(int mask, int currentTotal, int maxChoosableInteger, int desiredTotal){
        if(currentTotal>=desiredTotal)return false;
        bool temp=true;
        for(int i=1;i<=maxChoosableInteger;i++){
            if(mask&(1<<i)){
                temp&=checkWin(mask&!(1<<i),currentTotal+i,maxChoosableInteger,desiredTotal);
            }
        }
        return !temp;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int maxTotal=(1+maxChoosableInteger)*maxChoosableInteger/2;
        if(desiredTotal==0)return false;
        int mask=pow(2,maxChoosableInteger)-1;
        return checkWin(mask, 0, maxChoosableInteger, desiredTotal);
    }
};

class Solution3 {
public:
    unordered_map<pair<int, int>, bool> v;
    
    bool checkWin(int mask, int currentTotal, int maxChoosableInteger, int desiredTotal){
        if(currentTotal>=desiredTotal)return false;
        bool temp=true;
        for(int i=1;i<=maxChoosableInteger;i++){
            if(mask&(1<<i)){
                temp&=checkWin(mask&!(1<<i),currentTotal+i,maxChoosableInteger,desiredTotal);
            }
        }
        return !temp;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int maxTotal=(1+maxChoosableInteger)*maxChoosableInteger/2;
        v[make_pair(0, 0)]=false;
        int mask=0;
        for(int i=1;i<=maxChoosableInteger;i++){
            
        }
        if(desiredTotal==0)return false;
        int mask=pow(2,maxChoosableInteger)-1;
        return checkWin(mask, 0, maxChoosableInteger, desiredTotal);
    }
};
