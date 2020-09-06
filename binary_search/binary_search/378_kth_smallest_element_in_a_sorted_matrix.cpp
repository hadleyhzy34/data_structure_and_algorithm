//
//  378_kth_smallest_element_in_a_sorted_matrix.cpp
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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int count=1;
        int i=0,j=0;
        auto m=matrix.size();
        auto n=matrix[0].size();
        vector<pair<int, int>> kth{make_pair(0, 0),make_pair(0, 1),make_pair(1,0)};
        while(i<m&&j<n){
            if(count==k)return matrix[i][j];
            if(matrix[kth[i].first][kth[i].second]<matrix[kth[i].first][kth[i].second]){
                count++;
                
            }
        }
    }
};
