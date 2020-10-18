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
    int count=0;
    void countN(TreeNode* root){
        if(!root) return;
        count++;
        countN(root->left);
        countN(root->right);
    }
    int countNodes(TreeNode* root) {
        countN(root);
        return count;
    }
};


//binary search 
class Solution2 {
public:
    int computeDepth(TreeNode* root){
        int depth=0;
        while(root->left){
            root=root->left;
            depth++;
        }
        return depth;
    }

    bool check(int index, int d, TreeNode* node){
        int left=0,right=pow(2,d)-1;
        int pivot;
        for(int i=0;i<d;i++){
            pivot=left+(right-left)/2;
            if(index<=pivot){
                node=node->left;
                right=pivot;
            }else{
                node=node->right;
                left=pivot+1;
            }
        }
        return node!=nullptr;
    }

    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int d=computeDepth(root);
        
        if(d==0)return 1;

        int left=1, right=pow(2,d)-1;
        int pivot;
        while(left<=right){
            pivot=left+(right-pivot)/2;
            if(check(pivot,d,root)){
                left=pivot+1;
            }else{
                right=pivot-1;
            }
        }

        return pow(2,d)-1+left;
    }
};

