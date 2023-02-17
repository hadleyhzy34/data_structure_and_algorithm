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
    int findBottomLeftValue(TreeNode* root) {
        std::queue<TreeNode*> q;
        int res;
        int curSize = 0;

        if(root){
            q.push(root);
            curSize = 1;
            res = root->val;
        }else{
            return {};
        }
        
        int tmpSize;
        while(!q.empty()){
            tmpSize = 0;
            bool l_check = true;
            for(int i = 0; i < curSize; i++){
                if(q.front()->left){
                    q.push(q.front()->left);
                    tmpSize++;
                    // if(i==0){
                    //     res = q.front()->val;
                    // }
                }else{
                    l_check = false;
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                    tmpSize++;
                    // if(i==0&&l_check){
                    //     res = q.front()->val;
                    // }
                }
                if(i==0){
                    res = q.front()->val;
                }
                q.pop();
            }
            // std::cout<<"cur: "<<res<<std::endl;
            curSize = tmpSize;
        }
        return res;
    }
};
