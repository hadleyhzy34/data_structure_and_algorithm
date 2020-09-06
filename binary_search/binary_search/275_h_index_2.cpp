//
//  275_h_index_2.cpp
//  binary_search
//
//  Created by Hadley on 09.08.20.
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
    int hIndex(vector<int>& citations) {
        if(citations.empty())return 0;
        auto n=citations.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            cout<<l<<" "<<r<<" "<<m<<endl;
            if(citations[m]>=(n-1)-m+1){
                if(m==0||citations[m-1]<(n-1)-m+2){
                    return (n-1)-m+1;
                }else{
                    r=m-1;
                }
            }else{
                l=m+1;
            }
        }
        return 0;
    }
};
