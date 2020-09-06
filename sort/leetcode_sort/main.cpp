//
//  main.cpp
//  leetcode_sort
//
//  Created by Hadley on 08.05.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include "252_meeting_rooms.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<pair<int,int>>t{{1,2},{3,4},{5,6}};
    Solution252 test1;
    cout<<test1.couldAttend(t);
    return 0;
}
