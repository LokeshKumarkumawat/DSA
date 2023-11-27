// https://leetcode.com/problems/invert-binary-tree/submissions/

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
        TreeNode* invertTree(TreeNode* root) {
		// base condition to terminate the recursive operations
        if(!root) return root;
		
		// swapping the left and right subtrees
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
		
		// recursively operating the same on left and right subtree
        invertTree(root->left);
        invertTree(root->right);
		
        return root;
    }
};