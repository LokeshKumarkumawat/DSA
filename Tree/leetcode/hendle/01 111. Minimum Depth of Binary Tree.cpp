https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        //check root is null;
        if(root == NULL) return 0;
        //check whether node is leaf or not
        if(root->left == NULL && root->right == NULL) return 1;
        //Now check left depth
        int left_depth = root->left != NULL ? minDepth(root->left) : INT_MAX;
        int right_depth = root->right != NULL ? minDepth(root->right) : INT_MAX;
        return 1 + min(left_depth, right_depth);
        
    }
};