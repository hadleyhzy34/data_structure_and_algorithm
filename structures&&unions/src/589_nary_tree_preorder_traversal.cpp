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
    std::vector<int> preorder(Node* root){
        std::vector<int> res;
        pNary(root, res);
        return res;
    }

    void pNary(Node* node, std::vector<int> &res){
        if(node == NULL){
            return;
        }
        res.push_back(node->val);
        for(auto child:node->children){
            pNary(child, res);
        }
    }
};
