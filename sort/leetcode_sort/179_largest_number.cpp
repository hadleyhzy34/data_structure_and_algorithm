//
//  179_largest_number.cpp
//  leetcode_sort
//
//  Created by Hadley on 22.06.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

bool numCompare(int &i, int &j){
    string si=to_string(i);
    string sj=to_string(j);
    string a=si+sj;
    string b=sj+si;
    int na=stoi(a);
    int nb=stoi(b);
    return na>nb;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string output;
        vector<string> nums_string;
        for(int i(0);i<=nums.size()-1;i++)
        {
            nums_string.push_back(to_string(nums[i]));
        }
        sort(nums_string.begin(),nums_string.end(),[](string a,string b){
            return a+b>b+a;
        });
        for(auto n:nums_string){
            output+=n;
        }
        return output[0]=='0'?"0":output;
    }
};
