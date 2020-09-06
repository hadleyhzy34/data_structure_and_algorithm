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



class Solution {
public:
//    void merge(TreeNode* &t1,TreeNode* t2){
//        if(!t1)return;
//        if(!t1)
//            t1=t2;
//        if(!t2)
//            t2=t1;
//        if(!t1&&!t2)
//            t1->val+=t2->val;
//        merge(t1->left,t2->left);
//        merge(t1->right,t2->right);
//    }
    
    TreeNode *node = new TreeNode();
    
    void merge(TreeNode* t1,TreeNode* t2, TreeNode* node){
        if(!t1&&!t2)return;
        
        if(!t1&&t2){
            node->val=t2->val;
            if(t2->left){
                node->left= new TreeNode();
                merge(nullptr, t2->left, node->left);
            }
            if(t2->right){
                node->left= new TreeNode();
                merge(nullptr, t2->right, node->right);
            }
        }
        
        if(t1&&!t2){
            node->val=t1->val;
            if(t1->left){
                node->left= new TreeNode();
                merge(t1->left, nullptr, node->left);
            }
            if(t1->right){
                node->right= new TreeNode();
                merge(t1->right, nullptr, node->right);
            }
        }

        if(t1&&t2){
            node->val=t1->val+t2->val;
            if(t1->left||t2->left){
                node->left= new TreeNode();
                merge(t1->left,t2->left,node->left);
            }
            if(t1->right||t2->right){
                node->right= new TreeNode();
                merge(t1->right,t2->right,node->right);
            }
        }
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1&&!t2)return nullptr;
        merge(t1, t2,node);
        return node;
    }
};

class Solution1 {
public:
    TreeNode* mergeTrees(TreeNode* &t1,TreeNode* t2){
        if(!t1&&!t2)return nullptr;
        if(!t1)
            t1=t2;
        if(!t2)
            t2=t1;
        if(t1&&t2)
            t1->val+=t2->val;
        t1->left=mergeTrees(t1->left,t2->left);
        t1->right=mergeTrees(t1->right,t2->right);
        return t1;
    }
};
