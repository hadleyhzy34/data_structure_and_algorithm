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
    int countNodes(TreeNode* root) {
        std::queue<TreeNode*> q;
        int res = 0;
        int curSize = 0;

        if(root){
            q.push(root);
            curSize = 1;
            res++;
        }else{
            return {};
        }
        
        int tmpSize;
        while(!q.empty()){
            tmpSize = 0;
            for(int i = 0; i < curSize; i++){
                if(q.front()->left){
                    q.push(q.front()->left);
                    tmpSize++; 
                    res++;
                }else{
                    return res;
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                    tmpSize++;
                    res++;
                }else{
                    return res;
                }
                q.pop();
            }
            curSize = tmpSize;
        }
        return res;
    }
};
