//
//  225_implement_stack_using_queues.cpp
//  LeetCode_stack
//
//  Created by Hadley on 23.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        vector<int>stack;
        while (!q.empty()) {
            stack.push_back(q.front());
            q.pop();
        }
        for(auto it=stack.begin();it!=stack.end()-1;it++){
            q.push(*it);
        }
        return stack[stack.size()-1];
        
    }
    
    /** Get the top element. */
    int top() {
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q.empty()){return true;}else{
            return false;
        }
    }
};
