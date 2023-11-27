https://leetcode.com/problems/path-sum/

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
        return helper(root, targetSum, 0);
    }
    
    bool helper(TreeNode* node, int targetSum, int sum_so_far) {
        
        if(!node) return false;
        
        int val = node->val + sum_so_far;
        
        if (node && !node->left && !node->right && targetSum == val)
            return true;
        
        if (node->left && helper(node->left, targetSum, val)) return true;
        
        return node->right && helper(node->right, targetSum, val);
        
    }
	
};