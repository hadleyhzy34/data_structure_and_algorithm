#include <iostream>
#include <vector>

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
    int largestBSTSubtree(TreeNode* root){
        if(!root){
            return 0;
        }
        int length = 1;
        std::vector<int> res = largestBST(root, &length);
        return length;
    }
    
    //return {l_min, r_max, nums, valid}
    std::vector<int> largestBST(TreeNode* node, int* largest){
        if(!node->left&&!node->right){
            return {node->val, node->val, 1, 1};
        }
        
        std::vector<int> tmp = {node->val, node->val, 0, 1};
        tmp[3] = 1;
        if(node->left){
            std::vector<int> l_tree = largestBST(node->left, largest);
            if(node->val>l_tree[1]&&l_tree[3]==1){
                tmp[0] = l_tree[0];
                tmp[2] += l_tree[2];
            }else{
                tmp[3] = 0;
            }
        }

        if(node->right){
            std::vector<int> r_tree = largestBST(node->right, largest);
            if(node->val<r_tree[0]&&r_tree[3]==1){
                tmp[1] = r_tree[1];
                tmp[2] += r_tree[2];
            }else{
                tmp[3] = 0;
            }
        }

        if(tmp[3]){
            tmp[2]++;
        }else{
            tmp[2] = 0;
        }

        if(tmp[2] > *largest){
            // std::cout<<tmp[2]<<" "<<node->val<<" "<<*largest<<" "<<tmp[3]<<std::endl;
            *largest = tmp[2];
        }
        return tmp;
    }
};
