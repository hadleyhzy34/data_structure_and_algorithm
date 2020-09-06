//
//  232_implement_queue_using_stacks.cpp
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

class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        vector<int>c;
        while(!s1.empty()){
            c.push_back(s1.top());
            s1.pop();
        }
        s1.push(x);
        for(auto it=c.rbegin();it!=c.rend();it++){
            s1.push(*it);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int var=s1.top();
        s1.pop();
        return var;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s1.empty()){
            return true;
        }else{
            return false;
        }
    }
};
