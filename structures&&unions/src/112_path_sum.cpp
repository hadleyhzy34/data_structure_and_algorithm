#include <iostream>
#include <vector>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = false;
        // if(root==NULL){
        //     return false;
        // }
        checkSum(root, targetSum, 0, &res);
        return res;

    }
    void checkSum(TreeNode* root, int targetSum, int curSum, bool* res){
        if(root==NULL){
            // if(targetSum == curSum){
            //     *res = true;
            // }
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(curSum+root->val == targetSum){
                *res = true;
            }
            return;
        }
        checkSum(root->left, targetSum, curSum + root->val, res);
        checkSum(root->right, targetSum, curSum + root->val, res);
    }
};

//class Solution {
//public:
    //bool isSameTree(TreeNode* p, TreeNode* q) {
        //if(p == NULL && q == NULL){
            //return true;
        //}
        //if(p == NULL || q == NULL){
            //return false;
        //}
        //if(!isSameTree(p->left, q->left)){
            //return false;
        //}
        //if(!isSameTree(p->right, q->right)){
            //return false;
        //}
        //if(p->val == q->val){
            //return true;
        //}else{
            //return false;
        //}
    //}
//};
