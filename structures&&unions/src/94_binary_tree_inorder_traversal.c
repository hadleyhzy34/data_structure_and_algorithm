#include <stdlib.h>
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

struct res{
    int val;
    struct res* next;
};

/*struct res* printInorder(TreeNode* node, struct res* head){*/
    /*if(node == NULL){*/
        /*return NULL;*/
    /*}*/
    /*head = printInorder(node->left, head);*/
    /*head->next->val = node->val;*/
    /*head = head->next;*/
    /*head = printInorder(node->right, head);*/
    /*return head;*/
/*}*/
void printInorder(struct TreeNode* node, int* res, int* returnSize){
    if(node == NULL){
        return;
    }
    printInorder(node->left, res, returnSize);
    res[*returnSize] = node->val;
    (*returnSize)++;
    printInorder(node->right, res, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if(root==NULL){
        return NULL;
    }
    int* res = (int*)calloc(100, sizeof(int));
    printInorder(root, res, returnSize);
    return res;
}
