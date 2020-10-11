//
//  429_nary_tree_level_order_traversal.cpp
//  leetcode_tree
//
//  Created by Hadley on 11.07.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <queue>
#include <functional>
#include <numeric>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    Solution():count(1024,1){
    }
    
    int countTrees(int n){
        if(!n)return 1;
        if(count[n]!=1)return count[n];
        
        count[n]=0;
        for(int i=1;i<=n;i++){
            count[n]+=countTrees(i-1)*countTrees(n-i);
        }
        return count[n];
    }
    int numTrees(int n) {
//        for(int i=0;i<1024;i++)
//            count[i] = 1;
        return countTrees(n);
    }
private:
    vector<int> count;
};


class Solution2 {
public:
    int numTrees(int n) {
        
    }
};

