//
//  573_squirrel_simulation.cpp
//  leetcode_math
//
//  Created by Hadley on 13.08.20.
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
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        vector<int>distance;
        int total=0;
        int minD=INT_MAX;
        int index=0;
        for(int i=0;i<nuts.size();i++){
            int n2t=abs(nuts[i][0]-tree[0])+abs(nuts[i][1]-tree[1]);
            int s2n=abs(squirrel[0]-nuts[i][0])+abs(squirrel[1]-nuts[i][1]);
            if(s2n-n2t<minD){
                minD=s2n-n2t;
                index=i;
            }
            total+=2*(n2t);
        }
        // cout<<total<<" "<<minD<<endl;
        return total+minD;
    }
};
