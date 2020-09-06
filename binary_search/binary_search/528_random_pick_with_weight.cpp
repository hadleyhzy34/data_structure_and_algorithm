//
//  528_random_pick_with_weight.cpp
//  binary_search
//
//  Created by Hadley on 11.08.20.
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
    Solution(vector<int>& w) {
            n=w.size();
            this->w=w;
            for(int i=0;i<n;i++){
                total+=w[i];
                b.push_back(total);
            }
        }
        
        int pickIndex() {
            int x=rand()%total+1;
            int l=0,r=n-1;
            while(l<=r){
                int m=l+(r-l)/2;
                if(b[m]==x){
                    return m;
                }else if(b[m]>x){
                    if(m==0||b[m-1]<x){
                        return m;
                    }else{
                        r=m-1;
                    }
                }else{
                    l=m+1;
                }
            }
            return 0;
        }
    
private:
    int total=0;
    int n;
    vector<int> w;
    vector<int> b;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
