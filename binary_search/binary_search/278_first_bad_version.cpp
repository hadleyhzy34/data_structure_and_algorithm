//
//  278_first_bad_version.cpp
//  binary_search
//
//  Created by Hadley on 05.08.20.
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

// The API isBadVersion is defined for you.
 bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n;
        while(l<=r){
            int m=l+(r-l)/2;
            if(isBadVersion(m)==false){
                if(isBadVersion(m+1)==true){
                    return m+1;
                }else{
                    l=m+1;
                }
            }else{
                r=m-1;
            }
        }
        return 1;
    }
};
