https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    int maxPath(TreeNode* root, int &pathSum){
        if(root == NULL) return 0;
        
        int l=maxPath(root->left,pathSum);
        int r=maxPath(root->right,pathSum);
        
        int x=max(max(l,r),0)+root->val;
        pathSum=max(pathSum,max(x,l+r+root->val));
        return x;
    }
    int maxPathSum(TreeNode* root) {
        int pathSum=INT_MIN;
        maxPath(root,pathSum);
        return pathSum;
    }
};
