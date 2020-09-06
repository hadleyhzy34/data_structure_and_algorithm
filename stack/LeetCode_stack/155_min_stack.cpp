//
//  155_min_stack.cpp
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
#include <vector>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        Min_stack.push_back(x);
    }
    
    void pop() {
        Min_stack.erase(Min_stack.end()-1);
    }
    
    int top() {
        return Min_stack[Min_stack.size()-1];
    }
    
    int getMin() {
        return *min_element(Min_stack.begin(), Min_stack.end());
    }
private:
    vector<int>Min_stack;
};
