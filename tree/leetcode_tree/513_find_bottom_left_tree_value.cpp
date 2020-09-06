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
    int findBottomLeftValue(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return {};
        
        queue<TreeNode *>q;
        q.push(root);
                
        while(!q.empty())
        {
            TreeNode *node=q.front();
            q.pop();
            res.push_back(node->val);
            
            if(node->right!=NULL)
                q.push(node->right);
            
            if(node->left!=NULL)
                q.push(node->left);
        }
        return res[res.size()-1];
        }
};



