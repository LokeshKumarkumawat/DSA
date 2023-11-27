https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    
    void solve(TreeNode* root, int k,int &ans, priority_queue<int> &maxh ){
        if(root == NULL){
            return;
        }
        
        solve(root->left, k,ans , maxh);
        solve(root->right,k,ans,maxh);
        
        maxh.push(root->val);
            if (maxh.size()>k){
                maxh.pop();
            }
        ans= maxh.top();
    }
    
    
    int kthSmallest(TreeNode* root, int k ){
        priority_queue<int> maxh;
        int ans = 0;
        solve(root,k,ans, maxh);
        return ans;
    }
};