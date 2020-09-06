//
//  109_convert_sorted_list_to_bianry_search_tree.cpp
//  leetcode_dfs
//
//  Created by Hadley on 26.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include <fstream>
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
#include <map>
#include <filesystem>
#include <dirent.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    TreeNode* tobst(vector<int>& inorder, int l, int r){
        if(l>r)return nullptr;
        auto n=(r-l+1)/2+l;
        TreeNode* t=new TreeNode(inorder[n]);
        if(l==r)return t;
        t->left=tobst(inorder,l,n-1);
        t->right=tobst(inorder,n+1,r);
        return t;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>res;
        while (head) {
            res.push_back(head->val);
            head=head->next;
        }
        return tobst(res, 0, res.size()-1);
    }
};
