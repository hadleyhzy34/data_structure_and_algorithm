//
//  496_next_greater_element.cpp
//  LeetCode_stack
//
//  Created by Hadley on 23.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        queue<int>q;
        vector<int>output;
        for(auto num2:nums2){
            q.emplace(num2);
        }
        for(auto num1:nums1){
            for(auto it=nums2.begin();it!=nums2.end();it++){
                if(num1==*it){
                    while (it!=nums2.end()) {
                        if(it==nums2.end()-1){
                            output.push_back(-1);
                            break;
                        }
                        it++;
                        if(*it>num1){
                            output.push_back(*it);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return output;
    }
};


class Solution2 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>output;
        stack<int>st;
        for(auto num2:nums2){
            st.push(num2);
        }
        for(auto num1:nums1){
            stack<int>s(st);
            int b=-1;
            while(!s.empty()){
                if(num1==s.top()){
                    output.push_back(b);
                    break;
                }
                if(s.top()>num1){
                    b=s.top();
                }
                s.pop();
            }
        }
        return output;
    }
};
