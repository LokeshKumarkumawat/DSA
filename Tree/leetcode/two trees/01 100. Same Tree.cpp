https://leetcode.com/problems/same-tree/

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


class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isSameTree(TreeNode *r1, TreeNode *r2)
    {
        // base case
        if(r1 == NULL && r2 == NULL) {
            return true;
        }
        
        if(r1 == NULL && r2 != NULL) {
            return false;
        }
        
        if(r1 != NULL && r2 == NULL) {
            return false;
        }
        
        bool left = isSameTree(r1->left, r2->left);
        bool right = isSameTree(r1->right, r2->right);
        
        bool value = r1->val == r2->val;
        
        
        if(left && right && value) {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
};