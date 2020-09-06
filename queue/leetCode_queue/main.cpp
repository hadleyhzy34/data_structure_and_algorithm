//
//  main.cpp
//  leetCode_queue
//
//  Created by Hadley on 06.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include "641_design_circular_deque.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    MyCircularDeque *circularDeque = new MyCircularDeque(3); // set the size to be 3
    circularDeque->insertLast(1);            // return true
     // return 4
    return 0;
}
