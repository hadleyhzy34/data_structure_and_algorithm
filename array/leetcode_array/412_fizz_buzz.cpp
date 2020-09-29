//
//  412_fizz_buzz.cpp
//  leetcode_array
//
//  Created by Hadley on 29.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i=1;i<=n;i++){
            if(i%3==0&&i%5==0){
                res.push_back("FizzBuzz");
            }else if(i%3==0){
                res.push_back("Fizz");
            }else if(i%5==0){
                res.push_back("Buzz");
            }else{
                res.push_back(to_string(i));
            }
        }
        return res;
    }
};
