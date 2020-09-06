//
//  526_beautiful_arrangement.cpp
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
void arrangment(vector<int>&array, int l, bool divisible){
        if(!divisible)return;
        if(l==array.size()-1){
            // if(checkBeautiful(array))
            for(auto x:array)cout<<x<<" ";
            cout<<endl;
            count++;
            return;
        }
        for(int i=l;i<array.size();i++){
            swap(array[i], array[l]);
            if(array[l]%(l+1)==0||(l+1)%array[l]==0){
                divisible=true;
            }else{
                divisible=false;
            }
            arrangment(array, l+1, divisible);
            swap(array[l], array[i]);
        }
    }
    
    int countArrangement(int N) {
        vector<int>array(N);
        std::iota(array.begin(), array.end(), 1);
        arrangment(array, 0, true);
        return count;
    }
private:
    int count=0;
};
