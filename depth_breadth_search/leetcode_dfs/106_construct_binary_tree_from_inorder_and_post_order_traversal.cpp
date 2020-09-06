//
//  106_construct_binary_tree_from_inorder_and_post_order_traversal.cpp
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


class Solution {
public:
    TreeNode* treeBuild(vector<int>& inorder, vector<int>& postorder, int pl, int pr, int il, int ir){
        if(pl>pr||il>ir)return nullptr;
        TreeNode* t=new TreeNode(postorder[pr]);
        if(pl==pr)return t;
        int j=find(inorder.begin(),inorder.end(),postorder[pr])-inorder.begin();
        //number of nodes that are left of current root
        int n=j-il;
        //number of nodes that are right of current root
//        int m=ir-j;
        // cout<<pl<<" "<<pr<<" "<<il<<" "<<ir<<" "<<t->val<<" "<<j<<" "<<n<<endl;
        t->left=treeBuild(inorder, postorder, pl, pl+n-1,il,j-1);
        t->right=treeBuild(inorder, postorder,pl+n,pr-1, j+1,ir);
        return t;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int r=postorder.size()-1;
        return treeBuild(inorder, postorder, 0, r,0,r);
    }
};

class Solution2 {
public:
    TreeNode* treeBuild(vector<int>& inorder, vector<int>& postorder, int pl, int pr, int il, int ir){
        if(pl>pr)return nullptr;
        TreeNode* t=new TreeNode(postorder[pr]);
        if(pl==pr)return t;
        int j=map[postorder[pr]];
//        int j=find(inorder.begin(),inorder.end(),postorder[pr])-inorder.begin();
        //number of nodes that are left of current root
        int n=j-il;
        //number of nodes that are right of current root
//        int m=ir-j;
        // cout<<pl<<" "<<pr<<" "<<il<<" "<<ir<<" "<<t->val<<" "<<j<<" "<<n<<endl;
        t->left=treeBuild(inorder, postorder, pl, pl+n-1,il,j-1);
        t->right=treeBuild(inorder, postorder,pl+n,pr-1, j+1,ir);
        return t;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int r=postorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        return treeBuild(inorder, postorder, 0, r,0,r);
    }
private:
    unordered_map<int, int>map;
};
