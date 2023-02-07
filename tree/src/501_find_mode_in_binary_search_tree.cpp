#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    std::vector<int> findMode(TreeNode* root){
        std::unordered_set<int> node_map;
        std::vector<int> res;

    }
    
    void dfsMode(TreeNode* node, std::unordered_set<int> &node_map, std::vector<int> res){
        if(node==NULL){
            return;
        }
        if(node_map.find(node->val)!=node_map.end()){
            node_map.insert(node->val);
        }
        res[node->val]++;

        if(left && node->left == NULL && node->right == NULL){
            (*res) += node->val;
            return;
        }
        sumLeft(node->left, res, true);
        sumLeft(node->right, res, false);
    }

    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> res;
        std::string tmp = "";
        checkPath(root, tmp, res);
        return res;
    }
    void checkPath(TreeNode* node, std::string curString, std::vector<std::string>& res){
        if(node == NULL){
            return;
        }
        // curString += "->";
        curString += std::to_string(node->val);
        if(node->left == NULL && node->right == NULL){
            res.push_back(curString);
        }else{
            curString += "->";
        }
        checkPath(node->left, curString, res);
        checkPath(node->right, curString, res);
    }
};
