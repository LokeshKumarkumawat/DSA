https://leetcode.com/problems/binary-tree-level-order-traversal-ii/




class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
         vector<int>v;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
           
            if(temp == NULL){
                ans.push_back(v);
                v.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                v.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                
                if(temp->right){
                    q.push(temp->right);
                }
                
            }
        }
        
         reverse(ans.begin(),ans.end());
        
        return ans;
                                                    
                                
        
    }
};


        
        
