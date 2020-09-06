//
//  292_nim_game.cpp
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
    bool canWinNim(int n) {
        if(n<=3)return true;
        vector<pair<bool, bool>> L(n+1,make_pair(false, false));
        
        L[0].first=false;
        L[0].second=false;
        L[1].first=true;
        L[1].second=true;
        L[2].first=true;
        L[2].second=true;
        L[3].first=true;
        L[3].second=true;
        
        for(int i=4;i<=n;i++){
            L[i].first=!(L[i-1].second&&L[i-2].second&&L[i-3].second);
            L[i].second=!(L[i-1].first&&L[i-2].first&&L[i-3].first);
        }
        return L[n].first;
    }
};

class Solution2 {
public:
    bool checkWin(int n,bool check){
        if(n<3&&n>0){
            return true;
        }
        if(n==0)return false;
        return !(checkWin(n-1, !check)&&checkWin(n-2, !check)&&checkWin(n-3, !check));
    }
    bool canWinNim(int n) {
        return checkWin(n, true);
    }
};

class Solution3 {
public:
    bool canWinNim(int n) {
        if(n<=3)return true;
        vector<bool> L(n+1,false);
        
        L[0]=false;
        L[1]=true;
        L[2]=true;
        L[3]=true;
        
        for(int i=4;i<=n;i++){
            L[i]=!(L[i-1]&&L[i-2]&&L[i-3]);
        }
        return L[n];
    }
};
