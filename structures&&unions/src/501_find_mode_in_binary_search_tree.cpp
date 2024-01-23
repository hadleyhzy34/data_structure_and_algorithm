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
class Solution1 {
public:
    std::vector<int> findMode(TreeNode* root){
        std::vector<int> res;
        std::vector<int> ret = {0};
        dfs(root, res);
        std::sort(res.begin(),res.end());
        int mode_count = 0;
        int max_count = 0;
        int cur_value;
        for(int i=0;i<res.size();i++){
            if(i==0||(i > 0 && res[i] != res[i-1])){
                mode_count = 1;
                if(mode_count > max_count){
                    ret[0] = res[i];
                    max_count = mode_count;
                }else if(mode_count == max_count){
                    ret.push_back(res[i]);
                }
            }else if(i > 0 && res[i] == res[i-1]){
                mode_count++;
                if(mode_count > max_count){
                    ret = {res[i]};
                    max_count = mode_count;
                }else if(mode_count == max_count){
                    ret.push_back(res[i]);
                }
            }
        }
        return ret;
    }
    
    void dfs(TreeNode* node, std::vector<int>& res){
        if(node == NULL){
            return;
        }
        res.push_back(node->val);
        dfs(node->left, res);
        dfs(node->right, res);
    }
};

class Solution {
public:
    int cur_fre = 0, max_fre = 0, pre = INT_MIN;
    std::vector<int> findMode(TreeNode* root){
        std::vector<int> res;
        dfs(root, res);
        return res;
    }
    
    void dfs(TreeNode* node, std::vector<int>& res){
        if(node == NULL){
            return;
        }
        dfs(node->left, res);
        if(node->val == pre){
            cur_fre++;
        }else{
            cur_fre = 1;
        }
        if(cur_fre > max_fre){
            max_fre = cur_fre;
            res = {node->val};
        }else if(cur_fre == max_fre){
            res.push_back(node->val);
        }
        pre = node->val;
        dfs(node->right, res);
    }
};
