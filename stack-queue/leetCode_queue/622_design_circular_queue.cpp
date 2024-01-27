//
//  622_design_circular_queue.cpp
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

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(value>=0&&value<=1000&&q.size()<size){
            q.push_back(value);
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(q.empty()){
            return false;
        }else{
            q.erase(q.begin());
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(q.empty()){
            return -1;
        }else{
        return q[0];
        }
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(q.empty()){
            return -1;
        }else{
        return q[q.size()-1];
        }
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(q.empty()){
            return true;
        }else{
            return false;
        }
    }
    
    /** Checks whether the circular queue is full or not. */
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
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
