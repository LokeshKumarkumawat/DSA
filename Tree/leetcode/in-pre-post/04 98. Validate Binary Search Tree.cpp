https://leetcode.com/problems/validate-binary-search-tree/



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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* root, TreeNode* &prev) {
        if(root == NULL){
            return true;
        } 

        //left
        if(validate(root->left, prev) == false){
            return false;
        } 

        //node
        if(prev != NULL && prev->val >= root->val){
            return false;
        }
        prev = root;

        //right
        return validate(root->right, prev);
    }
};