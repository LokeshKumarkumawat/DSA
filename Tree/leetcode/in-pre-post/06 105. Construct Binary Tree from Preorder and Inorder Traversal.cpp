
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/



// inorder preorder traversal
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
    int findPos(vector<int>&in , int element,int n){
        for(int i=0;i<n;i++){
            if(in[i] == element){
                return i;
            }
        }
        return -1;
    }
    // &preIndex => &
    TreeNode* solve(vector<int>& in, vector<int>& pr,int &preIndex,int inStart,int inEnd,int n){
        
        if(preIndex >= n || inStart > inEnd){
            return NULL;
        }
        
        int element = pr[preIndex++];
        TreeNode* root = new TreeNode(element);
        
        int posion = findPos(in,element,n);
        
        root->left = solve(in,pr,preIndex,inStart,posion-1,n);
        root->right = solve(in,pr,preIndex,posion+1,inEnd,n);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preindex = 0;
        
        TreeNode* root = solve(inorder,preorder,preindex,0,n-1,n);
        
        return root;
        
    }
};





// batter soluction






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


    void createMapping(vector<int>&in , map<int,int>&nodetoindex,int n){
        for(int i=0;i<n;i++){
            nodetoindex[in[i]] = i;
        }
    }
    
    TreeNode* solve(vector<int>& in, vector<int>& pr,int &preIndex,int inStart,int inEnd,int n,map<int,int>&nodetoindex){
        
        if(preIndex >= n || inStart > inEnd){
            return NULL;
        }
        
        int element = pr[preIndex++];
        TreeNode* root = new TreeNode(element);
        
        int posion = nodetoindex[element];
        
        root->left = solve(in,pr,preIndex,inStart,posion-1,n,nodetoindex);
        root->right = solve(in,pr,preIndex,posion+1,inEnd,n,nodetoindex);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int preindex = 0;
        
        map<int,int>nodetoindex;
        
        createMapping(inorder,nodetoindex,n);
        TreeNode* root = solve(inorder,preorder,preindex,0,n-1,n,nodetoindex);
        
        return root;
        
    }
};




//inorder postorder




class Solution {
public:


    void createMapping(vector<int>&in , map<int,int>&nodetoindex,int n){
        for(int i=0;i<n;i++){
            nodetoindex[in[i]] = i;
        }
    }
    
    TreeNode* solve(vector<int>& in, vector<int>& post,int &postIndex,int inStart,int inEnd,int n,map<int,int>&nodetoindex){
        
        if(postIndex < 0 || inStart > inEnd){
            return NULL;
        }
        
        int element = post[postIndex--];
        TreeNode* root = new TreeNode(element);
        
        int posion = nodetoindex[element];

        root->right = solve(in,post,postIndex,posion+1,inEnd,n,nodetoindex);
        root->left = solve(in,post,postIndex,inStart,posion-1,n,nodetoindex);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& post, vector<int>& inorder) {
        int n = preorder.size();
        int postindex = n-1;
        
        map<int,int>nodetoindex;
        
        createMapping(inorder,nodetoindex,n);
        TreeNode* root = solve(inorder,post,postindex,0,n-1,n,nodetoindex);
        
        return root;
        
    }
};

