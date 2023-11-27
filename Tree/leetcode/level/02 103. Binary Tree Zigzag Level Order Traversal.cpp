https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/




class Solution {
public:
    
    
    void solve(TreeNode* root, vector<vector<int>> &ans){
        if(root == NULL){
            return;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        
        bool ltr = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> v(size);

            for(int i = 0;i<size;i++){
                  TreeNode* frontVal  = q.front();
                  q.pop();
                
                int index = ltr ? i : size - i - 1;
    	        v[index] = frontVal -> val;
                
                if(frontVal->left){
                    q.push(frontVal->left);
                }
                
               if(frontVal->right){
                    q.push(frontVal->right);
                }
            }
            
            ltr = !ltr;
            
            ans.push_back(v);
            
        }
        
        
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        solve(root,ans);
        return ans;
    }
};