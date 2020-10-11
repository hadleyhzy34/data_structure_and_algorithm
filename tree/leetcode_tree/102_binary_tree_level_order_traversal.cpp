//
//  107_binary_tree_level_order_traversal.cpp
//  leetcode_tree
//
//  Created by Hadley on 23.06.20.
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
using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//void printLevelOrder(TreeNode *root){
//    if(root==NULL) return;
//            
//            queue<TreeNode *> q;
//            vector<int>d;
//            
//    int depth=0;
//            q.push(root);
//    d.push_back(depth);
//            
//            while(q.empty()==false){
//    //            res.push_back(q.front());
//                
//                if(q.front()->left!=NULL)
//                    q.push(root->left);
//                    d.push_back(d.front()+1);
//                if(q.front()->right!=NULL)
//                    q.push(root->right);
//                    d.push_back(d.front()+1);
//                q.pop();
//            }
//}

class Solution107 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return {{}};
        
        queue<pair<TreeNode *,int>>q;
        vector<pair<TreeNode *, int>> c;
                
        q.push(make_pair(root, 0));
                
                while(q.empty()==false){
                    if(q.front().first->left!=NULL)
                        q.push(make_pair(q.front().first->left,q.front().second+1));
                    if(q.front().first->right!=NULL)
                        q.push(make_pair(q.front().first->right,q.front().second+1));
                    c.push_back(q.front());
                    q.pop();
                }
        
        int count=0;
        for(int i=0;i<=c.back().second;i++){
            vector<int>line;
            cout<<i<<" "<<c[count].first->val<<" "<<c[count].second<<endl;
            while(count<c.size()&&i==c[count].second){
                line.push_back(c[count].first->val);
                count++;
            }
            res.push_back(line);
        }
        return res;
    }
};


class Solution107_1 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return {};
        
        queue<pair<TreeNode *,int>>q;
        unordered_map<int,vector<int>> t;
                
        q.push(make_pair(root, 0));
                
                while(q.empty()==false){
                    if(q.front().first->left!=NULL)
                        q.push(make_pair(q.front().first->left,q.front().second+1));
                    if(q.front().first->right!=NULL)
                        q.push(make_pair(q.front().first->right,q.front().second+1));
                    t[q.front().second].push_back(q.front().first->val);
                    q.pop();
                }
        
        vector<pair<int,vector<int>>> ts(t.begin(),t.end());
        std::sort(ts.begin(), ts.end());
        
        for(auto &x:ts){
            res.push_back(x.second);
        }
        return res;
    }
};


//BFS solution https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/699659/C%2B%2B-Easiest-BFS.DFS-explained-solution-4ms-beats-91
class Solution107_3 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return {};
        
        queue<TreeNode *>q;
        q.push(root);
                
        while(!q.empty())
        {
            vector<int> v;
            auto size=q.size();
            while(size--)
            {
                TreeNode *node=q.front();
                q.pop();
                v.push_back(node->val);
                
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
            res.push_back(v);
        }
        return res;
    }
};

//BFS solution using two queue
class Solution107_4 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return {};
        
        queue<TreeNode *>q1,q2;
        q1.push(root);
                
        while(!q1.empty())
        {
            vector<int> v;
            while(!q1.empty()){
                TreeNode *node=q1.front();
                v.push_back(q1.front()->val);
                q1.pop();
                if(node->left!=NULL)
                        q2.push(node->left);
                if(node->right!=NULL)
                        q2.push(node->right);
            }
            swap(q1,q2);
            res.push_back(v);
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> s;
        s.push(root);
        
        vector<vector<int>>res;
        
        while(!s.empty()){
            int size=int(s.size());
            vector<int>t;
            while(size--){
                TreeNode *temp=s.front();
                t.push_back(temp->val);
                s.pop();
                if(temp->left){
                    s.push(temp->left);
                }
                if(temp->right){
                     s.push(temp->right);
                }
            }
            res.push_back(t);
        }
        return res;
    }
};


