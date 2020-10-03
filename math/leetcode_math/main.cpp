//
//  main.cpp
//  leetcode_math
//
//  Created by Hadley on 11.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int a=-1;
    unsigned b=a;
    cout<<b<<endl;
    
    //int_min->unsigned(int_max+1)
    a=-pow(2,31);
    unsigned c=a;
    cout<<c<<endl;
    
    //int_max
    int d=pow(2,31)-1;
    cout<<d<<endl;
    //int_min
    int e=-pow(2,31);
    cout<<e<<endl;
    //unsigned_max
    unsigned f=pow(2,32)-1;
    cout<<f<<endl;
    
    cout<<INT_MAX<<" "<<INT_MIN<<endl;
    return 0;
}
