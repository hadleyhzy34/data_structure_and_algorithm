//
//  89_gray_code.cpp
//  leetcode_backtracking
//
//  Created by Hadley on 05.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

class Solution {
public:
    void utils(bitset<32>& bits, vector<int>& result, int k){
            if (k==0) {
                result.push_back(bits.to_ulong());
            }
            else {
                utils(bits, result, k-1);
                bits.flip(k-1);
                utils(bits, result, k-1);
            }
        }
    public:
        vector<int> grayCode(int n) {
            bitset<32> bits;
            vector<int> result;
            utils(bits, result, n);
            return result;
        }
};

class Solution2 {
public:
    vector<int> grayCode(int n) {
        vector<int> result={0};
        for(int i=0;i<n;i++){
            int temp=1<<i;
            int s=result.size();
            while(s){
                int t=temp|result[--s];
                result.push_back(t);
            }
        }
        return result;
    }
};
