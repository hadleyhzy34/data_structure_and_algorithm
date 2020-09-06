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


class Solution337 {
public:
    int rod(TreeNode* root,bool alert){
        if(!root) return 0;
        if(alert){
            return rod(root->left,false)+rod(root->right,false)+root->val;
        }else{
            return max(rod(root->left,true),rod(root->left,false))+max(rod(root->right,true),rod(root->right,false));
        }
    }
    int rob(TreeNode* root) {
        return max(rod(root,true),rod(root,false));
    }
};


class Solution337_2 {
public:
    pair<int,int> rod(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int> left=rod(root->left);
        pair<int,int> right=rod(root->right);
        int choose=left.second+right.second+root->val;
        int not_choose=max(left.first,left.second)+max(right.first,right.second);
        return {choose,not_choose};
    }
    int rob(TreeNode* root) {
        return max(rod(root).first,rod(root).second);
    }
};


