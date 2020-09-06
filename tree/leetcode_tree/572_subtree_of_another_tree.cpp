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
    bool checkSubTree(TreeNode* s, TreeNode* t){
        if(!s&&!t)
            return true;
        else if(!s||!t)
            return false;
        cout<<s->val<<" "<<t->val<<endl;
        if(s->val==t->val)
            return checkSubTree(s->left, t->left)&&checkSubTree(s->right, t->right);
        else
            return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        queue<TreeNode*> q;
        q.push(s);
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            if(checkSubTree(node, t))
                return true;
        }
        return false;
    }
};
