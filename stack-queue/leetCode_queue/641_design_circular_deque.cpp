//
//  641_design_circular_deque.cpp
//  leetCode_queue
//
//  Created by Hadley on 07.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }else{
            if(q.empty()){
                q.push_back(value);
                return true;
            }else{
                q.insert(q.begin(), value);
                return true;
            }
        }
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }else{
            q.push_back(value);
            return true;
        }
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }else{
            q.erase(q.begin());
            return true;
        }
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }else{
            q.erase(q.end()-1);
            return true;
        }
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()){
            return -1;
        }else{
            return q[0];
        }
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()){
            return -1;
        }else{
            return q[q.size()-1];
        }
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(q.empty()){
            return true;
        }else{
            return false;
        }
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(q.size()==size){
            return true;
        }else{
            return false;
        }
    }
private:
    vector<int>q;
    int size;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
