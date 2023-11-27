https://leetcode.com/problems/recover-binary-search-tree/

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
private:
    TreeNode* first=NULL, *mid=NULL, *last=NULL, *prev=NULL;
public:
    
    
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        if(last != NULL)
            swap(first->val, last->val);
        else
            swap(first->val, mid->val);
        
    }
    
    
    void inorder(TreeNode* root){
            
        if(!root)
            return ;
        inorder(root-> left);
        
        int value;
        if(prev == NULL ){
            value=INT_MIN;
            // cout<<" first->"<<value<<endl;

        }else{
            value=prev->val;
            // cout<<" second->"<<value<<endl;

        }
        
            
        
        if(first == NULL && root->val < value){
            mid=root;
            first=prev;
        }
        else if(root->val < value){
            last=root;
        }
        
        prev=root;
        inorder(root->right);
    }
};
