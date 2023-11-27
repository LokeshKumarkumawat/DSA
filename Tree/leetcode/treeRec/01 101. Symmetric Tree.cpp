https://leetcode.com/problems/symmetric-tree/


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
    
    bool isSymmetric(TreeNode* root) {
        return solve(root,root);
        
        
    }
    bool solve(TreeNode* left,TreeNode* right){
        if(right==NULL || left==NULL){
            return right==left;
        }
        if(left->val!=right->val)return false;
        return solve(left->left,right->right)&& solve(left->right,right->left);
    }
    
    
};    
    