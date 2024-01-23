#include <iostream>
#include <vector>
#include <queue>

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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> res;
        if(root==nullptr){
            return {};
        }
        q.push(root);
        int cur = 1;
        while(!q.empty()){
            std::vector<int> tmp;
            int j = 0;
            for(int i=0;i<cur;i++){
                tmp.push_back(q.front()->val);
                if(q.front()->left){
                    q.push(q.front()->left);
                    j++;
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                    j++;
                }
                q.pop();
            }
            cur = j;
            res.push_back(tmp);
            // res.insert(res.begin(),tmp);
        }
        std::reverse(res.begin(),res.end());
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> tmp;
        checkSum(root, targetSum, 0, res, tmp);
        return res;
    }

    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     bool res = false;
    //     // if(root==NULL){
    //     //     return false;
    //     // }
    //     checkSum(root, targetSum, 0, &res);
    //     return res;

    // }
    void checkSum(TreeNode* root, int targetSum, int curSum, vector<vector<int>> &res, vector<int> &tmp){
        if(root==NULL){
            // if(targetSum == curSum){
            //     *res = true;
            // }
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(curSum+root->val == targetSum){
                tmp.push_back(root->val);
                res.push_back(tmp);
                tmp.pop_back();
            }
            return;
        }
        tmp.push_back(root->val);
        checkSum(root->left, targetSum, curSum + root->val, res, tmp);
        checkSum(root->right, targetSum, curSum + root->val, res, tmp);
        tmp.pop_back();
    }
};
