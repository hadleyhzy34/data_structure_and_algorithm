//
//  532_k_diff_pairs_in_an_array.cpp
//  leetcode_array
//
//  Created by Hadley on 20.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> diff;
        if(k<0){return 0;}
        if(!k){
            for(auto it=nums.begin();it!=nums.end();it++){
                if(find(it+1,nums.end(),*it)!=nums.end()){
                    diff[*it]++;
                }
            }
            return static_cast<int>(diff.size());
        }
        for(auto it=nums.begin();it!=nums.end();it++){
            if(find(nums.begin(),nums.end(),*it+k)!=nums.end()){
                diff[*it]++;
            }
        }
        return static_cast<int>(diff.size());
    }
};

class Solution2 {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() < 2 || k < 0)
                return 0;
            
            if (0 == k)
            {
                std::unordered_map<int, int> m;
                for (auto n : nums)
                    ++m[n];
                return std::count_if(m.begin(), m.end(), [](auto const &p){ return p.second > 1; });
            }

            std::unordered_set<int> m{nums.begin(), nums.end()};
            return std::count_if(m.begin(), m.end(), [&m, k](auto n){ return m.count(n + k); });
        }
};

